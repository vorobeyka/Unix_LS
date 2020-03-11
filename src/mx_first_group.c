#include "header.h"

char *mx_first_group(struct stat stbuf) {
    char *s = NULL;

    s = stbuf.st_mode & MX_IRUSR ? mx_super_join(s, "r")
        : mx_super_join(s, "-");
    s = stbuf.st_mode & MX_IWUSR ? mx_super_join(s, "w")
        : mx_super_join(s, "-");
    s = (stbuf.st_mode & MX_ISUID
        ? (stbuf.st_mode & MX_IXUSR ? mx_super_join(s, "s")
            : mx_super_join(s, "S"))
        : (stbuf.st_mode & MX_IXUSR ? mx_super_join(s, "x")
            : mx_super_join(s, "-")));
    return s;
}
