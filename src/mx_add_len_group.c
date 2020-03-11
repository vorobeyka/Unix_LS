#include "header.h"

void mx_add_len_group(t_files *lst, char *flags) {
    int max = mx_max_len_group(lst, flags);
    
    for (t_files *i = lst; i; i = i->next)
        for (int j = max - mx_strlen(i->group); j > 0; j--) {
            char *v = i->group;
            
            i->group = mx_strjoin(i->group, " ");
            free(v);
        }
}
