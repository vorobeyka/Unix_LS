#include "header.h"

char *mx_add_space(char *c, int num) {
    char *s = mx_strdup(c);
    char *v = mx_itoa(num);

    for (int i = 0; ; i++) {
        int j = (mx_strlen(s) + mx_strlen(v)) % 4;
        int x = ((mx_strlen(s) + mx_strlen(v)) / 4) % 2;

        if (j == 0 && x == 1 && i != 0)
            break;
        s = mx_super_join(s, " ");
    }
    s = mx_super_join(s, " ");
    s = mx_super_join(s, v);
    free(v);
    free(c);
    return s;
}
