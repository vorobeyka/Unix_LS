#include "header.h"

char *mx_third_group(struct stat stbuf) {
    char *s = NULL;

    s = stbuf.st_mode & MX_IROTH ? mx_super_join(s, "r")
        : mx_super_join(s, "-");
    s = stbuf.st_mode & MX_IWOTH ? mx_super_join(s, "w")
        : mx_super_join(s, "-");
    s = (stbuf.st_mode & MX_ISVTX
        ? (stbuf.st_mode & MX_IXOTH ? mx_super_join(s, "t")
            : mx_super_join(s, "T"))
        : (stbuf.st_mode & MX_IXOTH ? mx_super_join(s, "x")
            : mx_super_join(s, "-")));
    return s;
}
