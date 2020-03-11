#include "header.h"

void mx_add_start(char **v, int i, char *flags, int *res) {
    char **s = mx_cre_argv(v[i]);

    if (mx_count_mass(v) > 1 && mx_afterr(v[i], flags) == 1) {
        if (i != 0)
            mx_slesh_en(v[i], v[i - 1], flags);
        mx_printstr(v[i]);
        mx_printstr(":\n");
    }
    mx_uls(s, flags, res);
    mx_del_strarr(&s);
}
