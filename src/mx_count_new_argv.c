#include "header.h"

int mx_count_new_argv(char *fl, char ***src) {
    int count = 0;
    
    for (int i = 0; src[1][i]; i++)
        if (mx_strcmp(fl, src[1][i]) == 0)
            count++;
    return count;
}
