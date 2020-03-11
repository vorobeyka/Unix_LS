#include "header.h"

void mx_add_x(char *s, int x_pix, char *z, char *flags) {
    char **v = mx_strsplit(s, '|');
    char **v1 = mx_strsplit(z, '|');
    t_all_nes t;
    int max_size = 0;
    
    t.count = mx_len_of_array(v);
    t.tabs = 0;
    t.rows = 0;
    t.col = x_pix;
    if (!t.count)
        return;
    mx_cx_max_size(&max_size, v);
    mx_cx_tabs(&t, flags, &max_size);
    mx_print_with_flag_x(v, t, v1, flags);
    mx_del_strarr(&v);
    mx_del_strarr(&v1);
}
