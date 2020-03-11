#include "header.h"

static bool check_smth(char *str, int i) {
    if (str[i] == '\a'
        || str[i] == '\b' 
        || str[i] == '\t'
        || str[i] == '\n'
        || str[i] == '\v'
        || str[i] == '\f'
        || str[i] == '\r') {
        return true;
    }
    return false;
}

char *mx_turn_n(char *str) {
    char *res = mx_strdup(str);

    for (int i = 0; str[i]; i++) {
        if (check_smth(str, i))
            res[i] = '?';
        else
            res[i] = str[i];
    }
    free(str);
    return res;
}
