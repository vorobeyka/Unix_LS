#include "header.h"

static int files_group(t_arg *lst) {
    int count = 0;

    for (t_arg *i = lst; i && i->file_dir == 1; i = i->next)
        if (mx_strlen(i->files->group) > count)
            count = mx_strlen(i->files->group);
    return count;
}

void mx_files_group(t_arg *lst) {
    int max_len = files_group(lst);

    for (t_arg *i = lst; i && i->file_dir == 1; i = i->next)
        if (max_len > mx_strlen(i->files->group))
            for (int j = mx_strlen(i->files->group);
                j < max_len; j++) {
                char *v = i->files->group;
                
                i->files->group = mx_strjoin(i->files->group, " ");
                free(v);
            }
}
