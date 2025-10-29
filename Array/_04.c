#include <stdio.h>

int main(){

    int array[] = {5, 56, 89, 45, 0, 6, -1, 98, 74};
    int size = sizeof(array)/sizeof(array[0]);

    printf("[");
    for(int item =0; item < size; item++){
        printf("%d", array[item]);
        if(item < size -1) printf(", ");
    }

    printf("]\n");

    return 0;
}