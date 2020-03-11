#include "header.h"

void mx_permition(char *name, int fl, int flag, int z) {
    if (fl == 1) {
        mx_print_error("uls: ");
        mx_print_error(name);
        mx_print_error(": No such file or directory\n");
    }
    else if (fl == 0) {
        if (flag == 1) {
            if (z != 0)
                mx_printstr("\n");
            mx_print_error(name);
            mx_print_error(":\n");
        }
        mx_print_error("uls: ");
        mx_last_slesh(name);
        mx_print_error(": Permission denied\n");
    }
}
