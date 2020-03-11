#include "header.h"

static bool check_if_files(t_arg *lst) {
    for (t_arg *i = lst; i; i = i->next)
        if (i->file_dir == 1)
            return true;
    return false;
}

static bool check_if_dirs(t_arg *lst) {
    for (t_arg *i = lst; i; i = i->next)
        if (i->file_dir == 0)
            return true;
    return false;
}

static char *string_of_files(int fl, char *flags, t_arg *i, char *v) {
    char *s = NULL;

    if (v) {
        s = mx_strdup(v);
        free(v);
    }
    if (fl == -1 || flags[fl] == 'C')
        s = mx_second_flag_c(flags, i->files, s);
    else if (fl != -1 && flags[fl] == 'x')
        s = mx_second_flag_x(flags, i->files, s);
    else
        s = mx_second_flag_c(flags, i->files, s);
    if (fl != -1 && flags[fl] == 'm' && i->next->file_dir == 1)
        s = mx_super_join(s, ",");
    s = mx_super_join(s, "|");
    return s;
}

static void output_files(char *s, char *z, int fl, char *flags) {
    int x_pix = isatty(1) ? mx_find_ioctl() : 80;

    if ((fl == -1 && isatty(1) == 0) || (fl != -1 && flags[fl] == '1'))
        mx_output_one(z);
    else if (fl != -1 && flags[fl] == 'x')
        mx_add_x(s, x_pix, z, flags);
    else if (fl != -1 && flags[fl] == 'm')
        mx_output_m(s, z, x_pix, flags);
    else
        mx_add_c(s, x_pix, flags, z);
}

void mx_print_files(t_arg *arg, char *flags, int fl) {
    if (check_if_files(arg)) {
        char *s = NULL;
        char *z = NULL;

        for (t_arg *i = arg; i && i->file_dir == 1; i = i->next) {
            s = string_of_files(fl, flags, i, s);
            z = string_of_files(fl, flags, i, z);
        }
        output_files(s, z, fl, flags);
        if (check_if_dirs(arg))
            mx_printstr("\n");
        free(s);
        free(z);
    }
}
