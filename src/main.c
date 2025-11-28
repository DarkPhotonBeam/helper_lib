#include <stdio.h>
#include "HelperLib/args.h"

int main(int argc, char *argv[]) {
    const char *my_arg = "my_default_value";
    const char *other_arg = "other";
    int some_flag = 0;
    int out_flag = 0;
    int in_flag = 0;

    for (size_t i = 1; i < argc; i++) {
        int match = 0;

        match += get_arg("--my-arg=", argv[i], &my_arg);
        match += get_arg("--other-arg=", argv[i], &other_arg);
        match += get_flag("--some-flag", argv[i], &some_flag);
        match += get_flag("-o", argv[i], &out_flag);
        match += get_flag("-i", argv[i], &in_flag);

        if (match) continue;

        if (out_flag) {
            printf("out arg -> %s\n", argv[i]);
            out_flag = 0;
        } else if (in_flag) {
            printf("in arg -> %s\n", argv[i]);
            in_flag = 0;
        } else {
            printf("raw arg -> %s\n", argv[i]);
        }
    }

    printf("my_arg -> %s\n", my_arg);
    printf("other_arg -> %s\n", other_arg);
    printf("some_flag -> %d\n", some_flag);
    return 0;
}