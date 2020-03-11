#include "header.h"

void mx_konets(char **v, char *flags) {
    mx_name(v, mx_count_mass(v));
    mx_buble(v, mx_count_mass(v), flags);
    mx_files(v, mx_count_mass(v), flags);
}
