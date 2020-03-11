#include "header.h"

void mx_permition_new(char *name, int fl, int flag) {
    if (fl == 1) {
        mx_print_error("uls: ");
        mx_print_error(name);
        mx_print_error(": No such file or directory\n");
    }
    else if (fl == 0) {
        if (flag == 1) {
            mx_print_error(name);
            mx_print_error(":\n");
        }
        mx_print_error("uls: ");
        mx_last_slesh_new(name);
        mx_print_error(": Permission denied\n");
    }
}
