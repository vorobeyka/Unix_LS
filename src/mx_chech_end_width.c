#include "header.h"

bool mx_chech_end_width(t_all_nes *t, int pos, int j) {
    if ((t->tabs != 0
        && pos == (t->col / t->tabs) * t->tabs)
        || j == t->count - 1) {
        return true;
    }
    else
        return false;
}
