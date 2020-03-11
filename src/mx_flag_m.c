#include "header.h"

static int len_of_lst(t_files *lst, char *flags) {
    int rez = 0;

    for (t_files *i = lst; i; i = i->next) {
        if (mx_reverse_index(flags, 'a') != -1
            || mx_reverse_index(flags, 'f') != -1) {
            rez++;
        }
        else if (mx_reverse_index(flags, 'A') != -1
            && (mx_strcmp(i->name, "..") != 0
            && mx_strcmp(i->name, ".") != 0)) {
            rez++;
        }
        else if (i->name[0] != '.') {
            rez++;
        }
    }
    return rez;
}

static void sasuske(t_files *i, t_for_m *t, char *flags, int *j) {
    t->m[*j] = mx_strjoin(i->name, ",");
    *j += 1;
    t->s = mx_add_s_i_m(flags, i, t->s);
    i->name = mx_more_than_name(i->full_name,
                                i->name, flags, i->file_info);
    t->z = mx_add_s_i_m(flags, i, t->z);
}

static void sakura(t_files *lst, t_for_m *t, char *flags) {
    int j = 0;

    for (t_files *i = lst; i; i = i->next) {
        if (mx_reverse_index(flags, 'a') != -1
            || mx_reverse_index(flags, 'f') != -1) {
            sasuske(i, t, flags, &j);
        }
        else if (mx_reverse_index(flags, 'A') != -1
            && (mx_strcmp(i->name, "..") != 0
            && mx_strcmp(i->name, ".") != 0)) {
            sasuske(i, t, flags, &j);
        }
        else if (i->name[0] != '.') {
            sasuske(i, t, flags, &j);
        }
    }
}

void mx_flag_m(t_files *lst, char *flags, int x_pix) {
    t_for_m t;

    t.m = (char **) malloc((len_of_lst(lst, flags) + 1)
          * sizeof(char *));
    t.m[len_of_lst(lst, flags)] = NULL;
    t.s = NULL;
    t.z = NULL;
    sakura(lst, &t, flags);
    mx_print_mm(&t, x_pix, flags);
    free(t.s);
    free(t.z);
    for (int i = 0; t.m[i]; i++)
        free(t.m[i]);
    free(t.m);
}
