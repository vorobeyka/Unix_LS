#include "header.h"

static void sort_arg(t_arg *lst, char *flags) {
    for (t_arg *i = lst; i; i = i->next) {
        if (i->files) {
            if (mx_reverse_index(flags, 'r') != -1) {
                mx_sort_filse_name(i->files, 1);
                if (mx_reverse_index(flags, 'S') != -1)
                    mx_sort_filse_size(i->files, 1);
                else if (mx_reverse_index(flags, 't') != -1)
                    mx_sort_filse_time(i->files, 1);
            }
            else {
                mx_sort_filse_name(i->files, 0);
                if (mx_reverse_index(flags, 'S') != -1)
                    mx_sort_filse_size(i->files, 0);
                else if (mx_reverse_index(flags, 't') != -1)
                    mx_sort_filse_time(i->files, 0);
            }
        }
    }
}

void mx_sort_arg(t_arg *lst, char *flags) {
    if (mx_reverse_index(flags, 'f') != -1 || !lst)
        return;
    mx_sort_arg_file_dir(lst);
    if (mx_reverse_index(flags, 'r') != -1) {
        mx_sort_arg_name(lst, 1);
        if (mx_reverse_index(flags, 'S') != -1)
            mx_sort_arg_size(lst, 1);
        else if (mx_reverse_index(flags, 't') != -1)
            mx_sort_arg_time(lst, 1);
    }
    else {
        mx_sort_arg_name(lst, 0);
        if (mx_reverse_index(flags, 'S') != -1)
            mx_sort_arg_size(lst, 0);
        else if (mx_reverse_index(flags, 't') != -1)
            mx_sort_arg_time(lst, 0);
    }
    sort_arg(lst, flags);
}
