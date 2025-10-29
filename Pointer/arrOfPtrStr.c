#include<stdio.h>
// int arrLen(char * arr){
//     int len = 0;
//     for(int item =0; item < 4; item++){

//     }
// }
int main(){
    char *name[] = {"Mustafiz", "Jasmin", "Shuvo", "Jannat"}; // array of pointers 
    int size = sizeof(name) / sizeof(name[0]);

    // printf("I want to access 'f' from 'Mustafiz' : %c\n", *(*(name)+5));
    // printf("I want to access 's' from 'Jasmin' : %c\n", *(*(name+1)+2));
    // printf("I want to access 'a' from 'Jannat' : %c", *(*(name+3)+1));
    for(int item = 0; item < size; item++){
        printf("'%c'", *(*(name+item)+2));
        if(item < size-1) printf(", ");
    }

    return 0;
}