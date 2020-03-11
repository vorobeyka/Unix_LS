#include "header.h"

static bool chech_files_for_h(t_arg *lst) {
    for (t_arg *i = lst; i && i->file_dir == 1; i = i->next)
        if (i->files->min || i->files->min)
            return true;
    return false;
}

static bool check_smth(int fl, char *flags) {
    if (fl != -1
        && (flags[fl] == 'g' 
        || flags[fl] == 'o' 
        || flags[fl] == 'l'
        || flags[fl] == 'n')) {
        return true;
    }
    return false;
}

void mx_output_formats(t_arg *i, char *flags, t_arg *arg, int total) {
    if (mx_lenn_list(arg) != 1 && i->file_dir == 0)
        mx_combo(i->name, ":\n");
    if (mx_reverse_index(flags, 'i') != -1)
        mx_add_len_flag_i(i->files, flags);
    if (mx_reverse_index(flags, 's') != -1)
        mx_add_len_flag_s(i->files, flags);
    int fl = mx_find_true_flag(flags);

    if (check_smth(fl, flags)) {
        if (chech_files_for_h(arg) && i->argv_info[0] != 'd')
            mx_flag_l(i, flags, 1);
        else 
            mx_flag_l(i, flags, 0);
    }
    else
        mx_else_output_flags(i, flags, total, fl);
}
