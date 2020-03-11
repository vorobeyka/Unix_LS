#include "header.h"

char **mx_cre_argv(char *name) {
    char **s = (char **)malloc(sizeof(char *) * 3);

    s[0] = mx_strdup("./uls");
    s[1] = mx_strdup(name);
    s[2] = NULL;
    return s;
}
