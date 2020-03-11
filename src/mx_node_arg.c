#include "header.h"

t_arg *mx_node_arg(char *name, char *flags) {
    t_arg *node = (t_arg *)malloc(sizeof(t_arg));
    struct stat stbuf;

    if (lstat(name, &stbuf) == -1)
        exit(1);
    node->name = mx_strdup(name);
    node->file_dir = mx_file_or_dir(stbuf, flags);
    node->time_int = mx_time_int(stbuf, flags);
    node->size = mx_itoa(stbuf.st_size);
    node->argv_info = mx_file_info(stbuf);
    node->total = 0;
    node->next = NULL;
    node->files = NULL;
    return node;
}
