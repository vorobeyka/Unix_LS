#include "header.h"

int mx_count_argv(t_arg *lst) {
    int count = 0;

    for (t_arg *i = lst; i; i = i->next)
        count++;
    return count;
}
