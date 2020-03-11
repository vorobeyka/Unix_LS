#include "header.h"

static bool more(t_files *i, int size_more) {
    if (mx_strlen(i->size) > size_more)
        return true;
    return false;
}

static int min_more(t_files *lst, char *flags) {
    int size_more = 0;

    for (t_files *i = lst; i; i = i->next) {
        if ((mx_reverse_index(flags, 'a') != -1
            || mx_reverse_index(flags, 'f') != -1)
            && more(i, size_more)) {
            size_more = mx_strlen(i->size);
        }
        else if (mx_reverse_index(flags, 'A') != -1
            && (mx_strcmp(i->name, "..") != 0
            && mx_strcmp(i->name, ".") != 0)
            && more(i, size_more)) {
            size_more = mx_strlen(i->size);
        }
        else if (i->name[0] != '.' && more(i, size_more)) {
            size_more = mx_strlen(i->size);
        }
    }
    return size_more;
}

void mx_add_min_more(t_files *lst, char *flags) {
    int max = min_more(lst, flags);

    for (t_files *i = lst; i; i = i->next)
        if (i->min && i->maj)
            for (int j = max - (mx_strlen(i->min) +
                mx_strlen(i->maj) + 3); j > 0; j--) {
                char *v = i->min;
                
                i->min = mx_strjoin(" ", i->min);
                free(v);
            }
}
