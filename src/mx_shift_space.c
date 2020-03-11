#include "header.h"

char *mx_shift_space(char *src) {
    char *s = mx_strnew(mx_strlen(src) - 1);
    
    for (int i = 0; i < mx_strlen(src) - 1; i++)
        s[i] = src[i + 1];
    free(src);
    return s;
}
