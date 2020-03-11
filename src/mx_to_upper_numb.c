#include "header.h"

char *mx_to_upper_numb(int num) {
    char *tmp = NULL;
    double rez = num / 2.;

    if ((double) (num / 2) + 0.5 <= rez)
        tmp = mx_itoa((num / 2) + 1);
    else
        tmp = mx_itoa(num / 2);
    return tmp;
}
