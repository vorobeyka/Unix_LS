#include "header.h"

static void total(t_arg *i, char *flags, int *z) {
    for (t_files *j = i->files; j; j = j->next) {
        struct stat stbuf;

        if (lstat(j->full_name, &stbuf) == -1)
            *z += 0;
        else {
            if (mx_reverse_index(flags, 'a') != -1
                || mx_reverse_index(flags, 'f') != -1)
                *z += stbuf.st_blocks;
            else if (mx_reverse_index(flags, 'A') != -1
                && mx_strcmp(j->name, ".") != 0
                && mx_strcmp(j->name, "..") != 0)
                *z += stbuf.st_blocks;
            else if (j->name[0] != '.')
                *z += stbuf.st_blocks;
        }
    }
}

void mx_total(t_arg *lst, char *flags) {
    int z;
    
    for (t_arg *i = lst; i; i = i->next) {
        z = 0;
        total(i, flags, &z);
        i->total = z;
    }
}
