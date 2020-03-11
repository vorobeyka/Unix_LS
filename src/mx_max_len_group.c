#include "header.h"

int mx_max_len_group(t_files *lst, char *flags) {
    int max_group = 0;
    
    for (t_files *i = lst; i; i = i->next) {
        if (mx_reverse_index(flags, 'a') != -1
            || mx_reverse_index(flags, 'f') != -1) {
            if (mx_strlen(i->group) > max_group)
                max_group = mx_strlen(i->group);
        }
        else if (mx_reverse_index(flags, 'A') != -1
            && (mx_strcmp(i->name, "..") != 0
            && mx_strcmp(i->name, ".") != 0)) {
            if (mx_strlen(i->group) > max_group)
                max_group = mx_strlen(i->group);
        }
        else if (i->name[0] != '.') {
            if (mx_strlen(i->group) > max_group)
                max_group = mx_strlen(i->group);
        }
    }
    return max_group;
}
