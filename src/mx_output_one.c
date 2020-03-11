#include "header.h"

void mx_output_one(char *s) {
    char **v = mx_strsplit(s, '|');

    for (int i = 0; v[i]; i++) {
        mx_printstr(v[i]);
        mx_printstr("\n");
    }
    mx_del_strarr(&v);
}
