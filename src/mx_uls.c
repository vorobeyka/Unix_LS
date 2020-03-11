#include "header.h"

static void mx_print_long_files(t_arg *arg, char *flags) {
    mx_all_for_files(arg, flags);
    for (t_arg *i = arg; i; i = i->next)
        if (i->file_dir == 1)
            mx_output_formats(i, flags, arg, i->total);
}

static void uls_error(t_files *j, int fl, int *res) {
    if (fl == 1) {
        mx_print_error("\nuls: ");
        mx_print_error(j->full_name);
        mx_print_error(": Bad file descriptor\n");
        *res = 1;
    }
    if (fl == 2) {
        mx_print_error("\nuls: ");
        mx_print_error(j->full_name);
        mx_print_error(": Permission denied\n");
        *res = 1;
    }
}

static void uls(t_files *j, char *flags, int *res) {
    if (mx_check_rec(j, flags, 1)
        && mx_reverse_index(flags, 'R') != -1) {
            mx_r_uls(j, flags, res);
            mx_last_space(j->next, flags);
        }
    else if (mx_check_rec(j, flags, 0)
        && mx_reverse_index(flags, 'R') != -1) {
            mx_r_uls(j, flags, res);
            mx_last_space(j->next, flags);
        }
    else if (j->file_info[0] == 'd'
        && mx_get_substr_index(j->full_name, "/dev/fd/3") == 1)
        uls_error(j, 1, res);
    else if (j->file_info[0] == 'd'
        && !mx_check_open(j->full_name)
        && mx_strcmp(j->name, ".") != 0
        && mx_strcmp(j->name, "..") != 0)
        uls_error(j, 2, res);
}

static void statos_uls(t_arg *arg, char *flags, int *res) {
    for (t_arg *i = arg; i; i = i->next) {
        if (i->file_dir == 0) {
            mx_output_formats(i, flags, arg, i->total);
            mx_last_space(i->files, flags);
            for (t_files *j = i->files; j; j = j->next) {
                if (mx_reverse_index(flags, 'R') != -1
                    && mx_check_g_tochka(j->name, flags)) {
                    uls(j, flags, res);
                }
            }
        }
    }
}

void mx_uls(char **argv, char *flags, int *res) {
    t_arg *arg = mx_list_argv(argv, flags);
    int fl = mx_find_true_flag(flags);

    mx_add_dir_list(arg, flags);
    mx_sort_arg(arg, flags);
    mx_total(arg, flags);
    if (fl != -1 && flags[fl] == 'l')
        mx_print_long_files(arg, flags);
    else
        mx_print_files(arg, flags, fl);
    statos_uls(arg, flags, res);
    mx_free(arg);
}
