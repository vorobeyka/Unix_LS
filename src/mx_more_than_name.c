#include "header.h"

char *mx_more_than_name(char *full, char *name,
                        char *flags, char *file_info) {
    struct stat stbuf;
    char *s = NULL;

    if (lstat(full, &stbuf) == -1) {
        s = mx_strdup(name);
        free(name);
        return s;
    }
    char *flag_G = mx_color_name(stbuf, name, flags, file_info);
    char *flag_F_p = mx_find_f_p(stbuf, flags, file_info);

    s = mx_strjoin(flag_G, flag_F_p);
    if (s == NULL)
        s = mx_strdup(name);
    else if (flag_G == NULL)
        s = mx_strjoin(name, flag_F_p);
    free(name);
    free(flag_G);
    free(flag_F_p);
    return s;
}
