#include "header.h"

void mx_flag_one(t_files *lst, char *flags, int total) {
    if (mx_reverse_index(flags, 's') != -1) {
        char *v = mx_itoa(total);

        mx_combo("total: ", v);
        mx_printchar('\n');
        free(v);
    }
    for (t_files *i = lst; i; i = i->next) {
        if (mx_reverse_index(flags, 'a') != -1
            || mx_reverse_index(flags, 'f') != -1)
            mx_add_one(flags, i);
        else if (mx_reverse_index(flags, 'A') != -1
            && (mx_strcmp(i->name, "..") != 0
            && mx_strcmp(i->name, ".") != 0))
            mx_add_one(flags, i);
        else if (i->name[0] != '.')
            mx_add_one(flags, i);
    }
}
