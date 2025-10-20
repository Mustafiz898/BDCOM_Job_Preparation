#include <iostream>
#include <climits>
using namespace std;

int main(){
    int arr[] = {45, -5, 8, 100, 566, -2, 500};
    int size = sizeof(arr)/sizeof(int);

    // use of constant as starting point 
    int minVal = INT_MAX;
    int maxVal = INT_MIN;
    int m, n;

    for(int i=0; i<size; i++){
        // Using min() and max() function
        minVal = min(arr[i], minVal);
        if(minVal == arr[i]) m=i;
        maxVal = max(arr[i], maxVal);
        if(maxVal == arr[i]) n = i;
    }

    cout << "Max = " << maxVal << ", index = " << n <<  endl;
    cout << "Min = " << minVal << ", index = " << m << endl;

    return 0;
}