#include "header.h"

char *mx_second_flag_x(char *flags, t_files *j, char *v) {
    char *s = NULL;

    if (v) {
        s = mx_strdup(v);
        free(v);
    }
    if (mx_reverse_index(flags, 'a') != -1
        || mx_reverse_index(flags, 'f') != -1)
        s = mx_full_str(s, j, flags);
    else if (mx_reverse_index(flags, 'A') != -1
        && (mx_strcmp(j->name, "..") != 0
        && mx_strcmp(j->name, ".") != 0))
        s = mx_full_str(s, j, flags);
    else if (j->name[0] != '.')
        s = mx_full_str(s, j, flags);
    return s;
}
