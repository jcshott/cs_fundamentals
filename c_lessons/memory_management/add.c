#include <stdio.h>
#include <stdlib.h>

void add(int *x, int *y, int *z) {
    *z = *x + *y;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("This program takes 2 arguments! Run it like: %s <some_number> <some_number>\n", argv[0]);
        return 1;
    }
    int x = atoi(argv[1]);
    int y = atoi(argv[2]);
    int z;
    add(&x, &y, &z);
    printf("The sum of %d + %d is %d\n", x, y, z);
    return 0;
}
