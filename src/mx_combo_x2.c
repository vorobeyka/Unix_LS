#include "header.h"

char *mx_combo_x2(int z, char *src1) {
    char *s = NULL;
    char *v = mx_itoa(z);

    s = mx_strjoin(v, src1);
    free(v);
    return s;
}
