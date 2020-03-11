#include "header.h"

static int mx_atoi(const char *s) {
    int res = 0;
	int n = 1;

    for (; *s; s++) {
        if (*s == '-')
			n = -1; 
        else
            res = res * 10 + (*s - '0');
    }
    return res * n;
}

static bool mx_sort(t_arg *i, int s1, int s2, int fl) {
	if (s1 < s2
		&& (i->file_dir == i->next->file_dir)
		&& fl == 0)
		return true;
	if (s1 > s2
		&& (i->file_dir == i->next->file_dir)
		&& fl == 1)
		return true;
	return false;
}

void mx_sort_arg_size(t_arg *lst, int fl) {
	int flag = 1;

	while (flag) {
		flag = 0;
		for (t_arg *i = lst; i->next != NULL; i = i->next) {
			int s1 = mx_atoi(i->size);
			int s2 = mx_atoi(i->next->size);

			if (mx_sort(i, s1, s2, fl)) {
                mx_swap_argv(i);
				flag = 1;
			}
            if (mx_sort(i, s1, s2, fl)) {
                mx_swap_argv(i);
				flag = 1;
			}
		}
	}
}
