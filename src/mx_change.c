#include "header.h"

char *mx_change(char *s, char *d, char *v) {
    char *z = NULL;
    
    z = s;
    s = mx_replace_substr(s, d, v);
    free(z);
    z = NULL;
    return s;
}
