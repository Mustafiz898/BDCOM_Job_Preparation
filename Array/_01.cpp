#include <iostream>
using namespace std;

int main(){
    int marks[] = {12, 14, 16, 18};
    double age[5];
    
    // Just practicing array input and output and loops
    for(int i=0; i<4; i++){
        cout << marks[i] << endl; 
    }
    cout << "Enter the age of different People:" << endl;
    for(int i=0; i<5; i++){
        cin >> age[i];
    }
    
    cout << "These are the age of 5 different People:" << endl;
    for(int i=0; i<5; i++){
        cout << age[i] << endl; 
        
    }
    return 0;
}