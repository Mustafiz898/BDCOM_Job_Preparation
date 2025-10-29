#include <stdio.h>

extern int myVar; // extern ব্যাবহার করে ভেরিএবল 
extern void Inc(); // extern ব্যাবহার করে ফাংশন 

void display(){
    printf("The value of 'myVar' is: %d\n", myVar);
}

int main(){
    display();
    Inc();
    display();
    return 0;
}