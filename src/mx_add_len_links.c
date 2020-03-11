#include "header.h"

void mx_add_len_links(t_files *lst, char *flags) {
    int max = mx_max_len_links(lst, flags);
    
    for (t_files *i = lst; i; i = i->next)
        for (int j = max - mx_strlen(i->links); j > 0; j--) {
            char *v = i->links;
            
            i->links = mx_strjoin(" ", i->links);
            free(v);
        }
}
