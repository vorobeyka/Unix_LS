#include "header.h"

void mx_add_len_flag_s(t_files *lst, char *flags) {
    int max = mx_max_len_flag_s(lst, flags);
    
    for (t_files *i = lst; i; i = i->next)
        for (int j = max - mx_strlen(i->flag_s); j > 0; j--) {
            char *v = i->flag_s;
            
            i->flag_s = mx_strjoin(" ", i->flag_s);
            free(v);
        }
}
