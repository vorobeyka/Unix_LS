#include "header.h"

char *mx_ne_spi(char *d, int flag, char **v, int i) {
    if (flag == 0) {
        d = mx_super_join(d, "./uls");
        d = mx_super_join(d, "|");
        flag = 1;
    }
    d = mx_super_join(d, v[i]);
    d = mx_super_join(d, "|");
    return d;
}
