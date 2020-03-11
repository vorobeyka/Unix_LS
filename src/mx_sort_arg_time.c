#include "header.h"

void mx_sort_arg_time(t_arg *lst, int fl) {
	int flag = 1;

	while (flag) {
		flag = 0;
		for (t_arg *i = lst; i->next != NULL; i = i->next) {
			if ((mx_strcmp(i->time_int, i->next->time_int) < 0)
				&& (i->file_dir == i->next->file_dir) 
				&& fl == 0) {
                mx_swap_argv(i);
				flag = 1;
			}
            if ((mx_strcmp(i->time_int, i->next->time_int) > 0)
				&& (i->file_dir == i->next->file_dir)
				&& fl == 1) {
                mx_swap_argv(i);
				flag = 1;
			}
		}
	}
}
