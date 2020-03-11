#include "header.h"

char *mx_exstra_group(char *name) {
    char *s = NULL;
    ssize_t xattr = listxattr(name, NULL, 0, XATTR_NOFOLLOW);
    acl_t acl = acl_get_file(name, ACL_TYPE_EXTENDED);

    if (xattr > 0) {
        s = mx_super_join(s, "@");
        if (acl) {
            acl_free(acl);
            acl = NULL;
        }
    }
    else if (acl != NULL) {
        s = mx_super_join(s, "+");
        acl_free(acl);
        acl = NULL;
    }
    else
        s = mx_super_join(s, " ");
    s = mx_super_join(s, " ");
    return s;
}
