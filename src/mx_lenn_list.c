#include "header.h"

int mx_lenn_list(t_arg *lst) {
    int count = 0;

    for (t_arg *i = lst; i; i = i->next)
        count++;
    return count;
}
