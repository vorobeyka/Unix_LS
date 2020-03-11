#include "header.h"

int main(int argc, char **argv) {
    int res = 0;
    
    mx_saske_vernis_v_konohy(argc, argv, &res);
    // system("leaks -q uls");
    return res;
}
