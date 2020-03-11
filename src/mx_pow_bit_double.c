#include "header.h"

double mx_pow_bit_double(int pow) {
    double x = 1;
    
    if (pow == 0)
        return x;

    for (int i = pow; i > 0; i--) {
        if (i == pow)
            x = 1024;
        else 
            x *= 1024;
    }
    return x;
}
