#include "header.h"

static char *time_int(char flag, struct stat stbuf) {
    char *s = NULL;
    time_t last = 0;

    if (flag == 'U')
        last = stbuf.st_birthtime;
    else if (flag == 'u')
        last = stbuf.st_atime;
    else if (flag == 'c')
        last = stbuf.st_ctime;
    else if (flag == 't')
        last = stbuf.st_mtime;
    s = mx_itoa(last);
    return s;
}

char *mx_time_int(struct stat stbuf, char *flags) {
    char *s = NULL;

    if (flags
        && mx_reverse_index(flags, 'u') > mx_reverse_index(flags, 'c')
        && mx_reverse_index(flags, 'u') > mx_reverse_index(flags, 'U'))
        s = time_int('u', stbuf);
    else if (flags
        && mx_reverse_index(flags, 'u') < mx_reverse_index(flags, 'c')
        && mx_reverse_index(flags, 'U') < mx_reverse_index(flags, 'c'))
        s = time_int('c', stbuf);
    else if (flags
        && mx_reverse_index(flags, 'u') < mx_reverse_index(flags, 'U')
        && mx_reverse_index(flags, 'c') < mx_reverse_index(flags, 'U'))
        s = time_int('U', stbuf);
    else
        s = time_int('t', stbuf);
    if (s == NULL)
        exit(1);
    s = mx_super_join(s, " ");
    return s;
}
