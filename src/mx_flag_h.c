#include "header.h"

static char *second_h(double size_whole, int size, char **src, int i) {
    char *s = NULL;
    int povit = (size_whole - (double)size) * 10;
    double rest = (size_whole - (double)size) * 100 - povit * 10;

    while (((int)rest % 10) == 5)
        rest *= 10;
    if (rest >= 5 && povit != 9)
            povit++;
    else if (rest >= 5 && povit == 9) {
        povit = 0;
        size++;
    }
    s = mx_combo_x4(size, povit, ".", src[i]);
    return s;
}

static char *first_h(double size_whole, int size, char **src, int i) {
    double rest = (size_whole - (double)size) * 10;
    char *s = NULL;

    if ((int)rest >= 5) {
        if (size + 1 >= mx_pow_bit(i))
            s = mx_combo_x3(s, "1.0", src[i + 1]);
        else {
            size++;
            s = mx_combo_x2(size, src[i]);
        }
    }
    else
        s = mx_combo_x2(size, src[i]);
    return s;
}

static char *flag_h(struct stat stbuf, char **src, int i) {
    char *s = NULL;
    int size;
    double size_whole = stbuf.st_size / mx_pow_bit_double(i);

    if ((int)size_whole == 0 && stbuf.st_size >= mx_pow_bit(i)) {
        if (i == 1)
            s = mx_combo_x3(s, "1.0", src[i]);
        else
            s = mx_super_join(flag_h(stbuf, src, i - 1), s);
    }
    else {
        size = stbuf.st_size / mx_pow_bit_double(i);
        if (size >= 9)
            s = first_h(size_whole, size, src, i);
        else
            s = second_h(size_whole, size, src, i);
    }
    return s;
}

char *mx_flag_h(struct stat stbuf) {
    char *s = NULL;
    int flag = mx_find_flag(stbuf);
    char *src[] = {"B", "K", "M", "G", "T", "P", NULL}; 
    
    s = flag_h(stbuf, src, flag - 1);
    return s;
}
