#include "header.h"

char *mx_extra_line(char *name, struct stat stbuf, char *flags) {
    char *s = NULL;
    char *v = NULL;
    char *z = NULL;
    
    if (mx_reverse_index(flags, '@') != -1)
        v = mx_print_extend(name);
    if (mx_reverse_index(flags, 'e') != -1)
        z = mx_flag_e(name, stbuf);
    if (v && z)
        v = mx_super_join(v, "\n");
    s = mx_strjoin(v, z);
    free(v);
    free(z);
    return s;
}
