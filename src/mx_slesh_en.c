#include "header.h"

void mx_slesh_en(char *name, char *pre_name, char *flags) {
    DIR *dir;
    struct stat stbuf;

    if (mx_get_substr_index(name, "/dev/fd/3") == 1
        || mx_strcmp(name, "/dev/fd/3") == 0)
        return;
    if (lstat(name, &stbuf) == -1)
        return;
    if (MX_ISDIR(stbuf.st_mode)
        || (MX_ISLNK(stbuf.st_mode)
        && mx_reverse_index(flags, 'l') == -1)) {
        dir = opendir(name);
        if (dir != NULL)
            closedir(dir);
        if ((mx_afterr(pre_name, flags) == 1 && pre_name)
            || mx_first_check(pre_name))
            mx_printchar('\n');
        return;
    }
    return;
}
