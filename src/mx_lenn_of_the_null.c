#include "header.h"

char *mx_lenn_of_the_null(char *src) {
    int lenn = mx_strlen(src);
    char *s = NULL;

    s = mx_strjoin(s, "0x");
    for (int i = 0; i < 8 - lenn; i++)
        s = mx_super_join(s, "0");
    s = mx_super_join(s, src);
    free(src);
    return s;
}
