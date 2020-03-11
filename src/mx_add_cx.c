#include "header.h"

char *mx_add_cx(char *flags, t_files *i, char *c) {
    char *s = NULL;

    if (c != NULL)
        s = mx_strdup(c);
    if (mx_reverse_index(flags, 'i') != -1)
        s = mx_super_join(s, i->flag_i);
    if (mx_reverse_index(flags, 's') != -1) {
        if (mx_reverse_index(flags, 'i') != -1)
            s = mx_super_join(s, " ");
        s = mx_super_join(s, i->flag_s);
    }
    if (mx_reverse_index(flags, 'i') != -1
        || mx_reverse_index(flags, 's') != -1)
        s = mx_super_join(s, " ");
    s = mx_super_join(s, i->name);
    if (i->next)
        s = mx_super_join(s, "|");
    if (c != NULL)
        free(c);
    return s;
}
