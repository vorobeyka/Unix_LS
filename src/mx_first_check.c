#include "header.h"

bool mx_first_check(char *name) {
    if (!name)
        return 0;
    DIR *dir;
    struct stat stbuf;

    if (mx_get_substr_index(name, "/dev/fd/3") == 1
        || mx_strcmp(name, "/dev/fd/3") == 0) {
        return false;
    }
    if (lstat(name, &stbuf) == -1)
        return false;
    if (MX_ISDIR(stbuf.st_mode)) {
        dir = opendir(name);
        if (dir == NULL)
            return false;
        else
            closedir(dir);
    }
    return true;
}
