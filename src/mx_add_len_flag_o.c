#include "header.h"

void mx_add_len_flag_o(t_files *lst, char *flags) {
    int max = mx_max_len_flag_o(lst, flags);
    
    for (t_files *i = lst; i; i = i->next)
        for (int j = max - mx_strlen(i->flag_o); j > 0; j--) {
            char *v = i->flag_o;
            
            i->flag_o = mx_strjoin(i->flag_o, " ");
            free(v);
        }
}
