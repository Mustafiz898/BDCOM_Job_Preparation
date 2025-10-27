#include <stdio.h>

void fun(){
    static int num = 5; // to remember the value of num for every call of the function
    num++;
    printf("The value of num: %d\n", num);
}
int main(){
    
    fun(); // value = 6 
    fun();// value = 7
    fun(); // value = 8
    fun(); // value = 9
    return 0;
}