#include "header.h"

char *mx_print_extend(char *name) {
    char *s = NULL;
    char **v = mx_find_extend(name);
    
    if (v) {
        for (int i = 0; v[i]; i++) {
            s = mx_super_join(s, v[i]);
            s = mx_super_join(s, " ");
            if (v[i + 1] != NULL)
                s = mx_super_join(s, "\n");
        }
        mx_del_strarr(&v);
    }
    return s;
}
