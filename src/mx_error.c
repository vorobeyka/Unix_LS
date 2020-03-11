#include "header.h"

void mx_error(char *name, char **v, int z, int *res) {
    int count = mx_count_mass(v);

    *res = 1;
    if (count > 0)
        mx_chek_input_in(name, 1, z);
    else
        mx_chek_input_in(name, 0, z);
}
