#include "header.h"

static void third_free(int i, t_arg *lst) {
    t_arg *z = lst;

    for (int j = 0; j < i - 1; j++)
        z = z->next;
    for (int k = mx_count_files(z->files); k > 0; k--) {
        t_files *l = z->files;

        for (int m = 0; m < k - 1; m++)
            l = l->next;
        free(l);
    }
    free(z);
}

static void second_free(t_files *j) {
    free(j->file_info);
    free(j->links);
    free(j->user);
    free(j->group);
    free(j->size);
    free(j->date);
    free(j->time_int);
    free(j->name);
    free(j->full_name);
}

static void first_free(t_files *j) {
    if (j->flag_i)
        free(j->flag_i);
    if (j->flag_s)
        free(j->flag_s);
    if (j->flag_o)
        free(j->flag_o);
    if (j->flag_h)
        free(j->flag_h);
    if (j->min && j->maj) {
        free(j->min);
        free(j->maj);
    }
    if (j->link_name)
        free(j->link_name);
    if (j->extended)
        free(j->extended);
}

void mx_free(t_arg *lst) {
    if (!lst)
        return;
    for (t_arg *i = lst; i; i = i->next) {
        free(i->name);
        free(i->time_int);
        free(i->size);
        free(i->argv_info);
        for (t_files *j = i->files; j; j = j->next) {
            first_free(j);
            second_free(j);
        }
    }

    for (int i = mx_count_argv(lst); i > 0; i--)
        third_free(i, lst);
}
