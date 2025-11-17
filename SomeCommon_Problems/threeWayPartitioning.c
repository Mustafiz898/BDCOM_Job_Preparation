#include <stdio.h>
#include <stdlib.h>

//____________Function___________

void partition(int *arr, int n);
void swap(int *a, int *b);
void print(int *arr, int k);

//________________________________


int main(){
    int array[]={1,0,2,0,1,2,0};                 // 0 = false, 1 = maybe, 2 = true
    int size = sizeof(array)/ sizeof(array[0]);

    //PRINT THE ARRAY BEFORE REARRANGE
    printf("BEFORE: ");
    print(array, size);
    printf("\n\n");

    //REARRANGE THE ARRAY
    partition(array, size);

    //PRINT THE ARRAY AFTER REARRANGE
    printf("AFTER: ");
    print(array, size);
    return 0;
}

//______________Print The Array____________

void print(int *arr, int k){
    int item = 0;
    printf("{");
    while(item < k){
        if(arr[item] == 0) printf("false");
        else if(arr[item]==1) printf("maybe");
        else printf("true");
        // printf("%d", *(arr+item));
        if(item < k-1)
        printf(", ");
        item++;
    }
    printf("}");
}

//____________SWAP The value___________
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

//____________Three Way Partitioning Function___________

void partition(int *arr, int n){
    // 0 = false, 1 = maybe, 2 = true


    int low = 0;                       //Start Boundary----> false
    int mid = 0;                       // Start boundary----> maybe
    int high = n-1;                      // Start boundary----> true

    while(mid <= high){                       
        if(arr[mid] == 0){                 
            swap(&arr[mid], &arr[low]);       // if arr[mid] == false, increse index for mid and low
            mid++;
            low++;
        } else if(arr[mid] == 1){
            mid++;                           // if arr[mid] == maybe
        } else{                             // if arr[mid] == true
            swap(&arr[mid], &arr[high]);
            high--;                           // reduce the high index , not change mid

        }
    }
}