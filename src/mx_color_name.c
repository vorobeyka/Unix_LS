#include "header.h"

char *mx_color_name(struct stat stbuf, char *name,
    char *flags, char *file_info) {
    char *s = NULL;

    if (isatty(1) && mx_reverse_index(flags, 'G') != -1)
        s = mx_flag_g(stbuf, name, file_info);
    else
        s = mx_strdup(name);
    return s;
}
