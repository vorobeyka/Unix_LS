#include "header.h"

static void with_x(int *pos) {
    mx_printstr(" ");
    *pos += 1;
}

static int with_flag_x(int pos) {
    mx_printstr("\n");
    pos = 0;
    return pos;
}

static int f_x(char **str, char **str_p, char *flags, int j) {
    int i = mx_naruto(str_p[j], flags)
        ? mx_strlen(str[j]) + 1 : mx_strlen(str[j]);
    
    return i;
}

void mx_print_with_flag_x(char **str, t_all_nes t,
                          char **str_p, char *flags) {
    int j = 0;
    int pos = 0;

    for ( ; j < t.count; j++) {
        mx_printstr(str_p[j]);
        if (!str_p[j + 1]) {
            mx_printstr("\n");
            return;
        }
        if (t.col - pos - t.tabs + 1 >= t.tabs) {
            pos += f_x(str, str_p, flags, j);
            for (int i = f_x(str, str_p, flags, j);
                i < t.tabs && t.col - pos > t.tabs; i++)
                with_x(&pos);
        }
        else
            pos = with_flag_x(pos);
        if (mx_chech_end_width(&t, pos, j) && isatty(1))
            pos = with_flag_x(pos);
    }
}
