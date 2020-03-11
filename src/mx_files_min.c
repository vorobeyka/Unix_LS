#include "header.h"

static int files_min(t_arg *lst) {
    int count = 0;

    for (t_arg *i = lst; i && i->file_dir == 1; i = i->next)
        if (i->files->min != NULL)
            if (mx_strlen(i->files->min) > count
                && i->files->min[1] != 'x')
                count = mx_strlen(i->files->min);
    return count;
}

void mx_files_min(t_arg *lst) {
    int max_len = files_min(lst);

    for (t_arg *i = lst; i && i->file_dir == 1; i = i->next)
        if (i->files->min != NULL)
            if (max_len > mx_strlen(i->files->min)
                && i->files->min[1] != 'x')
                for (int j = mx_strlen(i->files->min);
                    j < max_len; j++) {
                    char *v = i->files->min;

                    i->files->min = mx_strjoin(" ", i->files->min);
                    free(v);
                }
}
