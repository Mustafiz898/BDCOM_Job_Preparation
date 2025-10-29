#include <stdio.h>

int main(){
    char *name[] = {"Mustafiz", "Jasmin", "Shuvo", "Jannat"}; // array of pointers 
    // Suppose I want to access 'f' from the string 'Mujstafiz'

    printf("%c", name[0][5]);
    
    return 0;

}