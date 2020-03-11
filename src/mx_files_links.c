#include "header.h"

static int files_links(t_arg *lst) {
    int count = 0;

    for (t_arg *i = lst; i && i->file_dir == 1; i = i->next)
        if (mx_strlen(i->files->links) > count)
            count = mx_strlen(i->files->links);
    return count;
}

void mx_files_links(t_arg *lst) {
    int max_len = files_links(lst);

    for (t_arg *i = lst; i && i->file_dir == 1; i = i->next)
        if (max_len > mx_strlen(i->files->links))
            for (int j = mx_strlen(i->files->links);
                j < max_len; j++) {
                char *v = i->files->links;

                i->files->links = mx_strjoin(" ", i->files->links);
                free(v);
            }
}
