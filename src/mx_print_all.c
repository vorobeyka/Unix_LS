#include "header.h"

static void first_print_all(t_files *i, char *flags, int fl) {
    if (mx_reverse_index(flags, 'O') != -1)
        mx_combo(i->flag_o, " ");
    if (i->file_info[0] == 'b' || i->file_info[0] == 'c') {
        mx_combo(" ", i->min);
        mx_combo(", ", i->maj);
        mx_combo(" ", NULL);
    }
    else if (mx_reverse_index(flags, 'h') != -1 && fl == 0) {
        mx_combo(NULL, " ");
        mx_combo(i->flag_h, " ");
    }
    else
        mx_combo(i->size, " ");
    mx_combo(i->date, " ");
    mx_printstr(i->name);
    if (i->link_name)
        mx_combo(NULL, i->link_name);
    if (i->extended)
        mx_combo("\n", i->extended);
    mx_printchar('\n');
}

void mx_print_all(t_files *i, char *flags, int fl) {
    i->name = mx_more_than_name(i->full_name,
        i->name, flags, i->file_info);
    if (mx_reverse_index(flags, 'i') != -1)
        mx_combo(i->flag_i, " ");
    if (mx_reverse_index(flags, 's') != -1)
        mx_combo(i->flag_s, " ");
    mx_combo(i->file_info, NULL);
    mx_combo(i->links, " ");
    if (mx_reverse_index(flags, 'g') != -1)
        mx_printstr(" ");
    else
        mx_combo(i->user, "  ");
    if (mx_reverse_index(flags, 'o') == -1)
        mx_combo(i->group, "  ");
    first_print_all(i, flags, fl);
}
