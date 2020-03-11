#include "header.h"

void mx_add_one(char *flags, t_files *i) {
    if (mx_reverse_index(flags, 'i') != -1)
        mx_printstr(i->flag_i);
    if (mx_reverse_index(flags, 's') != -1) {
        if (mx_reverse_index(flags, 'i') != -1)
            mx_printstr(" ");
        mx_printstr(i->flag_s);
    }
    if (mx_reverse_index(flags, 's') != -1
        || mx_reverse_index(flags, 'i') != -1)
        mx_printstr(" ");
    mx_printstr(i->name);
    mx_printchar('\n');
}
