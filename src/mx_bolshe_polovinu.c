#include "header.h"

char *mx_bolshe_polovinu(char *s) {
    char *d = mx_strnew(mx_count_lenn_of_time(s, 1));
    int k = 0;

    for (int i = 4; i < mx_strlen(s) - 1; i++)
        if (i < 11 || i > 18) {
            d[k] = s[i];
            k++;
        }
    return d;
}
