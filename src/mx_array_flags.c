#include "header.h"

char *mx_array_flags(char **argv) {
    char *flags = NULL;

    for (int i = 0; argv[i]; i++)
        if (argv[i][0] == '-')
            flags = mx_super_join(flags, argv[i]);
    return flags;
}
