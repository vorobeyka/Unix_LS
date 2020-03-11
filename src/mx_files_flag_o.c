#include "header.h"

static int files_flag_o(t_arg *lst) {
    int count = 0;

    for (t_arg *i = lst; i && i->file_dir == 1; i = i->next)
        if (mx_strlen(i->files->flag_o) > count)
            count = mx_strlen(i->files->flag_o);
    return count;
}

void mx_files_flag_o(t_arg *lst) {
    int max_len = files_flag_o(lst);

    for (t_arg *i = lst; i && i->file_dir == 1; i = i->next)
        if (max_len > mx_strlen(i->files->flag_o))
            for (int j = mx_strlen(i->files->flag_o);
                j < max_len; j++) {
                char *v = i->files->flag_o;

                i->files->flag_o = mx_strjoin(i->files->flag_o, " ");
                free(v);
            }
}
