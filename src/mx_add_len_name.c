#include "header.h"

void mx_add_len_name(t_files *lst, char *flags) {
    int max = mx_max_len_name(lst, flags);
    
    for (t_files *i = lst; i; i = i->next)
        for (int j = max - mx_strlen(i->name); j > 0; j--) {
            char *v = i->name;
            
            i->name = mx_strjoin(i->name, " ");
            free(v);
        }
}
