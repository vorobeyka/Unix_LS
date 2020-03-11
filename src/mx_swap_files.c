#include "header.h"

static void third_swap(t_files *i) {
    char *s = NULL;

    s = i->time_int;
    i->time_int = i->next->time_int;
    i->next->time_int = s;
    s = i->name;
    i->name = i->next->name;
    i->next->name = s;
    s = i->full_name;
    i->full_name = i->next->full_name;
    i->next->full_name = s;
    s = i->link_name;
    i->link_name = i->next->link_name;
    i->next->link_name = s;
    s = i->extended;
    i->extended = i->next->extended;
    i->next->extended = s;
}

static void second_swap(t_files *i) {
    char *s = NULL;

    s = i->user;
    i->user = i->next->user;
    i->next->user = s;
    s = i->group;
    i->group = i->next->group;
    i->next->group = s;
    s = i->size;
    i->size = i->next->size;
    i->next->size = s;
    s = i->min;
    i->min = i->next->min;
    i->next->min = s;
    s = i->maj;
    i->maj = i->next->maj;
    i->next->maj = s;
    s = i->date;
    i->date = i->next->date;
    i->next->date = s;
}

static void first_swap(t_files *i) {
    char *s = NULL;

    s = i->flag_i;
    i->flag_i = i->next->flag_i;
    i->next->flag_i = s;
    s = i->flag_s;
    i->flag_s = i->next->flag_s;
    i->next->flag_s = s;
    s = i->flag_o;
    i->flag_o = i->next->flag_o;
    i->next->flag_o = s;
    s = i->flag_h;
    i->flag_h = i->next->flag_h;
    i->next->flag_h = s;
    s = i->file_info;
    i->file_info = i->next->file_info;
    i->next->file_info = s;
    s = i->links;
    i->links = i->next->links;
    i->next->links = s;
}

void mx_swap_files(t_files *i) {
    int d = 0;

    d = i->file_dir;
    i->file_dir = i->next->file_dir;
    i->next->file_dir = d;
    first_swap(i);
    second_swap(i);
    third_swap(i);
}
