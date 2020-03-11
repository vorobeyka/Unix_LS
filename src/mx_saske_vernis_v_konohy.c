#include "header.h"

void mx_saske_vernis_v_konohy(int argc, char **argv, int *res) {
    if (!argc)
        return;
    char *flags = mx_array_flags(argv);

    mx_chek_flags(flags);
    int count = mx_count_all_intput(argv);

    if (count == 0) {
        char **s = mx_mass_for_tochka(argv);

        mx_uls(s, flags, res);
        mx_del_strarr(&s);
    }
    else
        mx_start(argv, flags, count, res);
    free(flags);
}
