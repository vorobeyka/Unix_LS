#include "header.h"

static t_files *list_files(struct dirent *entry,
                           DIR *dir, char *name, char *flags) {
    t_files *head = NULL;
    t_files *povit = NULL;
    int flag = 0;

    while ((entry = readdir(dir)) != NULL) {
        t_files *node = mx_node_files(entry->d_name, name, flags);
        
        if (flag == 0) {
            head = node;
            flag = 1;
        }
        else
            povit->next = node;
        povit = node;
    }
    return head;
}

t_files *mx_list_files(char *name, char *flags) {
    DIR *dir;
    struct dirent *entry = NULL;

    dir = opendir(name);
    t_files *head = list_files(entry, dir, name, flags);

    closedir(dir);
    return head;
}
