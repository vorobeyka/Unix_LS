#include "header.h"

void mx_name(char **arr, int size) {
    char *s;

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (mx_strcmp(arr[j], arr[j + 1]) > 0) {
                s = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = s;
            }
        }
    }
}
