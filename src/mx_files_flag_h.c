#include "header.h"

static int files_flag_h(t_arg *lst) {
    int count = 0;

    for (t_arg *i = lst; i && i->file_dir == 1; i = i->next)
        if (mx_strlen(i->files->flag_h) > count)
            count = mx_strlen(i->files->flag_h);
    return count;
}

void mx_files_flag_h(t_arg *lst) {
    int max_len = files_flag_h(lst);

    for (t_arg *i = lst; i && i->file_dir == 1; i = i->next)
        if (max_len > mx_strlen(i->files->flag_h))
            for (int j = mx_strlen(i->files->flag_h);
                j < max_len; j++) {
                char *v = i->files->flag_h;
                
                i->files->flag_h = mx_strjoin(" ", i->files->flag_h);
                free(v);
            }
}
