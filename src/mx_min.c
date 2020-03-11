#include "header.h"

char *mx_min(struct stat stbuf) {
    char *s = NULL;
    int min = MX_MAJOR(stbuf.st_rdev);

    if (min > 256)
        s = mx_lenn_of_the_null(mx_hex(min));
    else
        s = mx_itoa(min);
    return s;
}
