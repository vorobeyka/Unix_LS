#include "header.h"

void mx_add_len_date(t_files *lst, char *flags) {
    int max = mx_max_len_date(lst, flags);
    
    for (t_files *i = lst; i; i = i->next)
        for (int j = max - mx_strlen(i->date); j > 0; j--) {
            char *v = i->date;
            
            i->date = mx_strjoin(i->date, " ");
            free(v);
        }
}
