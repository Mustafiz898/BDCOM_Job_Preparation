#include <stdio.h>

void modify(const int *p) {
    *p = 100; // Q1: Valid? ----------> Invalid, because it assigns in a read only locations
}

int main() {
    int a = 5;
    modify(&a);
    printf("%d\n", a);
}