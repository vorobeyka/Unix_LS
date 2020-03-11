#include "header.h"

void mx_add_len_flag_i(t_files *lst, char *flags) {
    int max = mx_max_len_flag_i(lst, flags);
    
    for (t_files *i = lst; i; i = i->next)
        for (int j = max - mx_strlen(i->flag_i); j > 0; j--) {
            char *v = i->flag_i;
            
            i->flag_i = mx_strjoin(" ", i->flag_i);
            free(v);
        }
}
