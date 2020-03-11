#include "header.h"

char *mx_flag_fp(int flag, struct stat stbuf, char *file_info) {
    char *s = NULL;

    if (MX_ISDIR(stbuf.st_mode))
        s = mx_strdup("/");
    if ((MX_ISEXE(stbuf.st_mode)) && flag == 0)
        s = mx_strdup("*");
    if ((MX_ISFIFO(stbuf.st_mode)) && flag == 0)
        s = mx_strdup("|");
    if (file_info[0] == 'l' && flag == 0) 
        s = mx_strdup("@");
    if ((MX_ISSOCK(stbuf.st_mode)) && flag == 0)
        s = mx_strdup("=");
    return s;
}
