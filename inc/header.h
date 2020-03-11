#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <wchar.h>
#include <uuid/uuid.h>
#include <sys/uio.h>
#include <sys/acl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/xattr.h>
#include <sys/ioctl.h>
#include <malloc/malloc.h>
#include "macros_header.h"
#include "libmx/inc/libmx.h"

typedef struct s_all_nes {
    int rows;
    int col;
    int tabs;
    int count;
}              t_all_nes;

typedef struct s_files {
    int file_dir;
    char *flag_i;
    char *flag_s;
    char *flag_o;
    char *flag_h;
    char *file_info;
    char *links;
    char *user;
    char *group;
    char *size;
    char *min;
    char *maj;
    char *date;
    char *time_int;
    char *name;
    char *full_name;
    char *link_name;
    char *extended;
    struct s_files *next;
}              t_files;

typedef struct s_arg {
    int file_dir;
    int total;
    char *name;
    char *time_int;
    char *size;
    char *argv_info;
    struct s_arg *next;
    t_files *files;
}              t_arg;

typedef struct s_for_m {
    char *s;
    char *z;
    char **m;
}              t_for_m;

char *mx_time_int(struct stat stbuf, char *flags);
char *mx_super_join(char *src, char *d);
int mx_reverse_index(char *src, char s);
int mx_count_mass(char **argv);
bool mx_check_open(char *full_name);
void mx_print_error(char *src);
char *mx_array_flags(char **argv);
char *mx_first_group(struct stat stbuf);
char *mx_second_group(struct stat stbuf);
char *mx_third_group(struct stat stbuf);
char *mx_zero_group(struct stat stbuf);
char *mx_file_info(struct stat stbuf);
char *mx_exstra_group(char *name);
char *mx_combine(struct stat stbuf, char *name);
int mx_file_or_dir(struct stat stbuf, char *flags);
char *mx_flag_h(struct stat stbuf);
t_arg *mx_node_arg(char *name, char *flags);
t_arg *mx_list_argv(char **argv, char *flags);
void mx_swap_argv(t_arg *i);
void mx_swap_files(t_files *i);
void mx_sort_arg_name(t_arg *lst, int fl);
void mx_sort_arg_size(t_arg *lst, int fl);
void mx_sort_arg_time(t_arg *lst, int fl);
void mx_sort_arg_file_dir(t_arg *lst);
void mx_sort_filse_name(t_files *lst, int fl);
void mx_sort_filse_size(t_files *lst, int fl);
void mx_sort_filse_time(t_files *lst, int fl);
void mx_sort_arg(t_arg *lst, char *flags);
char *mx_user(struct stat stbuf, char *flags);
char *mx_group(struct stat stbuf);
char *mx_hex(int num);
char *mx_lenn_of_the_null(char *src);
char *mx_min(struct stat stbuf);
char *mx_maj(struct stat stbuf);
int mx_count_lenn_of_time(char *s, int fl);
char *mx_full_time(char *s);
char *mx_bolshe_polovinu(char *s);
char *mx_new_mass(char *s);
char *mx_time_file(struct stat stbuf, char *flags);
char *mx_flag_i(struct stat stbuf, char *flags);
char *mx_to_upper_numb(int num);
char *mx_get_s(struct stat stbuf, char *flags);
char *mx_flag_s(struct stat stbuf, char *flags);
char *mx_change(char *s, char *d, char *v);
char *mx_flag_e(char *name, struct stat stbuf);
char *mx_add_space(char *c, int num);
void mx_add_num(char **s, char *name);
char **mx_find_extend(char *name);
char *mx_print_extend(char *name);
char *mx_extra_line(char *name, struct stat stbuf, char *flags);
char *mx_combo_x3(char *src1, char *src2, char *src3);
char *mx_flag_g(struct stat stbuf, char *name, char *file_info);
char *mx_color_name(struct stat stbuf, char *name, char *flags, char *file_info);
char *mx_flag_fp(int flag, struct stat stbuf, char *file_info);
char *mx_find_f_p(struct stat stbuf, char *flags, char *file_info);
char *mx_more_than_name(char *full, char *name, char *flags, char *file_info);
char *mx_link_name(char *name);
double mx_pow_bit(int pow);
double mx_pow_bit_double(int pow);
int mx_find_flag(struct stat stbuf);
char *mx_combo_x2(int z, char *src1);
char *mx_combo_x4(int s1, int s2, char *src1, char *src2);
void mx_add_size_more(t_files *lst, char *flags);
bool mx_check_x(t_files *lst);
void mx_add_min_more(t_files *lst, char *flags);
void mx_chek_flags(char *fl);
char ***mx_chek_argv(char **argv);
char *mx_flag_o(unsigned long num, char *flags);
char *mx_turn_n(char *name);
t_files *mx_node_files(char *name, char *dir_name, char *flags);
t_files *mx_list_files(char *name, char *flags);
void mx_add_dir_list(t_arg *lst, char *flags);
int mx_count_argv(t_arg *lst);
int mx_count_files(t_files *lst);
void mx_free(t_arg *lst);
void mx_total(t_arg *lst, char *flags);
int mx_max_len_flag_i(t_files *lst, char *flags);
void mx_add_len_flag_i(t_files *lst, char *flags);
int mx_max_len_flag_s(t_files *lst, char *flags);
void mx_add_len_flag_s(t_files *lst, char *flags);
int mx_max_len_flag_o(t_files *lst, char *flags);
void mx_add_len_flag_o(t_files *lst, char *flags);
int mx_max_len_flag_h(t_files *lst, char *flags);
void mx_add_len_flag_h(t_files *lst, char *flags);
int mx_max_len_links(t_files *lst, char *flags);
void mx_add_len_links(t_files *lst, char *flags);
int mx_max_len_user(t_files *lst, char *flags);
void mx_add_len_user(t_files *lst, char *flags);
int mx_max_len_group(t_files *lst, char *flags);
void mx_add_len_group(t_files *lst, char *flags);
int mx_max_len_size(t_files *lst, char *flags);
void mx_add_len_size(t_files *lst, char *flags);
int mx_max_len_date(t_files *lst, char *flags);
void mx_add_len_date(t_files *lst, char *flags);
int mx_max_len_min(t_files *lst, char *flags);
void mx_add_len_min(t_files *lst, char *flags);
void mx_add_len_maj(t_files *lst);
bool mx_check_min_maj(t_files *lst, char *flags);
bool mx_check_size(t_files *lst, char *flags);
void mx_all(t_files *lst, char *flags);
void mx_combo(char *str1, char *str2);
void mx_print_all(t_files *i, char *flags, int fl);
void mx_format_long(t_files *lst, char *flags, int fl);
void mx_flag_l(t_arg *i, char *flags, int fl);
char *mx_add_s_i_m(char *flags, t_files *i, char *c);
char *mx_shift_space(char *src);
void mx_print_mm(t_for_m *t, int x_pix, char *flags);
void mx_print_m(char *s, int x_pix, char *z);
void mx_flag_m(t_files *lst, char *flags, int x_pix);
void mx_add_one(char *flags, t_files *i);
void mx_flag_one(t_files *lst, char *flags, int total);
int mx_max_len_name(t_files *lst, char *flags);
void mx_add_len_name(t_files *lst, char *flags);
int mx_len_of_array(char **a);
bool mx_chech_end_width(t_all_nes *t, int pos, int j);
bool mx_naruto(char *s, char *flags);
void mx_print_with_flag_x(char **str, t_all_nes t, char **str_p, char *flags);
char *mx_add_cx(char *flags, t_files *i, char *c);
void mx_add_x(char *s, int x_pix, char *z, char *flags);
char *mx_full_str(char *c, t_files *i, char *flags);
void mx_flag_x(t_files *lst, char *flags, int x_pix, int total);
void mx_print_default(char **str, t_all_nes t, char *flags, char **str_p);
void mx_add_c(char *s, int x_pix, char *flags, char *z);
void mx_flag_c(t_files *lst, char *flags, int x_pix, int total);
int mx_find_ioctl(void);
void mx_else_output_flags(t_arg *i, char *flags, int total, int fl);
int mx_find_true_flag(char *f);
int mx_lenn_list(t_arg *lst);
void mx_output_formats(t_arg *i, char *flags, t_arg *arg, int total);
bool mx_check_rec(t_files *j, char *flags, int fl);
bool mx_check_g_tochka(char *name, char *flags);
void mx_uls(char **argv, char *flags, int *res);
bool mx_check_argv_tochka(int argc, char **argv);
char **mx_mass_for_tochka(char **argv);
int mx_count_new_argv(char *fl, char ***src);
char **mx_create_f_z(char ***s, char *fl);
void mx_buble(char **arr, int size, char *flags);
char **mx_chek_input(char **argv, char *flag);
void mx_saske_vernis_v_konohy(int argc, char **argv, int *res);
int main(int argc, char **argv);
void mx_r_uls(t_files *j, char *flags, int *res);
void mx_cx_max_size(int *max_size, char **v);
void mx_cx_tabs(t_all_nes *t, char *flags, int *max_size);
void mx_add_x(char *s, int x_pix, char *z, char *flags);
char *mx_third_flag_x(char *flags, t_files *j, char *v);
char *mx_second_flag_x(char *flags, t_files *j, char *v);
char *mx_third_flag_c(char *flags, t_files *j, char *v);
char *mx_second_flag_c(char *flags, t_files *j, char *v);
char *mx_first_e(char **z, char *s);
void mx_files_flag_s(t_arg *lst);
void mx_files_flag_i(t_arg *lst);
void mx_files_flag_o(t_arg *lst);
void mx_files_flag_h(t_arg *lst);
void mx_files_links(t_arg *lst);
void mx_files_user(t_arg *lst);
void mx_files_group(t_arg *lst);
void mx_files_size(t_arg *lst);
void mx_files_date(t_arg *lst);
void mx_files_maj(t_arg *lst);
void mx_files_min(t_arg *lst);
void mx_all_for_files(t_arg *lst, char *flags);
void mx_output_one(char *s);
void mx_output_m(char *s, char *z, int x_pix, char *flags);
void mx_print_files(t_arg *arg, char *flags, int fl);
void mx_last_space(t_files *i, char *flags);
void mx_last_slesh_new(char *name);
void mx_permition_new(char *name, int fl, int flag);
bool mx_first_check(char *name);
int mx_count_all_intput(char **argv);
char **mx_cre_argv(char *name);
char **mx_new_argv(char **argv, int size);
int mx_get_rev_index(char *name, char s);
void mx_last_slesh(char *name);
void mx_permition(char *name, int fl, int flag, int z);
void mx_print_diferent_erros(char *name, int flag, int z);
void mx_chek_input_in(char *s1, int flag, int z);
void mx_error(char *name, char **v, int z, int *res);
void mx_name(char **arr, int size);
int mx_afterr(char *name, char *flags);
void mx_slesh_en(char *name, char *pre_name, char *flags);
void mx_files(char **arr, int size, char *flags);
void mx_add_start(char **v, int i, char *flags, int *res);
bool mx_check_stat(char *name, char *flags);
void mx_kostul(char *d, char *flags, int *res);
char *mx_ne_spi(char *d, int flag, char **v, int i);
void mx_konets(char **v, char *flags);
void mx_start(char **argv, char *flags, int count, int *res);

#endif
