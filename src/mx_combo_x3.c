#include "header.h"

char *mx_combo_x3(char *src1, char *src2, char *src3) {
    char *s = NULL;

    s = mx_super_join(s, src1);
    s = mx_super_join(s, src2);
    s = mx_super_join(s, src3);
    return s;
}
