#include "header.h"

char *mx_user(struct stat stbuf, char *flags) {
    struct passwd *pas = NULL;
    char *s = NULL;
    unsigned int num = 0;

    num = stbuf.st_uid;
    if ((pas = getpwuid(num)) == NULL)
        exit(1);
    if (mx_reverse_index(flags, 'n') != -1) {
        char *v = mx_itoa(pas->pw_uid);
        
        s = mx_strdup(v);
        free(v);
    }
    else
        s = mx_strdup(pas->pw_name);
    return s;
}
