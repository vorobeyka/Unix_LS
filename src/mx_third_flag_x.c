#include "header.h"

static char *flag_x(t_files **i, char *flags, char *z) {
    t_files *j = *i;

    j->name = mx_more_than_name(j->full_name,
                                j->name, flags, j->file_info);
    z = mx_add_cx(flags, j, z);
    return z;
}

char *mx_third_flag_x(char *flags, t_files *j, char *v) {
    char *z = NULL;

    if (v) {
        z = mx_strdup(v);
        free(v);
    }
    if (mx_reverse_index(flags, 'a') != -1
        || mx_reverse_index(flags, 'f') != -1)
        z = flag_x(&j, flags, z);
    else if (mx_reverse_index(flags, 'A') != -1
        && (mx_strcmp(j->name, "..") != 0
        && mx_strcmp(j->name, ".") != 0))
        z = flag_x(&j, flags, z);
    else if (j->name[0] != '.')
        z = flag_x(&j, flags, z);
    return z;
}
