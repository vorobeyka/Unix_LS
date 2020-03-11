#include "header.h"

static bool checkon(char *name, char *flags) {
    struct stat stbuf;
    DIR *dir;

    lstat(name, &stbuf);
    if (MX_ISLNK(stbuf.st_mode)
        && mx_reverse_index(flags, 'l') == -1) {
        dir = opendir(name);
        if (dir != NULL) {
            closedir(dir);
            return true;
        }
    }
    else if (MX_ISDIR(stbuf.st_mode))
        return true;
    return false;
}

void mx_add_dir_list(t_arg *lst, char *flags) {
    for (t_arg * i = lst; i; i = i->next) {
        if (i->file_dir == 0 && checkon(i->name, flags))
            i->files = mx_list_files(i->name, flags);
        else
            i->files = mx_node_files(i->name, i->name, flags);
    }   
}
