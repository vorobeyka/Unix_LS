#include "header.h"

t_arg *mx_list_argv(char **argv, char *flags) {
    t_arg *head = NULL;
    t_arg *povit = NULL;
    int flag = 0;

    for (int i = 1; argv[i]; i++) {
        if (argv[i][0] != '-') {
            t_arg *node = mx_node_arg(argv[i], flags);

            if (flag == 0) {
                head = node;
                flag = 1;
            }
            else
                povit->next = node;
            povit = node;
        }
    }
    return head;
}
