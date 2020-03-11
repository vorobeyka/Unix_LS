#include "header.h"

static bool mnaruto(char *s, char *flags) {
    if (((s[mx_strlen(s) - 2] == '*'
        || s[mx_strlen(s) - 2] == '|'
        || s[mx_strlen(s) - 2] == '@'
        || s[mx_strlen(s) - 2] == '/'
        || s[mx_strlen(s) - 2] == '=')
        && mx_reverse_index(flags, 'F') != -1)
        || (s[mx_strlen(s) - 2] == '/'
        && mx_reverse_index(flags, 'p') != -1))
        return true;
    return false;
}

static int len_with_s_i(char *flags, char *str1, char *str3) {
    int rez = 0;
    if (mx_reverse_index(flags, 's') != -1
        || mx_reverse_index(flags, 'i') != -1) {
        rez += mx_strlen(str1) - mx_strlen(str3);
    }
    return rez;
}

static bool cycle_continue(int *count, int x_pix, int i, char **v) {
    if (*count >= x_pix) {
        mx_printstr("\n");
        *count = 0;
        return true;
    }
    mx_printstr(v[i]);
    if (v[i + 1])
        mx_printchar(' ');
    return false;
}

void mx_print_mm(t_for_m *t, int x_pix, char *flags) {
    char **v = mx_strsplit(t->s, '|');
    char **v1 = mx_strsplit(t->z, '|');
    int count = 0;
    int len_name;

    if (v && v1) {
        for (int i = 0; v[i]; ) {
            len_name = mnaruto(v1[i], flags)
                ? mx_strlen(t->m[i]) + 2 : mx_strlen(t->m[i]) + 1;
            count += len_name;
            if (cycle_continue(&count, x_pix, i, v1))
                continue;
            count += len_with_s_i(flags, v[i], t->m[i]);
            i++;
        }
        mx_printchar('\n');
        mx_del_strarr(&v);
        mx_del_strarr(&v1);
    }
}
