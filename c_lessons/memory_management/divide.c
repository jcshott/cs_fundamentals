#include <stdio.h>
#include <stdlib.h>

double divide(int *x, int *y) {
    double z;
    printf("pointer to z in divide: %p\n", &z);
    z = (double)*x / *y;
    return z;
}


int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("This program takes 2 arguments! Run it like: %s <some_number> <some_number>\n", argv[0]);
        return 1;
    }
    int x = atoi(argv[1]);
    int y = atoi(argv[2]);
    double z = divide(&x, &y);
    printf("pointer to z in main %p\n", &z);
    printf("%d divided by %d equals %f\n", x, y, z);
    return 0;
}
