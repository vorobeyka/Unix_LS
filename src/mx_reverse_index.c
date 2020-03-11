#include "header.h"

int mx_reverse_index(char *src, char s) {
    int index = -1;

    if (!src)
        return index;
    for (int i = mx_strlen(src) - 1; i >= 0; i--)
        if (src[i] == s)
            index = i;
    return index;
}
