#include "header.h"

void mx_print_m(char *s, int x_pix, char *z) {
    char **v = mx_strsplit(s, '|');
    char **v1 = mx_strsplit(z, '|');
    int count = 0;

    if (v && v1) {
        for (int i = 0; v[i]; i++) {
            count += mx_strlen(v[i]);
            mx_printstr(v1[i]);
            if (v[i + 1] != NULL
                && count + mx_strlen(v[i + 1]) + 2 - x_pix > 0
                && count + mx_strlen(v[i + 1]) + 2 - x_pix > 8) {
                v1[i + 1] = mx_shift_space(v1[i + 1]);
                mx_printchar('\n');
                count = 0;
            }
        }
        mx_printchar('\n');
        mx_del_strarr(&v);
        mx_del_strarr(&v1);
    }
}
