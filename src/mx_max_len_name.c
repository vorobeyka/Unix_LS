#include "header.h"

int mx_max_len_name(t_files *lst, char *flags) {
    int max_name = 0;

    for (t_files *i = lst; i; i = i->next) {
        if (mx_reverse_index(flags, 'a') != -1
            || mx_reverse_index(flags, 'f') != -1) {
            if (mx_strlen(i->name) > max_name)
                max_name = mx_strlen(i->name);
        }
        else if (mx_reverse_index(flags, 'A') != -1
            && (mx_strcmp(i->name, "..") != 0
            && mx_strcmp(i->name, ".") != 0)) {
            if (mx_strlen(i->name) > max_name)
                max_name = mx_strlen(i->name);
        }
        else if (i->name[0] != '.') {
            if (mx_strlen(i->name) > max_name)
                max_name = mx_strlen(i->name);
        }
    }
    return max_name;
}
