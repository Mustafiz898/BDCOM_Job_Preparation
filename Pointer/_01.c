#include <stdio.h>

int main(){
    int num = 5;
    int *ptr1 = &num;

    int *ptr2 = ptr1; // assigning of address of the 'num' in ptr2

    

    printf("The value of num before modification: %d\n", num);
    *ptr2 = 20;
    printf("The value of num after modification: %d\n", num);
    printf("The address of num in ptr1: %p\n", ptr1);
    printf("The address of num in ptr2: %p\n", ptr2);
    printf("The address of num in num: %p\n", &num);
    printf("The own address of ptr2: %p\n", &ptr2);


    return 0;
}