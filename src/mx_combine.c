#include "header.h"

char *mx_combine(struct stat stbuf, char *name) {
    char *s = NULL;
    char *v = NULL;
    char *z = NULL;

    v = mx_file_info(stbuf);
    z = mx_exstra_group(name);
    s = mx_strjoin(v, z);
    free(v);
    free(z);
    return s;
}
