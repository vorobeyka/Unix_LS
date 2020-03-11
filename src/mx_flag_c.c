#include "header.h"

static void first_flag_с(char *flags, int total) {
    if (mx_reverse_index(flags, 's') != -1) {
        char *v = mx_itoa(total);

        mx_combo("total: ", v);
        mx_printchar('\n');
        free(v);
    }
}

void mx_flag_c(t_files *lst, char *flags, int x_pix, int total) {
    first_flag_с(flags, total);
    char *s = NULL;
    char *z = NULL;

    for (t_files *j = lst; j; j = j->next) {
        s = mx_second_flag_c(flags, j, s);
        z = mx_third_flag_c(flags, j, z);
    }
    mx_add_c(s, x_pix, flags, z);
    free(s);
    free(z);
}
