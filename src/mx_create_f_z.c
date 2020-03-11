#include "header.h"

char **mx_create_f_z(char ***s, char *fl) {
    if (mx_count_new_argv(fl, s) == 0)
        return NULL;
    char **s1 = (char **)malloc(sizeof(char *)
                * (mx_count_new_argv(fl, s) + 1));
    int k = 0;

    s1[mx_count_new_argv(fl, s)] = NULL;    
    for (int i = 0; s[0][i]; i++) {
        if (mx_strcmp(fl, s[1][i]) == 0) {
            s1[k] = mx_strdup(s[0][i]);
            k++;
        }
    }
    return s1;
}
