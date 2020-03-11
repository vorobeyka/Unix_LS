#include "header.h"

char *mx_get_s(struct stat stbuf, char *flags) {
    char *tmp = NULL;
    char *p = NULL;
    int len = 0;

    tmp = mx_itoa(stbuf.st_blocks);
    if (mx_get_char_index(flags, 'k') != -1) {
        len = mx_strlen(tmp);
        free(tmp);
        tmp = mx_to_upper_numb(stbuf.st_blocks);
        while (mx_strlen(tmp) < len) {
            p = tmp;
            tmp = mx_strjoin(" ", p);
            free(p);
            p = NULL;
        }
    }
    return tmp;
}
