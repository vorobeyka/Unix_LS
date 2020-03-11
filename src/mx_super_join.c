#include "header.h"

char *mx_super_join(char *src, char *d) {
    char *s = NULL;

    s = mx_strjoin(src, d);
    if (src != NULL)
        free(src);
    src = NULL;
    return s;
}
