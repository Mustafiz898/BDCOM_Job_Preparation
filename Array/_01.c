#include <stdio.h>

float calculateAverage(int arr[], int n); // funtion prototype 
int findMax(int arr[], int n);

int main(){
    int array[] = {10,50,40,25,89,4,-2,0,78};
    int size = sizeof(array)/sizeof(array[0]);

    printf("Average: %.2f\n", calculateAverage(array, size));
    printf("Max: %d", findMax(array, size));
    return 0;
}

// Function for calculating Average 
float calculateAverage(int arr[], int n){
    int sum = 0;
    float avg;
    
    for(int item = 0; item < n; item++){
        sum += arr[item];
    }
    avg = (float) sum/n;
    return avg;
}

// Function for Finding Maximum from the array items 
int findMax(int arr[], int n){
    int max = arr[0];
    for(int item = 1; item < n; item++){
        if(max < arr[item]){
            max = arr[item];
        }
    }
    return max;
}