#include "header.h"

char *mx_second_group(struct stat stbuf) {
    char *s = NULL;

    s = stbuf.st_mode & MX_IRGRP ? mx_super_join(s, "r")
        : mx_super_join(s, "-");
    s = stbuf.st_mode & MX_IWGRP ? mx_super_join(s, "w")
        : mx_super_join(s, "-");
    s = (stbuf.st_mode & MX_ISGID
        ? (stbuf.st_mode & MX_IXGRP ? mx_super_join(s, "s")
            : mx_super_join(s, "S"))
        : (stbuf.st_mode & MX_IXGRP ? mx_super_join(s, "x")
            : mx_super_join(s, "-")));
    return s;
}
