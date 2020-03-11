#include "header.h"

static char *flag_g(struct stat stbuf, char *name, char *file_info) {
    char *s = NULL;

    if (MX_ISDIR(stbuf.st_mode))
        s = mx_combo_x3("\033[34m", name, "\033[0m");
    else if (file_info[0] == 'l')
        s = mx_combo_x3("\033[35m", name, "\033[0m");
    else if (MX_ISSOCK(stbuf.st_mode))
        s = mx_combo_x3("\033[32m", name, "\033[0m");
    else if (MX_ISFIFO(stbuf.st_mode))
        s = mx_combo_x3("\033[33m", name, "\033[0m");
    else if (MX_ISBLK(stbuf.st_mode))
        s = mx_combo_x3("\033[34;46m", name, "\033[0m");
    else if (MX_ISCHR(stbuf.st_mode))
        s = mx_combo_x3("\033[34;43m", name, "\033[0m");
    else if (MX_ISEXE(stbuf.st_mode))
        s = mx_combo_x3("\033[31m", name, "\033[0m");
    return s;
}

char *mx_flag_g(struct stat stbuf, char *name, char *file_info) {
    char *s = NULL;

    if (file_info[0] == 'd'
        && file_info[8] == 'w'
        && (file_info[9] == 't' || file_info[9] == 'T'))
        s = mx_combo_x3("\033[30;42m", name, "\033[0m");
    else if (file_info[0] == 'd' && file_info[8] == 'w')
        s = mx_combo_x3("\033[30;43m", name, "\033[0m");
    else if (file_info[0] == '-'
        && (file_info[3] == 's'
        || file_info[3] == 'S'))
        s = mx_combo_x3("\033[30;41m", name, "\033[0m");
    else if (file_info[0] == '-'
        && (file_info[6] == 's'
        || file_info[6] == 'S'))
        s = mx_combo_x3("\033[30;46m", name, "\033[0m");
    else
        s = flag_g(stbuf, name, file_info);
    return s;
}
