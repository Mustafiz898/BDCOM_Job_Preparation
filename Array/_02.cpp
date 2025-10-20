#include <iostream>
using namespace std;

int main(){
    int num[] = {45, 56, 12, 67, 90, 6, 3, 102, 56};
    int size = sizeof(num)/ sizeof(int);
    int max, min;
    max = min = num[0];
    
    // Loop for checking max and min
    for(int i=1; i<size; i++){
        if(max < num[i]){
            max = num[i];
        }
        if(min > num[i]){
            min = num[i];
        }
    }

    // Max and Min Print
    cout << "Max: " << max << endl;
    cout << "Min: " << min << endl;
    return 0;
}