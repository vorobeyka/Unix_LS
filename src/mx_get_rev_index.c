#include "header.h"

int mx_get_rev_index(char *name, char s) {
    for (int i = mx_strlen(name) - 1; i >= 0; i--)
        if (name[i] == s)
            return i + 1;
    return 0;
}
