#include "header.h"

char **mx_new_argv(char **argv, int size) {
    int flag = 0;
    char **s = (char **)malloc(sizeof(char *) * (size + 1));
    int k = 0;

    s[size] = NULL;
    for (int i = 1; argv[i]; i++) {
        if ((argv[i][0] != '-' && flag == 0) || flag == 1) {
            s[k] = mx_strdup(argv[i]);
            k++;
        }
        if (argv[i][0] != '-')
            flag = 1;
    }
    return s;
}
