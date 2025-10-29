#include <stdio.h>

int main(){
    int num;
    int *ptr = &num;

    *ptr = 50;
    // printf("size of int: %zu", sizeof(char *));

    // using direct value 
    printf("The value of 'num' is : %d\n", num);
    printf("The address of 'num' is : %p\n", &num);

    // Using pointer 
    printf("The value of 'num' is : %d\n", *ptr);
    printf("The address of 'num' is : %p", ptr);
    return 0;
}