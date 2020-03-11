#include "header.h"

bool mx_check_min_maj(t_files *lst, char *flags) {
    for (t_files *i = lst; i; i = i->next) {
        if (mx_reverse_index(flags, 'a') != -1
            || mx_reverse_index(flags, 'f') != -1) {
            if (i->maj && i->min)
                return true;
        }
        else if (mx_reverse_index(flags, 'A') != -1
            && (mx_strcmp(i->name, "..") != 0
            && mx_strcmp(i->name, ".") != 0)) {
            if (i->maj && i->min)
                return true;
        }
        else if (i->name[0] != '.') {
            if (i->maj && i->min)
                return true;
        }
    }
    return false;
}
