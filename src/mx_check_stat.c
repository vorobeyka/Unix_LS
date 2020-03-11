#include "header.h"

bool mx_check_stat(char *name, char *flags) {
    DIR *dir;
    struct stat stbuf;

    lstat(name, &stbuf);
    if (MX_ISDIR(stbuf.st_mode)
        || (MX_ISLNK(stbuf.st_mode)
        && mx_reverse_index(flags, 'l') == -1)) {
        dir = opendir(name);
        if (dir == NULL)
            return false;
        closedir(dir);
    }
    else
        return false;
    return true;
}
