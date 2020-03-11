#include "header.h"

static bool check_size(t_files *i) {
    if (!mx_check_x(i)
        && mx_strlen(i->min) + mx_strlen(i->maj) + 2
        < mx_strlen(i->size))
        return true;
    return false;
}

bool mx_check_size(t_files *lst, char *flags) {
    for (t_files *i = lst; i; i = i->next) {
        if (i->min && i->maj) {
            if ((mx_reverse_index(flags, 'a') != -1
                || mx_reverse_index(flags, 'f') != -1)
                && check_size(i)) {
                return true;
            }
            else if (mx_reverse_index(flags, 'A') != -1
                    && (mx_strcmp(i->name, "..") != 0
                    && mx_strcmp(i->name, ".") != 0)
                    && check_size(i)) {
                    return true;
            }
            else if (i->name[0] != '.' && check_size(i)) {
                return true;
            }
        }
    }
    return false;
}
