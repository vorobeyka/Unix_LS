#include "header.h"

static int after_continue(char *name, char *flags, DIR *dir, struct stat stbuf) {
    if (MX_ISDIR(stbuf.st_mode)) {
        dir = opendir(name);
        if (dir == NULL)
            return 1;
        else {
            closedir(dir);
            return 1;
		}
    }
    else if (MX_ISLNK(stbuf.st_mode)
        && mx_reverse_index(flags, 'l') == -1) {
        dir = opendir(name);
        if (dir != NULL) {
            closedir(dir);
            return 1;
		}
    }
    return 0;
}

int mx_afterr(char *name, char *flags) {
    if (!name)
        return 0;
    DIR *dir = NULL;
    struct stat stbuf;

    if (mx_get_substr_index(name, "/dev/fd/3") == 1
        || mx_strcmp(name, "/dev/fd/3") == 0)
        return 0;
    if (lstat(name, &stbuf) == -1)
        return 0;
    return after_continue(name, flags, dir, stbuf);
}
