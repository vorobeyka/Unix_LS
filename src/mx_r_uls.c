#include "header.h"

void mx_r_uls(t_files *j, char *flags, int *res) {
    char **s = (char **)malloc(sizeof(char *) * 3);

    s[0] = mx_strdup("./uls");
    s[1] = mx_strdup(j->full_name);
    s[2] = NULL;
    mx_combo(j->full_name, ":\n");
    mx_uls(s, flags, res);
    mx_del_strarr(&s);
}
