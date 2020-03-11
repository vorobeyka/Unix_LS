#include "header.h"

void mx_add_len_maj(t_files *lst) {
    int max = 3;
    
    for (t_files *i = lst; i; i = i->next)
        if (i->maj)
            for (int j = max - mx_strlen(i->maj); j > 0; j--)
                if (i->maj[1] != 'x') {
                    char *v = i->maj;
                    
                    i->maj = mx_strjoin(" ", i->maj);
                    free(v);
                }
}
