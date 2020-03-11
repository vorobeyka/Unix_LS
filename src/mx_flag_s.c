#include "header.h"

char *mx_flag_s(struct stat stbuf, char *flags) {
    char *f = NULL;
    
    if (mx_reverse_index(flags, 's') != -1)
        f = mx_get_s(stbuf, flags);
    return f;
}
