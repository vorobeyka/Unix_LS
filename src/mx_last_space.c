#include "header.h"

void mx_last_space(t_files *i, char *flags) {
    if (!i)
        return;
    for (t_files *j = i; j; j = j->next) {
        if (mx_check_rec(j, flags, 1)
            && mx_reverse_index(flags, 'R') != -1
            && mx_check_g_tochka(j->name ,flags)) {
            mx_printstr("\n");
            break;
        }
        else if (mx_check_rec(j, flags, 0)
            && mx_reverse_index(flags, 'R') != -1
            && mx_reverse_index(flags, 'G') == -1) {
            mx_printstr("\n");
            break;
        }
    }
}
