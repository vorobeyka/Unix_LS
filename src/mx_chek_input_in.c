#include "header.h"

void mx_chek_input_in(char *s1, int flag, int z) {
    if (mx_get_substr_index(s1, "/dev/fd/3") == 1
        || mx_strcmp(s1, "/dev/fd/3") == 0) {
        mx_print_error("uls: ");
        mx_print_error(s1);
        mx_print_error(": Bad file descriptor\n");
    }
    else {
        mx_print_diferent_erros(s1, flag, z);
    }
}
