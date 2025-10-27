#include <stdio.h>

void binaryRep(unsigned int n){
    // i starts at 31(highest bit)
    printf("Binary: ");
    for(int i = sizeof(n)*8-1; i>=0; i--){
        int bit = (n>>i) & 1;
        printf("%d", bit);

        // Space after every 8 bits 
        if(i%8==0 && i!=0){
            printf(" ");
        }
    }
}

int main(){
    int num;
    unsigned int n;

    printf("Enter Any Number you want to convert: ");
    scanf("%d", &num);

    n = (unsigned int) num;    

    printf("Decimal: %d\n", num);
    printf("Octal: %#o\n", n);
    printf("Hexa-decimal: %#X\n", n);
    binaryRep(n);

    // printf("%d", num);

    return 0;
}