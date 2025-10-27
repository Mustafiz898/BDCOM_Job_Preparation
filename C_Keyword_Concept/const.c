#include <stdio.h>

int main(){
    const int num = 25;

    //num = 20;  // If I do that it will give error as variable of const type is of read only 
    printf("%d", num);

    return 0;
}