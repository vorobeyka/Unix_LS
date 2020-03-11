#include "header.h"

int mx_max_len_flag_o(t_files *lst, char *flags) {
    int max_flag_o = 0;

    for (t_files *i = lst; i; i = i->next) {
        if (mx_reverse_index(flags, 'a') != -1
            || mx_reverse_index(flags, 'f') != -1) {
            if (mx_strlen(i->flag_o) > max_flag_o)
                max_flag_o = mx_strlen(i->flag_o);
        }
        else if (mx_reverse_index(flags, 'A') != -1
            && (mx_strcmp(i->name, "..") != 0
            && mx_strcmp(i->name, ".") != 0)) {
            if (mx_strlen(i->flag_o) > max_flag_o)
                max_flag_o = mx_strlen(i->flag_o);
        }
        else if (i->name[0] != '.') {
            if (mx_strlen(i->flag_o) > max_flag_o)
                max_flag_o = mx_strlen(i->flag_o);
        }
    }
    return max_flag_o;
}
