#include "header.h"

static int files_flag_i(t_arg *lst) {
    int count = 0;

    for (t_arg *i = lst; i && i->file_dir == 1; i = i->next)
        if (mx_strlen(i->files->flag_i) > count)
            count = mx_strlen(i->files->flag_i);
    return count;
}

void mx_files_flag_i(t_arg *lst) {
    int max_len = files_flag_i(lst);

    for (t_arg *i = lst; i && i->file_dir == 1; i = i->next)
        if (max_len > mx_strlen(i->files->flag_i))
            for (int j = mx_strlen(i->files->flag_i);
                j < max_len; j++) {
                char *v = i->files->flag_i;

                i->files->flag_i = mx_strjoin(" ", i->files->flag_i);
                free(v);
            }
}
