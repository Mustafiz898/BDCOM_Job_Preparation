// Given arr[] = {4, 5, 9, 85, 76, -2, 42}...........  Target = -2
// Perform linar search algorithm 

#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int target){
    for(int i=0; i<n; i++){
        if(arr[i] == target) return i; // FOUND VALUE
    }
    return -1; // NOT FOUND 
}

int main(){
    int arr[] = {4, 5, 9, 85, 76, -2, 42};
    int target = -2;
    int size = sizeof(arr)/sizeof(int);
    int index = linearSearch(arr, size, target);

    if(index == -1){
        cout << "Couldn't Find the target number!" << endl;
    } else {
        cout << "The target value -2 is in " << index+1 << "th postion" << endl;
    }

    return 0;
}