#include "header.h"

char *mx_new_mass(char *s) {
    char *d = mx_strnew(mx_count_lenn_of_time(s, 0));
    int k = 0;

    for (int i = 4; i < mx_strlen(s) - 1; i++)
        if (i < 16) {
            d[k] = s[i];
            k++;
        }
    return d;
}
