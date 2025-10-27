#include <stdio.h>

void binaryRep(unsigned int n){
    // i starts at 31(highest bit)
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
    unsigned int num = 15;
    // Custom Binary Representation
    printf("The binary representation of %u is: ", num);
    binaryRep(num);

    return 0;
}