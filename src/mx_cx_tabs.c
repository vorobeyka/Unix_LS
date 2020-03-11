#include "header.h"

void mx_cx_tabs(t_all_nes *t, char *flags, int *max_size) {
    if (mx_reverse_index(flags, 'G') != -1 && isatty(1))
            t->tabs = mx_reverse_index(flags, 'F') != -1
                || mx_reverse_index(flags, 'p') != -1
                ? *max_size + 2 : *max_size + 1;
    else
        for (int i = 1; i <= *max_size; i++)
            if (*max_size < i * 8) {
                t->tabs = i * 8;
                break;
            }
    for (int i = 1; ; i++)
        if (t->tabs == 0 || (t->col / (t->tabs)) * i >= t->count) {
            t->rows = i;
            break;
        }
}
