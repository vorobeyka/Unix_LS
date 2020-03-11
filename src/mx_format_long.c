#include "header.h"

void mx_format_long(t_files *lst, char *flags, int fl) {
    mx_all(lst, flags);
    for (t_files *i = lst; i; i = i->next) {
        if (mx_reverse_index(flags, 'a') != -1
            || mx_reverse_index(flags, 'f') != -1)
            mx_print_all(i, flags, fl);
        else if (mx_reverse_index(flags, 'A') != -1
            && (mx_strcmp(i->name, "..") != 0
            && mx_strcmp(i->name, ".") != 0))
            mx_print_all(i, flags, fl);
        else if (i->name[0] != '.')
            mx_print_all(i, flags, fl);
    }
}
