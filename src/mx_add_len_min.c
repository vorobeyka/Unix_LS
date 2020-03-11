#include "header.h"

void mx_add_len_min(t_files *lst, char *flags) {
    int max = mx_max_len_min(lst, flags);
    
    for (t_files *i = lst; i; i = i->next)
        if (i->min)
            for (int j = max - mx_strlen(i->min); j > 0; j--)
                if (i->min[1] != 'x' && i->min) {
                    char *v = i->min;
                    
                    i->min = mx_strjoin(" ", i->min);
                    free(v);
                }
}
