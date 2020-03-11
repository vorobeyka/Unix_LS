#include "header.h"

int mx_find_true_flag(char *f) {
    if (!f) {
        return -1;
    }
    int flag = -1;
    
    for (int i = 0; f[i]; i++) {
        if (f[i] == 'g'
            || f[i] == 'o'
            || f[i] == 'l'
            || f[i] == 'n'
            || f[i] == 'm'
            || f[i] == '1'
            || f[i] == 'x'
            || f[i] == 'C') {
            flag = i;
        }
    }
    return flag;
}
