#include "header.h"

void mx_add_num(char **s, char *name) {
    for (int i = 0; s[i]; i++) {
        ssize_t gxattr = getxattr(name, s[i], NULL, 0,
                                  0, XATTR_SHOWCOMPRESSION);
        char *v = s[i];

        s[i] = mx_strjoin("\t", s[i]);
        free(v);
        if (gxattr == -1)
            gxattr = 0;
        s[i] = mx_add_space(s[i], (int)gxattr);
    }
}
