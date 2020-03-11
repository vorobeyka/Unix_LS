#include "header.h"

static bool check_create(char *name) {
    DIR *dir;
    struct stat stbuf;

    if (lstat(name, &stbuf) == -1)
        return false;
    if (MX_ISDIR(stbuf.st_mode)) {
        dir = opendir(name);
        if (dir == NULL)
            return false;
        else
            closedir(dir);
    }
    return true;
}

static void chek_argv(char ****d, char **argv) {
    char ***s = *d;

    s[0] = (char **)malloc(sizeof(char *) * (mx_count_mass(argv) + 1));
    s[1] = (char **)malloc(sizeof(char *) * (mx_count_mass(argv) + 1));
    s[2] = NULL;
    s[0][mx_count_mass(argv)] = NULL;
    s[1][mx_count_mass(argv)] = NULL;
    s[0][0] = mx_strdup(argv[0]);
    s[1][0] = mx_strdup("0");
}

char ***mx_chek_argv(char **argv) {
    char ***s = (char ***)malloc(sizeof(char **) * 3);
    int flag = 0;

    chek_argv(&s, argv);
    for (int i = 1; argv[i]; i++) {
        if (mx_strcmp(argv[i], "--") == 0) {
            flag = 1;
            s[1][i] = mx_strdup("0");
        }
        else if (flag == 0 && argv[i][0] == '-')
            s[1][i] = mx_strdup("0");
        else if (flag == 1 && argv[i][0] == '-')
            s[1][i] = mx_strdup("1");
        else if (check_create(argv[i]) == true)
            s[1][i] = mx_strdup("0");
        else
            s[1][i] = mx_strdup("1");
        s[0][i] = mx_strdup(argv[i]);
    }
    return s;
}
