#include <stdio.h>

int main(){
    int arr[] = {10, 20, 30, 50, 60, 70};
    int *arrPtr[] = {&arr[0], &arr[1], &arr[2], &arr[3], &arr[4], &arr[5]};

    for(int item = 0; item < 6; item++){

        printf("%d", *(arrPtr + item));
        if(item < 5) printf(", ");
    }

    return 0;
}