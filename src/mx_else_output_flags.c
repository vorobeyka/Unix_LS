#include "header.h"

static bool dop_m(char *flags) {
    if (mx_reverse_index(flags, '1') < mx_reverse_index(flags, 'm')
        && mx_reverse_index(flags, 'l') < mx_reverse_index(flags, 'm'))
        return true;
    return false;
}

void mx_else_output_flags(t_arg *i, char *flags, int total, int fl) {
    int x_pix = isatty(1) ? mx_find_ioctl() : 80;

    if ((fl != -1 && flags[fl] == '1'))
        mx_flag_one(i->files, flags, total);
    else if (fl != -1 && (flags[fl] == 'm' || dop_m(flags)))
        mx_flag_m(i->files, flags, x_pix);
    else if (fl != -1 && flags[fl] == 'x')
        mx_flag_x(i->files, flags, x_pix, total);
    else
        mx_flag_c(i->files, flags, x_pix, total);
}
