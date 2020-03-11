#include "header.h"

static bool sor(char *s1, char *s2, char *flags) {
	int v1 = mx_afterr(s1, flags);
	int v2 = mx_afterr(s2, flags);

	if (v1 > v2)
		return true;
	return false;
}

void mx_buble(char **arr, int size, char *flags) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - 1 - i; j++) {
			if (sor(arr[j], arr[j + 1], flags)) {
				char *s = arr[j];

				arr[j] = arr[j + 1];
				arr[j + 1] = s;
			}
		}
	}
}
