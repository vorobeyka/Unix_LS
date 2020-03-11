#include "header.h"

static void max_len_min(char *flags, t_files *i, int *max_min) {
    if (mx_reverse_index(flags, 'a') != -1
        || mx_reverse_index(flags, 'f') != -1) {
        if (mx_strlen(i->min) > *max_min && i->min[1] != 'x' && i->min)
            *max_min = mx_strlen(i->min);
    }
    else if (mx_reverse_index(flags, 'A') != -1
        && (mx_strcmp(i->name, "..") != 0
        && mx_strcmp(i->name, ".") != 0)) {
        if (mx_strlen(i->min) > *max_min && i->min[1] != 'x' && i->min)
            *max_min = mx_strlen(i->min);
    }
    else if (i->name[0] != '.') {
        if (mx_strlen(i->min) > *max_min && i->min[1] != 'x' && i->min)
            *max_min = mx_strlen(i->min);
    }
}

int mx_max_len_min(t_files *lst, char *flags) {
    int max_min = 0;

    for (t_files *i = lst; i; i = i->next)
        if (i->min != NULL)
            max_len_min(flags, i, &max_min);
    return max_min;
}
