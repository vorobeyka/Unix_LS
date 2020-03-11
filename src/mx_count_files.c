#include "header.h"

int mx_count_files(t_files *lst) {
    int count = 0;

    for (t_files *i = lst; i; i = i->next)
        count++;
    return count;
}
