#include "header.h"

static int files_user(t_arg *lst) {
    int count = 0;

    for (t_arg *i = lst; i && i->file_dir == 1; i = i->next)
        if (mx_strlen(i->files->user) > count)
            count = mx_strlen(i->files->user);
    return count;
}

void mx_files_user(t_arg *lst) {
    int max_len = files_user(lst);

    for (t_arg *i = lst; i && i->file_dir == 1; i = i->next)
        if (max_len > mx_strlen(i->files->user))
            for (int j = mx_strlen(i->files->user);
                j < max_len; j++) {
                char *v = i->files->user;

                i->files->user = mx_strjoin(i->files->user, " ");
                free(v);
            }
}
