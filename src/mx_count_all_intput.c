#include "header.h"

int mx_count_all_intput(char **argv) {
    int count = 0;
    int flag = 0;

    for (int i = 1; argv[i]; i++) {
        if (argv[i][0] != '-' && flag == 0)
            count++;
        else if (flag == 1)
            count++;
        if (argv[i][0] != '-')
            flag = 1;
    }
    return count;
}
