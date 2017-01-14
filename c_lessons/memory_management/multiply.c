#include <stdio.h>
#include <stdlib.h>

int *multiply(int *x, int *y, int *z) {
    *z = *x * *y;
    return z;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("This program takes 2 arguments! Run it like: %s <some_number> <some_number>\n", argv[0]);
        return 1;
    }
    int x = atoi(argv[1]);
    int y = atoi(argv[2]);
    int *z;
    z = (int *) malloc(sizeof(int));
    multiply(&x, &y, z);
    printf("The product of %d and %d is %d\n", x, y, *z);
    free(z);
    return 0;
}
