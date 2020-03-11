#include "header.h"

static bool flags(char c) {
    char *s = "ACFGORSTUacefghiklmnoprstux1@";

    for (int i = 0; s[i]; i++)
        if (s[i] == c)
            return true;
    return false;
}

static void error_handle(char s) {
    mx_print_error("uls: illegal option -- ");
    write(2, &s, 1);
    mx_print_error("\nusage: uls ");
    mx_print_error("[-ACFGORSTUacefghiklmnoprstux1@] [file ...]\n");
    exit(1);
}

void mx_chek_flags(char *fl) {
    if (!fl)
        return ;
    fl++;
    if (*fl == '-') {
        fl++;
        if (mx_strlen(fl)) {
            fl--;
            error_handle(*fl);
        }
    }
    for (int i = 0; fl[i]; i++)
        if (!flags(fl[i]))
            error_handle(fl[i]);
}
