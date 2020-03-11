#include "header.h"

int mx_find_ioctl(void) {
    int x_pix = 0;
    struct winsize window;

    ioctl(STDOUT_FILENO, TIOCGWINSZ, &window);
    x_pix = window.ws_col;
    return x_pix;
}
