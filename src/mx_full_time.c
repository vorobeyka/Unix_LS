#include "header.h"

char *mx_full_time(char *s) {
    char *f = mx_strnew(mx_strlen(s) - 1);

    for (int i = 0; i < mx_strlen(s) - 1; i++)
        f[i] = s[i];
    return f;
}
