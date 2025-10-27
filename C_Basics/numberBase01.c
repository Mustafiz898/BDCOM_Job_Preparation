#include <stdio.h>

int main(){
    // Storing values using different base literals 
    int a = 20; // decimal
    int b = 0b0101;// binary
    int c = 05; // Octal
    int d = 0xC; // Hexa decimal

    // Now printing different bases in decimal format    
    printf("For decimal: %d\n",a);
    printf("For Binary: %d\n",b);
    printf("For Octal: %d\n",c);
    printf("For Hex: %d",d);

    return 0;
}