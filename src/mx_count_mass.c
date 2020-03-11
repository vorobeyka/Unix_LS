#include "header.h"

int mx_count_mass(char **argv) {
    int count = 0;

    for (int i = 0; argv[i]; i++)
        count++;
    return count;
}
