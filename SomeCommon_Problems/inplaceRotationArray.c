#include <stdio.h>

void printArray(int *arr, int n);
void rotateOneLeft(int *arr, int n);
void rotate_K_times(int *arr, int n, int k);



//-------------------------------------
int main(){
    int k;
    int array[] = {1, 2, 3, 4, 5, 6};
    int size = sizeof(array)/sizeof(array[0]);

    printf("before rotation: ");
    printArray(array, size);
    printf("\n");

    /*rotateOneLeft(array, size);
    printArray(array, size);
    printf("\n");
    rotateOneLeft(array, size);
    printArray(array, size);*/

    printf("Enter how many times you want to rotate: ");
    scanf("%d", &k);
    rotate_K_times(array, size, k);
    printArray(array, size);
    printf("\n");

    return 0;
}

//______________print array___________
void printArray(int *arr, int n){
    for(int item = 0; item<n; item++){
        printf("%d ", *(arr+item));
    }
}

//___________Rotate one times_________
void rotateOneLeft(int *arr, int n){
    int temp = arr[0];
    for(int item = 0; item < n-1; item++){
        *(arr+item) = *(arr+item+1);
    }
    *(arr+n-1) = temp;
}

//___________Rotate K times________
void rotate_K_times(int *arr, int n, int k){
    k = k % n;

    for(int item = 0; item < k; item++){
        rotateOneLeft(arr, n);
    }
}
