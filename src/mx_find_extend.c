#include "header.h"

char **mx_find_extend(char *name) {
    char **s = NULL;
    char tmp[512];
    ssize_t xattr = listxattr(name, tmp, 512, XATTR_NOFOLLOW);
    ssize_t gxattr = getxattr(name, tmp, NULL, 0, 0, XATTR_NOFOLLOW);
    
    if ((int)gxattr == -1)
        return NULL;
    for (int i = 0; i < xattr - 1; i++)
        if (tmp[i] == '\0')
            tmp[i] = '\n';
    s = mx_strsplit(tmp, '\n');
    mx_add_num(s, name);
    return s;
}
