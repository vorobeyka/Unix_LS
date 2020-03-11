#include "header.h"

int mx_find_flag(struct stat stbuf) {
    int flag = 0;

    if (stbuf.st_size >= 0 && stbuf.st_size < mx_pow_bit(1))
        flag = 1;
    if (stbuf.st_size >= mx_pow_bit(1)
        && stbuf.st_size < mx_pow_bit(2))
        flag = 2;
    else if (stbuf.st_size >= mx_pow_bit(2)
        && stbuf.st_size < mx_pow_bit(3))
        flag = 3;
    else if (stbuf.st_size >= mx_pow_bit(3)
        && stbuf.st_size < mx_pow_bit(4))
        flag = 4;
    else if (stbuf.st_size >= mx_pow_bit(4)
        && stbuf.st_size < mx_pow_bit(5))
        flag = 5;
    else if (stbuf.st_size >= mx_pow_bit(5)
        && stbuf.st_size < mx_pow_bit(6))
        flag = 6;
    return flag;
}
