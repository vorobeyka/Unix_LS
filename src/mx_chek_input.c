#include "header.h"

static void print_diferent_erros(char *name, int flag) {
    DIR *dir;
    struct stat stbuf;

    if (lstat(name, &stbuf) == -1) {
        mx_permition_new(name, 1, flag);
        return;
    }
    if (MX_ISDIR(stbuf.st_mode)) {
        dir = opendir(name);
        if (dir == NULL) {
            mx_permition_new(name, 0, flag);
            return;
        }
        else
            closedir(dir);
    }
}

static void chek_input(char **s1, int flag) {
    for (int i = 0; s1[i]; i++) {
        if (mx_get_substr_index(s1[i], "/dev/fd/3") == 1
            || mx_strcmp(s1[i], "/dev/fd/3") == 0) {
            mx_print_error("uls: ");
            mx_print_error(s1[i]);
            mx_print_error(": Bad file descriptor\n");
        }
        else
            print_diferent_erros(s1[i], flag);
    }
}

static int count_olny_argv(char **s) {
    int count = 0;

    for (int i = 1; s[i]; i++)
        if (s[i][0] != '-')
            count++;
    return count;
}

char **mx_chek_input(char **argv, char *flags) {
    char ***s = mx_chek_argv(argv);
    char **s0 = mx_create_f_z(s, "0");
    char **s1 = mx_create_f_z(s, "1");
    int flag = 0;


    if (s1) {
        if (mx_count_mass(s1) > 1 || count_olny_argv(s0) > 0)
            flag = 1;
        mx_buble(s1, mx_count_new_argv("1", s), flags);
        chek_input(s1, flag);
        mx_del_strarr(&s1);
        if (count_olny_argv(s0) > 0)
            mx_printchar('\n');
    }
    mx_del_strarr(&s[0]);
    mx_del_strarr(&s[1]);
    free(s);
    return s0;
}
