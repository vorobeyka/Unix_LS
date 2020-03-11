#include "header.h"

bool mx_naruto(char *s, char *flags) {
    if (((s[mx_strlen(s) - 1] == '*'
        || s[mx_strlen(s) - 1] == '|'
        || s[mx_strlen(s) - 1] == '@'
        || s[mx_strlen(s) - 1] == '/'
        || s[mx_strlen(s) - 1] == '=')
        && mx_reverse_index(flags, 'F') != -1)
        || (s[mx_strlen(s) - 1] == '/'
        && mx_reverse_index(flags, 'p') != -1)) {
        return true;
    }
    return false;
}
