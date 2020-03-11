#include "header.h"

void mx_files(char **arr, int size, char *flags) {
    char *s;

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (mx_afterr(arr[j], flags) == 0
                && mx_afterr(arr[j + 1], flags) == 0
                && mx_first_check(arr[j])
                && !mx_first_check(arr[j + 1])) {
                s = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = s;
            }
        }
    }
}
