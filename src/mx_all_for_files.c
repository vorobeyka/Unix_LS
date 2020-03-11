#include "header.h"

static bool mx_check_files_x(t_arg *lst) {
    for (t_arg *i = lst; i && i->file_dir == 1; i = i->next)
        if (i->files->min || i->files->maj)
            return true;
    return false;
}

static int files_more(t_arg *lst) {
    int count = 0;

    for (t_arg *i = lst; i && i->file_dir == 1; i = i->next)
        if (i->files->min && i->files->maj)
            if (!mx_check_x(i->files)
                && mx_strlen(i->files->min)
                + mx_strlen(i->files->maj) + 2 > count)
                count = mx_strlen(i->files->min)
                        + mx_strlen(i->files->maj) + 2;
    return count;
}

static void mx_files_more(t_arg *lst) {
    int count = files_more(lst) + 1;

    for (t_arg *i = lst; i && i->file_dir == 1;  i = i->next)
        if (!i->files->min && !i->files->maj)
            for (int j = mx_strlen(i->files->size); j < count; j++) {
                char *v = i->files->size;

                i->files->size = mx_strjoin(" ", i->files->size);
                free(v);
            }
}

static void more_space(t_arg *lst) {
    for (t_arg *i = lst; i && i->file_dir == 1;  i = i->next)
        i->files->group = mx_super_join(i->files->group, " ");
}

void mx_all_for_files(t_arg *lst, char *flags) {
    if (mx_reverse_index(flags, 's') != -1)
        mx_files_flag_s(lst);
    if (mx_reverse_index(flags, 'i') != -1)
        mx_files_flag_i(lst);
    if (mx_reverse_index(flags, 'O') != -1)
        mx_files_flag_o(lst);
    if (mx_reverse_index(flags, 'h') != -1)
        mx_files_flag_h(lst);
    mx_files_maj(lst);
    mx_files_min(lst);
    mx_files_links(lst);
    mx_files_user(lst);
    mx_files_group(lst);
    mx_files_size(lst);
    if (mx_check_files_x(lst)) {
        mx_files_more(lst);
        more_space(lst);
    }
    mx_files_date(lst);
}
