#include <stdio.h>
#include <stdlib.h>

int subtract(int *x, int *y) {
    int out;
    out = *x - *y;
    return out;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("This program takes 2 arguments! Run it like: %s <some_number> <some_number>\n", argv[0]);
        return 1;
    }
    int x = atoi(argv[1]);
    int y = atoi(argv[2]);
    int z = subtract(&x, &y);
    printf("%d - %d = %d\n", y, x, z);
    return 0;
}
