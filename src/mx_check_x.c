#include "header.h"

bool mx_check_x(t_files *lst) {
    for (int i = 0; lst->min[i]; i++) {
        if (lst->min[i] == 'x') {
            return true;
        }
    }
    for (int i = 0; lst->maj[i]; i++) {
        if (lst->maj[i] == 'x') {
            return true;
        }
    }
    return false;
}
