#include "header.h"

int mx_max_len_date(t_files *lst, char *flags) {
    int max_date = 0;

    for (t_files *i = lst; i; i = i->next) {
        if (mx_reverse_index(flags, 'a') != -1
            || mx_reverse_index(flags, 'f') != -1) {
            if (mx_strlen(i->date) > max_date)
                max_date = mx_strlen(i->date);
        }
        else if (mx_reverse_index(flags, 'A') != -1
            && (mx_strcmp(i->name, "..") != 0
            && mx_strcmp(i->name, ".") != 0)) {
            if (mx_strlen(i->date) > max_date)
                max_date = mx_strlen(i->date);
        }
        else if (i->name[0] != '.') {
            if (mx_strlen(i->date) > max_date)
                max_date = mx_strlen(i->date);
        }
    }
    return max_date;
}
