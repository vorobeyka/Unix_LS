#include "header.h"

void mx_start(char **argv, char *flags, int count, int *res) {
    char **v = mx_new_argv(argv, count);
    char *d = NULL;
    int flag = 0;

    mx_konets(v, flags);
    for (int i = 0; v[i]; i++) {
        if (mx_first_check(v[i])) {
            if (!mx_check_stat(v[i], flags))
                d = mx_ne_spi(d, flag, v, i);
            else {
                mx_kostul(d, flags, res);
                d = NULL;
                mx_add_start(v, i, flags, res);
            }
        }
        else
            mx_error(v[i], v, i, res);
    }
    mx_kostul(d, flags, res);
    mx_del_strarr(&v);
}
