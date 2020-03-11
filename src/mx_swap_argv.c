#include "header.h"

static void first_swap_argv(t_arg *i) {
    char *s = NULL;

    s = i->name;
    i->name = i->next->name;
    i->next->name = s;
    s = i->size;
    i->size = i->next->size;
    i->next->size = s;
    s = i->time_int;
    i->time_int = i->next->time_int;
    i->next->time_int = s;
    s = i->argv_info;
    i->argv_info = i->next->argv_info;
    i->next->argv_info = s;
}

void mx_swap_argv(t_arg *i) {
    int d = 0;
    t_files *v = NULL;

    d = i->file_dir;
    i->file_dir = i->next->file_dir;
    i->next->file_dir = d;
    d = i->total;
    i->total = i->next->total;
    i->next->total = d;
    v = i->files;
    i->files = i->next->files;
    i->next->files = v;
    first_swap_argv(i);
}
