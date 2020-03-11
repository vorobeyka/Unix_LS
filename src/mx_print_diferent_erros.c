#include "header.h"

void mx_print_diferent_erros(char *name, int flag, int z) {
    DIR *dir;
    struct stat stbuf;

    if (lstat(name, &stbuf) == -1) {
        mx_permition(name, 1, flag, z);
        return ;
    }
    if (MX_ISDIR(stbuf.st_mode)) {
        dir = opendir(name);
        if (dir == NULL) {
            mx_permition(name, 0, flag, z);
            return ;
        }
        else
            closedir(dir);
    }
}
