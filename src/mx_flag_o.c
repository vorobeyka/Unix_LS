#include "header.h"

char *mx_flag_o(unsigned long num, char *flags) {
    unsigned long nums[5] = {1048576, 524288, 32768, 32, 2};
    char t[5][12] = {"sunlnk", "restricted", "hidden",
                     "compressed", "uchg"};
    char *rez =  NULL;
    unsigned long sum = num;

    if (mx_reverse_index(flags, 'O') != -1) {
        if (num == 0)
            return mx_strdup("-");
        for (int i = 0; i < 5; i++)
            if (sum >= nums[i]) {
                rez = mx_super_join(rez, t[i]);
                sum -= nums[i];
                if (sum != 0)
                    rez = mx_super_join(rez, ",");
            }
    }
    return rez;
}
