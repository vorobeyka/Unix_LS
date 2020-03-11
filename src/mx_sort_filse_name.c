#include "header.h"

void mx_sort_filse_name(t_files *lst, int fl) {
	int flag = 1;

	while (flag) {
		flag = 0;
		for (t_files *i = lst; i->next != NULL; i = i->next) {
			if (mx_strcmp(i->name, i->next->name) > 0
				&& fl == 0) {
                mx_swap_files(i);
				flag = 1;
			}
            if (mx_strcmp(i->name, i->next->name) < 0
				&& fl == 1) {
                mx_swap_files(i);
				flag = 1;
			}
		}
	}
}
