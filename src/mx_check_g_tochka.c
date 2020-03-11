#include "header.h"

static bool first_check(char *flags, char *name) {
    if (mx_reverse_index(flags, 'G') != -1
        && (mx_reverse_index(flags, 'F') != -1
        || mx_reverse_index(flags, 'p') != -1)) {
        if (mx_strcmp(name, "\033[34m.\033[0m/") != 0
            && mx_strcmp(name, "\033[34m..\033[0m/") != 0) {
            return true;
        }
    }
    return false;
}

bool mx_check_g_tochka(char *name, char *flags) {
    if (first_check(flags, name)) {
        return true;
    }
    else if (mx_reverse_index(flags, 'G') != -1) {
        if (mx_strcmp(name, "\033[34m.\033[0m") != 0
        && mx_strcmp(name, "\033[34m..\033[0m") != 0)
            return true;
    }
    else if (mx_reverse_index(flags, 'F') != -1
        || mx_reverse_index(flags, 'p') != -1) {
        if (mx_strcmp(name, "./") != 0 && mx_strcmp(name, "../") != 0)
            return true;
    }
    else
        if (mx_strcmp(name, ".") != 0 && mx_strcmp(name, "..") != 0)
            return true;
    return false;
}
