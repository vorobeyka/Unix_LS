#include "header.h"

void mx_add_len_size(t_files *lst, char *flags) {
    int max = mx_max_len_size(lst, flags);
    
    for (t_files *i = lst; i; i = i->next)
        for (int j = max - mx_strlen(i->size); j > 0; j--) {
            char *v = i->size;
            
            i->size = mx_strjoin(" ", i->size);
            free(v);
        }
}
