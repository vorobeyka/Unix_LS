#include "header.h"

void mx_sort_arg_file_dir(t_arg *lst) {
	int flag = 1;

	while (flag) {
		flag = 0;
		for (t_arg *i = lst; i->next != NULL; i = i->next) {
			if (i->file_dir < i->next->file_dir) {
                mx_swap_argv(i);
				flag = 1;
			}
		}
	}
}
