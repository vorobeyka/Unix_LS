#include "header.h"

char *mx_combo_x4(int s1, int s2, char *src1, char *src2) {
    char *s = NULL;
    char *v = mx_itoa(s1);
    char *z = mx_itoa(s2);

    s = mx_super_join(s, v);
    s = mx_super_join(s, src1);
    s = mx_super_join(s, z);
    s = mx_super_join(s, src2);
    free(v);
    free(z);
    return s;
}
