#include "header.h"

int mx_max_len_size(t_files *lst, char *flags) {
    int max_size = 0;

    for (t_files *i = lst; i; i = i->next) {
        if (mx_reverse_index(flags, 'a') != -1
            || mx_reverse_index(flags, 'f') != -1) {
            if (mx_strlen(i->size) > max_size)
                max_size = mx_strlen(i->size);
        }
        else if (mx_reverse_index(flags, 'A') != -1
            && (mx_strcmp(i->name, "..") != 0
            && mx_strcmp(i->name, ".") != 0)) {
            if (mx_strlen(i->size) > max_size)
                max_size = mx_strlen(i->size);
        }
        else if (i->name[0] != '.') {
            if (mx_strlen(i->size) > max_size)
                max_size = mx_strlen(i->size);
        }
    }
    return max_size;
}
