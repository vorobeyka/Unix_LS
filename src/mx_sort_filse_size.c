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

void mx_sort_filse_size(t_files *lst, int fl) {
	int flag = 1;

	while (flag) {
		flag = 0;
		for (t_files *i = lst; i->next != NULL; i = i->next) {
			int s1 = mx_atoi(i->size);
			int s2 = mx_atoi(i->next->size);

			if (s1 < s2 && fl == 0) {
                mx_swap_files(i);
				flag = 1;
			}
			if (s1 > s2 && fl == 1) {
                mx_swap_files(i);
				flag = 1;
			}
		}
	}
}
