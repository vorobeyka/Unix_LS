#include "header.h"

static char *second_e_add(char *s, int fl, char **z, int j) {
    char **g = mx_strsplit(z[j], ',');

    for (int k = fl; g[k]; k++) {
        if (k == 0) {
            s = mx_super_join(s, g[k]);
            mx_del_strarr(&g);
            return s;
        }
        else {
            s = mx_super_join(s, g[k]);
            if (g[k + 1] != NULL)
                s = mx_super_join(s, ",");
        }
    }
    mx_del_strarr(&g);
    return s;
}

static char *third_more(char *s) {
    s = mx_change(s, "execute", "search");
    s = mx_change(s, "append", "add_subdirectory");
    s = mx_change(s, "write", "add_file");
    s = mx_change(s, "read", "list");
    return s;
}

static char *first_e_add(char *l, char *s) {
    if (l) {
        s = mx_super_join(s, ",");
        s = mx_super_join(s, l);
        free(l);
    }
    s = third_more(s);
    return s;
}

char *mx_first_e(char **z, char *s) {
    char *l = NULL;

    for (int j = 0; z[j]; j++)
        if (j == 0 || j == 2 || j == 4 || j == 5) {
            if (j != 4)
                s = mx_super_join(s, z[j]);
            if (j == 0)
                s = mx_super_join(s, ":");
            else if (j == 4) {
                s = second_e_add(s, 0, z, j);
                l = second_e_add(l, 1, z, j);
            }
            if (z[j + 1] != NULL && j != 0)
                s = mx_super_join(s, " ");
        }
    s = first_e_add(l, s);
    return s;
}
