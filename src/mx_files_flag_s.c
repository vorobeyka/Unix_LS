#include "header.h"

static int files_flag_s(t_arg *lst) {
    int count = 0;

    for (t_arg *i = lst; i && i->file_dir == 1; i = i->next)
        if (mx_strlen(i->files->flag_s) > count)
            count = mx_strlen(i->files->flag_s);
    return count;
}

void mx_files_flag_s(t_arg *lst) {
    int max_len = files_flag_s(lst);

    for (t_arg *i = lst; i && i->file_dir == 1; i = i->next)
        if (max_len > mx_strlen(i->files->flag_s))
            for (int j = mx_strlen(i->files->flag_s);
                j < max_len; j++) {
                char *v = i->files->flag_s;

                i->files->flag_s = mx_strjoin(" ", i->files->flag_s);
                free(v);
            }
}
