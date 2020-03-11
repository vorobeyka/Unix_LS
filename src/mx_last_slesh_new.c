#include "header.h"

void mx_last_slesh_new(char *name) {
    int i = mx_get_rev_index(name, '/');

    if (i == -1)
        i = 0;
    for ( ; name[i]; i++)
        write(2, &name[i], 1);
}
