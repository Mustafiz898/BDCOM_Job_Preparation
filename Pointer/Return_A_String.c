#include <stdio.h>
const char * str();
int main(){
    const char *ptr= str();
    // for(int i=0; i<9; i++) printf("%c", *(ptr+i));
    printf("%s\n", ptr);

    /**ptr = 'B';          // Trying to assign value to read-only location 
    printf("%s", ptr);*/
    

    return 0;
}
const char * str(){
    // static char ptr[] = "mustafiz";
    return "Mustafiz";
}