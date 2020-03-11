#include "header.h"

static void pdef(char **str, t_all_nes t, char *flags, char **str_p) {
    for (int i = 0; i < t.rows; i++) {
        int pos = 0;

        for (int j = i; j < t.count; j += t.rows) {
            mx_printstr(str_p[j]);
            if (t.col - t.tabs - pos + 1 > t.tabs
                && j + t.rows < t.count) {
                pos += mx_naruto(str_p[j], flags)
                    ? mx_strlen(str[j]) + 1 : mx_strlen(str[j]);
                for (int z = mx_naruto(str_p[j], flags)
                    ? mx_strlen(str[j]) + 1
                    : mx_strlen(str[j]); z < t.tabs; z++) {
                    mx_printstr(" ");
                    pos++;
                }
            }
        }
        mx_printstr("\n");
    }
}

void mx_print_default(char **str, t_all_nes t,
    char *flags, char **str_p) {
    if (mx_reverse_index(flags, 'C') == -1 && !isatty(1))
        for (int i = 0; str_p[i]; i++) {
            mx_printstr(str_p[i]);
            mx_printstr("\n");
        }
    else
        pdef(str, t, flags, str_p);
}
