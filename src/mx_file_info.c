#include "header.h"

char *mx_file_info(struct stat stbuf) {
    char *s = mx_zero_group(stbuf);
    char *first = mx_first_group(stbuf);
    char *second = mx_second_group(stbuf);
    char *third = mx_third_group(stbuf);

    s = mx_super_join(s, first);
    s = mx_super_join(s, second);
    s = mx_super_join(s, third);
    free(first);
    free(second);
    free(third);
    first = NULL;
    second = NULL;
    third = NULL;
    return s;
}
