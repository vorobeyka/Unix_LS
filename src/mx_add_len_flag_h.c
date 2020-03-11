#include "header.h"

void mx_add_len_flag_h(t_files *lst, char *flags) {
    int max = mx_max_len_flag_h(lst, flags);
    
    for (t_files *i = lst; i; i = i->next)
        for (int j = max - mx_strlen(i->flag_h); j > 0; j--) {
            char *v = i->flag_h;
            
            i->flag_h = mx_strjoin(" ", i->flag_h);
            free(v);
        }
}
