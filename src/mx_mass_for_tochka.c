#include "header.h"

char **mx_mass_for_tochka(char **argv) {
    char **s = (char **) malloc(sizeof(char *)
               * (mx_count_mass(argv) + 2));

    for (int i = 0; argv[i]; i++)
        s[i] = mx_strdup(argv[i]);
    s[mx_count_mass(argv)] = mx_strdup(".");
    s[mx_count_mass(argv) + 1] = NULL;
    return s;
}
