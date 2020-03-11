#include "header.h"

static bool more(t_files *i, int size_more) {
    if (!mx_check_x(i)
        && mx_strlen(i->min) + mx_strlen(i->maj) + 2 > size_more) {
        return true;
    }
    return false;
}

static int size_more(t_files *lst, char *flags) {
    int size = 0;

    for (t_files *i = lst; i; i = i->next) {
        if (i->maj != NULL && i->min != NULL) {
            if ((mx_reverse_index(flags, 'a') != -1
                || mx_reverse_index(flags, 'f') != -1)
                && more(i, size)) {
                size = mx_strlen(i->min) + mx_strlen(i->maj) + 2;
            }
            else if (mx_reverse_index(flags, 'A') != -1
                && (mx_strcmp(i->name, "..") != 0
                && mx_strcmp(i->name, ".") != 0)
                && more(i, size)) {
                size = mx_strlen(i->min) + mx_strlen(i->maj) + 2;
            }
            else if (i->name[0] != '.' && more(i, size))
                size = mx_strlen(i->min) + mx_strlen(i->maj) + 2;
        }
    }
    return size;
}

void mx_add_size_more(t_files *lst, char *flags) {
    int max = size_more(lst, flags);

    for (t_files *i = lst; i; i = i->next)
        for (int j = max - mx_strlen(i->size) + 1; j > 0; j--) {
            char *v = i->size;

            i->size = mx_strjoin(" ", i->size);
            free(v);
        }
}
