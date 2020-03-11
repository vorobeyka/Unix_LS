#include "header.h"

static int files_date(t_arg *lst) {
    int count = 0;

    for (t_arg *i = lst; i && i->file_dir == 1; i = i->next)
        if (mx_strlen(i->files->date) > count)
            count = mx_strlen(i->files->date);
    return count;
}

void mx_files_date(t_arg *lst) {
    int max_len = files_date(lst);

    for (t_arg *i = lst; i && i->file_dir == 1; i = i->next)
        if (max_len > mx_strlen(i->files->date))
            for (int j = mx_strlen(i->files->date);
                j < max_len; j++) {
                char *v = i->files->date;

                i->files->date = mx_strjoin(" ", i->files->date);
                free(v);
            }
}
