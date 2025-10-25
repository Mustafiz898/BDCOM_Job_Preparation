#include <stdio.h>
int main() {
unsigned char a = 200, b = 100, c = 0, d = 0;
c = a + b;
d = b - a;
printf("%d, %d, %d, %d.\n", a + b, c, b - a, d);
}
