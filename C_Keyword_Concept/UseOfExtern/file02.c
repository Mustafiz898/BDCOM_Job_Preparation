#include <stdio.h>

extern int myVar;
extern void Inc();

void display(){
    printf("The value of 'myVar' is: %d\n", myVar);
}

int main(){
    display();
    Inc();
    display();
    return 0;
}