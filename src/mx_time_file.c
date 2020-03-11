#include "header.h"

static char *time_file(struct stat stbuf, char *flags) {
    char *s = NULL;

    if (flags
        && mx_reverse_index(flags, 'u') > mx_reverse_index(flags, 'c')
        && mx_reverse_index(flags, 'u') > mx_reverse_index(flags, 'U'))
        s = mx_strdup(ctime(&stbuf.st_atime));
    else if (flags
        && mx_reverse_index(flags, 'u') < mx_reverse_index(flags, 'c')
        && mx_reverse_index(flags, 'U') < mx_reverse_index(flags, 'c'))
        s = mx_strdup(ctime(&stbuf.st_ctime));
    else if (flags
        && mx_reverse_index(flags, 'u') < mx_reverse_index(flags, 'U')
        && mx_reverse_index(flags, 'c') < mx_reverse_index(flags, 'U'))
        s = mx_strdup(ctime(&stbuf.st_birthtime));
    else
        s = mx_strdup(ctime(&stbuf.st_mtime));
    return s;
}

char *mx_time_file(struct stat stbuf, char *flags) {
    char *s = time_file(stbuf, flags);
    char *v = NULL;
    time_t last = stbuf.st_mtime;
    time_t now = time(NULL);

    if (mx_reverse_index(flags, 'T') != -1)
        v = mx_full_time(s);
    else if ((now - last) > (31536000 / 2))
        v = mx_bolshe_polovinu(s);
    else
        v = mx_new_mass(s);
    free(s);
    return v;
}
