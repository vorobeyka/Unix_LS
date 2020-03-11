#include "header.h"

void mx_add_len_user(t_files *lst, char *flags) {
    int max = mx_max_len_user(lst, flags);
    
    for (t_files *i = lst; i; i = i->next)
        for (int j = max - mx_strlen(i->user); j > 0; j--) {
            char *v = i->user;
            
            i->user = mx_strjoin(i->user, " ");
            free(v);
        }
}
