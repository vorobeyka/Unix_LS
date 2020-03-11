#include "header.h"

char *mx_find_f_p(struct stat stbuf, char *flags, char *file_info) {
    char *s = NULL;

    if (mx_reverse_index(flags, 'F') > mx_reverse_index(flags, 'p'))
        s = mx_flag_fp(0, stbuf, file_info);
    else if (mx_reverse_index(flags, 'F')
        < mx_reverse_index(flags, 'p'))
        s = mx_flag_fp(1, stbuf, file_info);
    return s;
}
