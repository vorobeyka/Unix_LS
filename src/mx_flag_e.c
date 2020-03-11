#include "header.h"

static char *second_e(char *f, char **z, char *s) {
    s = mx_super_join(s, f);
    for (int j = 0; z[j]; j++)
        if (j == 0 || j == 2 || j == 4 || j == 5) {
            s = mx_super_join(s, z[j]);
            if (j == 0)
                s = mx_super_join(s, ":");
            else if (j != 5)
                s = mx_super_join(s, " ");
        }
    return s;
}

static void first_more(char *f, char **v, char **z, acl_t acl) {
    free(f);
    mx_del_strarr(&v);
    mx_del_strarr(&z);
    acl_free(acl);
}

static char *second_more(char *s, char *d, int i) {
    d = mx_itoa(i - 1);
    s = mx_super_join(s, " ");
    s = mx_super_join(s, d);
    s = mx_super_join(s, ": ");
    free(d);
    return s;
}

static char *flag_e(char *s,char *f, struct stat stbuf, acl_t acl) {
    char **v = NULL;
    char **z = NULL;
    char *d = NULL;

    v = mx_strsplit(f, '\n');
    for (int i = 1; v[i] != NULL; i++) {
        z = mx_strsplit(v[i], ':');
        s = second_more(s, d, i);
        if (MX_ISDIR(stbuf. st_mode))
            s = mx_first_e(z, s);
        else
            s = second_e(f, z, s);
        if (v[i + 1])
            s = mx_super_join(s, "\n");
    }
    first_more(f, v, z, acl);
    return s;
}

char *mx_flag_e(char *name, struct stat stbuf) {
    char *s = NULL;
    char *f = NULL;
    acl_t acl = acl_get_file(name, ACL_TYPE_EXTENDED);
    
    f = acl_to_text(acl, NULL);
    if (f)
        s = flag_e(s, f, stbuf, acl);
    return s;
}
