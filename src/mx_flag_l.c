#include "header.h"

static int count_file_total(t_files *lst, int fl) {
    int count = 0;

    for (t_files *i = lst; i; i = i->next) {
        if (fl == 1 && i->name[0] != '.')
            count++;
        else if (fl == 0
            && mx_strcmp(i->name, ".") != 0
            && mx_strcmp(i->name, "..") != 0)
            count++;
    }
    return count;
}

static void print_total(t_arg *i) {
    if (i->file_dir == 0) {
        mx_printstr("total ");
        mx_printint(i->total);
        mx_printchar('\n');
    }
}

void mx_flag_l(t_arg *i, char *flags, int fl) {
    if (mx_reverse_index(flags, 'a') != -1
        || mx_reverse_index(flags, 'f') != -1)
        print_total(i);
    else if (mx_reverse_index(flags, 'A') != -1
        && count_file_total(i->files, 0) > 0)
        print_total(i);
    else if (count_file_total(i->files, 1) > 0)
        print_total(i);
    mx_format_long(i->files, flags, fl);
    if (i->next && i->next->file_dir == 0)
        mx_printchar('\n');
}
