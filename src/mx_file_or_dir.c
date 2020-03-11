#include "header.h"

int mx_file_or_dir(struct stat stbuf, char *flags) {
    int i = 1;

    if (MX_ISDIR(stbuf.st_mode)
        || (MX_ISLNK(stbuf.st_mode)
        && mx_reverse_index(flags, 'l') == -1))
        i = 0;
    return i;
}
