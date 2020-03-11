#include "header.h"

char *mx_flag_i(struct stat stbuf, char *flags) {
    char *s = NULL;
    
    if (mx_reverse_index(flags, 'i') != -1)
        s = mx_itoa(stbuf.st_ino);
    return s;
}
