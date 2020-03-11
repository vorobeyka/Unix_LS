#include "header.h"

void mx_sort_arg_name(t_arg *lst, int fl) {
	int flag = 1;

	while (flag) {
		flag = 0;
		for (t_arg *i = lst; i->next != NULL; i = i->next) {
			if ((mx_strcmp(i->name, i->next->name) > 0)
				&& (i->file_dir == i->next->file_dir)
				&& fl == 0) {
                mx_swap_argv(i);
				flag = 1;
			}
            if ((mx_strcmp(i->name, i->next->name) < 0)
				&& (i->file_dir == i->next->file_dir)
				&& fl == 1) {
                mx_swap_argv(i);
				flag = 1;
			}
		}
	}
}
