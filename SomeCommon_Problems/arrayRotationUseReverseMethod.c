#include <stdio.h>

void reverseArray(int *arr, int first, int last){
    
    while(first<last){
        int temp = arr[first];
        arr[first] = arr[last];
        arr[last] =  temp;

        first++;
        last--;
    }

}

void printArray(int *arr, int n){
    for(int item = 0; item<n; item++){
        printf("%d ", *(arr+item));
    }
}

void rotate_K_position(int *arr, int n, int k){
    k = k % n;
    reverseArray(arr, 0, k-1);
    reverseArray(arr, k, n-1);
    reverseArray(arr, 0, n-1);
}

int main(){
    int k;
    int array[] = {1, 2, 3, 4, 5, 6};
    int size = sizeof(array)/sizeof(array[0]);

    // Print before rotation
    printArray(array, size);
    printf("\n");
    
    printf("Enter how many times you want to rotate: ");
    scanf("%d", &k);
    
    rotate_K_position(array, size, k);
    printArray(array, size);
    printf("\n");

    return 0;
}