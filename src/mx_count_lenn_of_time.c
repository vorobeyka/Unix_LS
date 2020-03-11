#include "header.h"

int mx_count_lenn_of_time(char *s, int fl) {
    int count = 0;

    for (int i = 4; i < mx_strlen(s) - 1; i++) {
        if (i < 16 && fl == 0)
            count++;
        else if ((i < 11 || i > 18) && fl == 1)
            count++;
    }
    return count;
}
