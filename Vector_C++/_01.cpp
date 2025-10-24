#include <iostream>
#include <vector>

using namespace std;

int main(){
    // Vector defination 1
    vector<int> num = {1, 2, 5, 6};
    // cout << num[2] << endl;

    // Vector defination 2
    vector<int> NUM (3, 5);
    cout << "Method 2" << endl;
    for(int i=0; i<3; i++){
        cout << NUM[i] << endl;
    }

    // for each loop
    cout << "For each loop method" << endl;
    for(int i : num){
        cout << i << endl;
    }
    return 0;
}