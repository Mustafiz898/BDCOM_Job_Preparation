// Task: Reverse the given array, but don't create the copy of the array
// change the original array
// 2 Pointer approach

#include <iostream>
using namespace std;

void reverseArray(int arr[], int size){
    int temp;
    for(int i=0; i<size/2; i++){
        temp = arr[i];
        arr[i] = arr[size-i-1];
        arr[size - i-1] = temp;
    }
}

int main(){
    int num[] = {5,6,7,8,9,10,11,12,13};
    int size = sizeof(num)/sizeof(int);
    reverseArray(num, size);

    // After Reversing the Array
    for(int i=0; i < size; i++){
        cout << num[i] << " ";
    }

    return 0;
}