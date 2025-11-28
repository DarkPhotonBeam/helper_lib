#ifndef ARGS_H
#define ARGS_H

#ifndef MAX_ARG_LEN
#define MAX_ARG_LEN 256
#endif

int get_arg(const char *key, const char *arg, const char **out_p);

int get_flag(const char *flag, const char *arg, int *res_p);

#endif