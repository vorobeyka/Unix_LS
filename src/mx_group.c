#include "header.h"

char *mx_group(struct stat stbuf) {
    struct group *gr = NULL;
    char *s = NULL;
    
    if ((gr = getgrgid(stbuf.st_gid)) != NULL)
        s = mx_strdup(gr->gr_name);
    else
        s = mx_itoa(stbuf.st_gid);
    return s;
}
