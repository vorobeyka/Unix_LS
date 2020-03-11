#include "header.h"

char *mx_link_name(char *name) {
    char *tmp = mx_strnew(525);
    char *v = NULL;

    readlink(name, tmp, 524);
    v = tmp;
    tmp = mx_strjoin(" -> ", tmp);
    free(v);
    return tmp;
}
