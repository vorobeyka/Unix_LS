#include "header.h"

void mx_output_m(char *s, char *z, int x_pix, char *flags) {
    t_for_m *t = (t_for_m *)malloc(sizeof(t_for_m) * 1);
    
    t->s = mx_strdup(s);
    t->z = mx_strdup(z);
    t->m = mx_strsplit(s, '|');
    mx_print_mm(t, x_pix, flags);
    free(t->s);
    free(t->z);
    mx_del_strarr(&t->m);
    free(t);
}
