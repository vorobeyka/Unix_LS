#include "header.h"

void mx_all(t_files *lst, char *flags) {
    if (mx_reverse_index(flags, 'O') != -1)
        mx_add_len_flag_o(lst, flags);
    if (mx_reverse_index(flags, 'h') != -1)
        mx_add_len_flag_h(lst, flags);
    mx_add_len_maj(lst);
    mx_add_len_min(lst, flags);
    mx_add_len_links(lst, flags);
    mx_add_len_user(lst, flags);
    mx_add_len_group(lst, flags);
    mx_add_len_size(lst, flags);
    if (mx_check_min_maj(lst, flags))
        mx_add_size_more(lst, flags);
    if (mx_check_size(lst, flags))
        mx_add_min_more(lst, flags);
    mx_add_len_date(lst, flags);
}
