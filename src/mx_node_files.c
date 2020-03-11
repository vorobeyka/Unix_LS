#include "header.h"

static void third_node(t_files **n, struct stat stbuf) {
    t_files *node = *n;

    if (node->file_info[0] == 'c' || node->file_info[0] == 'b') {
        node->min = mx_min(stbuf);
        node->maj = mx_maj(stbuf);
    }
    else {
        node->min = NULL;
        node->maj = NULL;
    }
    if (node->file_info[0] == 'l')
        node->link_name = mx_link_name(node->full_name);
    else
        node->link_name = NULL;
}

static void second_node(t_files **n, struct stat stbuf, char *flags) {
    t_files *node = *n;

    node->file_info = mx_combine(stbuf, node->full_name);
    node->links = mx_itoa(stbuf.st_nlink);
    node->user = mx_user(stbuf, flags);
    node->group = mx_group(stbuf);
    node->size = mx_itoa(stbuf.st_size);
    node->date = mx_time_file(stbuf, flags);
    node->time_int = mx_time_int(stbuf, flags);
    node->flag_i = mx_flag_i(stbuf, flags);
    node->flag_s = mx_flag_s(stbuf, flags);
    node->extended = mx_extra_line(node->full_name, stbuf, flags);
    node->file_dir = mx_file_or_dir(stbuf, flags);
    node->flag_o = mx_flag_o(stbuf.st_flags, flags);
    node->flag_h = mx_flag_h(stbuf);
    node->next = NULL;
}

static bool unprint_ch(char *str) {
    for (int i = 0; str[i]; i++) {
        if (str[i] == '\a'
            || str[i] == '\b' 
            || str[i] == '\t'
            || str[i] == '\n'
            || str[i] == '\v'
            || str[i] == '\f'
            || str[i] == '\r')
            return true;
                        
    }
    return false;
}

static void first_node(t_files *node, char *name, char *dir_name) {
    if (mx_strcmp(name, dir_name) != 0) {
        node->name = mx_strdup(name);
        if (mx_strcmp(dir_name, "/") != 0) {
            node->full_name = mx_strjoin(dir_name, "/");
            node->full_name = mx_super_join(node->full_name, name);
        }
        else
            node->full_name = mx_strjoin(dir_name, name);
    }
    else {
        node->name = mx_strdup(name);
        node->full_name = mx_strdup(name);
    }
    if (unprint_ch(node->name))
        node->name = mx_turn_n(node->name);
}

t_files *mx_node_files(char *name, char *dir_name, char *flags) {
    t_files *node = (t_files *)malloc(sizeof(t_files));
    struct stat stbuf;

    first_node(node, name, dir_name);
    if (lstat(node->full_name, &stbuf) == -1)
        exit(1);
    second_node(&node, stbuf, flags);
    third_node(&node, stbuf);
    return node;
}
