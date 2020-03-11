#include "header.h"

void mx_cx_max_size(int *max_size, char **v) {
    int max = 0;

    for (int i = 0; v[i]; i++) {
        max = mx_strlen(v[i]);
        *max_size = max > *max_size ? max : *max_size;
        max = 0;
    }
}
