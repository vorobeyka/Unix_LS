#include "header.h"

static bool check_andryha(char *name, char *flags) {
    DIR *dir;
    struct stat stbuf;

    lstat(name, &stbuf);
    if (MX_ISDIR(stbuf.st_mode)
        || (MX_ISLNK(stbuf.st_mode)
        && mx_reverse_index(flags, 'l') == -1)) {
        dir = opendir(name);
        if (dir != NULL) {
            closedir(dir);
            return true;
        }
    }
    return false;
}

bool mx_check_rec(t_files *j, char *flags, int fl) {
    if (fl == 1) {
        if (check_andryha(j->full_name, flags)
            && mx_strcmp(j->name, ".") != 0
            && mx_get_substr_index(j->full_name, "/Volumes/Mac") == -1
            && mx_strcmp(j->name, "..") != 0
            && (mx_reverse_index(flags, 'a') != -1
            || mx_reverse_index(flags, 'f') != -1
            || mx_reverse_index(flags, 'A') != -1)) {
            return true;
        }
    }
    else if (fl == 0) {
        if (check_andryha(j->full_name, flags)
            && j->name[0] != '.'
            && mx_strcmp(j->name, "..") != 0
            && mx_get_substr_index(j->full_name, "/Volumes/Mac") == -1)
            return true;
    }
    return false;
}
