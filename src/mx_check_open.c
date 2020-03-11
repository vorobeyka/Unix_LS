#include "header.h"

bool mx_check_open(char *full_name) {
    DIR *dir;
    
    dir = opendir(full_name);
    if (dir == NULL)
        return false;
    else {
        closedir(dir);
        return true;
    }
}
