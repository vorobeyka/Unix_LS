#include "header.h"

bool mx_check_argv_tochka(int argc, char **argv) {
    if (argc == 1)
        return true;
    int count = 0;
    int flag = 0;

    for (int i = 1; argv[i]; i++) {
        if (argv[i][0] != '-' && flag == 0)
            count++;
        else if (flag == 1)
            count++;
        if (mx_strcmp(argv[i], "--") == 0)
            flag = 1;
    }
    if (count == 0)
        return true;
    return false;
}
