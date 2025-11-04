#include <stdio.h>

int main(){
    FILE * fptr= NULL;
    char arr[10];


    fptr = fopen("random01", "r");
    
    while(!feof(fptr)){
        fgets(arr, 10, fptr);
        printf("%s", arr);
    }
    return 0;
}