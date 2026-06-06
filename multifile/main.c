#include <stdio.h>
#include "common.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <name> [values...]\n", argv[0]);
        return 1;
    }

    Record *r = record_create(argv[1]);

    for (int i = 2; i < argc; i++) {
        record_add(r, atoi(argv[i]));
    }

    record_print(r);
    return 0;
}
