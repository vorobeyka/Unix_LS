#include "header.h"

char *mx_zero_group(struct stat stbuf) {
    char *s = NULL;

    if (MX_ISBLK(stbuf.st_mode))
        s = mx_super_join(s, "b");
    else if (MX_ISCHR(stbuf.st_mode))
        s = mx_super_join(s, "c");
    else if (MX_ISDIR(stbuf.st_mode))
        s = mx_super_join(s, "d");
    else if (MX_ISFIFO(stbuf.st_mode))
        s = mx_super_join(s, "p");
    else if (MX_ISREG(stbuf.st_mode))
        s = mx_super_join(s, "-");
    else if (MX_ISLNK(stbuf.st_mode))
        s = mx_super_join(s, "l");
    else if (MX_ISSOCK(stbuf.st_mode))
        s = mx_super_join(s, "s");
    return s;
}
