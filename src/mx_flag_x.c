#include "header.h"

static void first_flag_x(char *flags, int total) {
    if (mx_reverse_index(flags, 's') != -1) {
        char *v = mx_itoa(total);

        mx_combo("total: ", v);
        mx_printchar('\n');
        free(v);
    }
}

void mx_flag_x(t_files *lst, char *flags, int x_pix, int total) {
    first_flag_x(flags, total);
    char *s = NULL;
    char *z = NULL;

    for (t_files *j = lst; j; j = j->next) {
        s = mx_second_flag_x(flags, j, s);
        z = mx_third_flag_x(flags, j, z);
    }
    mx_add_x(s, x_pix, z, flags);
    free(s);
    free(z);
}
