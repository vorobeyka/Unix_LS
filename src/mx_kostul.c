#include "header.h"

void mx_kostul(char *d, char *flags, int *res) {
    if (d) {
        char **b = mx_strsplit(d, '|');

        mx_uls(b, flags, res);
        mx_del_strarr(&b);
        free(d);
    }
}
