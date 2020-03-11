#include "header.h"

char *mx_maj(struct stat stbuf) {
    char *s = NULL;
    int maj = MX_MINOR(stbuf.st_rdev);

    if (maj > 256)
        s = mx_lenn_of_the_null(mx_hex(maj));
    else
        s = mx_itoa(maj);
    return s;
}
