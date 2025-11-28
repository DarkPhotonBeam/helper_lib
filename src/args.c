#include "HelperLib/args.h"
#include <stdlib.h>

int get_arg(const char *key, const char *arg, const char **out_p) {
    size_t i = 0;
    while (i < MAX_ARG_LEN) {
        if (key[i] == '\0') break;
        if (key[i] != arg[i]) return 0;
        i++;
    }
    if (key[i] != '\0') return 0;
    *out_p = arg + i;
    return 1;
}

int get_flag(const char *flag, const char *arg, int *res_p) {
    size_t i = 0;
    while (i < MAX_ARG_LEN) {
        if (flag[i] == '\0') break;
        if (flag[i] != arg[i]) return 0;
        i++;
    }
    if (flag[i] != '\0') return 0;
    if (arg[i] != '\0') return 0;
    *res_p = 1;
    return 1;
}