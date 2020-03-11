#include "header.h"

static int files_size(t_arg *lst) {
    int count = 0;

    for (t_arg *i = lst; i && i->file_dir == 1; i = i->next)
        if (mx_strlen(i->files->size) > count)
            count = mx_strlen(i->files->size);
    return count;
}

void mx_files_size(t_arg *lst) {
    int max_len = files_size(lst);

    for (t_arg *i = lst; i && i->file_dir == 1; i = i->next)
        if (max_len > mx_strlen(i->files->size))
            for (int j = mx_strlen(i->files->size);
                j < max_len; j++) {
                char *v = i->files->size;

                i->files->size = mx_strjoin(" ", i->files->size);
                free(v);
            }
}
