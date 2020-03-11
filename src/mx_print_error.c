#include "header.h"

void mx_print_error(char *src) {
    int i = mx_strlen(src);

    write(2, src, i);
}
