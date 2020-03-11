#include "header.h"

void mx_files_maj(t_arg *lst) {
    int max_len = 3;

    for (t_arg *i = lst; i && i->file_dir == 1; i = i->next)
        if (i->files->maj != NULL)
            if (max_len > mx_strlen(i->files->maj)
                && i->files->maj[1] != 'x')
                for (int j = mx_strlen(i->files->maj);
                    j < max_len; j++) {
                    char *v = i->files->maj;

                    i->files->maj = mx_strjoin(" ", i->files->maj);
                    free(v);
                }
}
