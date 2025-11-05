#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE * fptr= NULL;
    // char arr[10];
    char * ptr;

    
    ptr = (char *)calloc(10, sizeof(char));
    if(ptr == NULL){
        printf("Memory allocation Failed");
        return 1;
    }


    fptr = fopen("random01", "r");
    if(fptr == NULL){
        printf("File not found!");
        exit(1);
    }
    
   /* while(!feof(fptr)){
        fgets(ptr, 10, fptr);
        printf("%s", ptr);
    }*/

    while(fgets(ptr, 10, fptr) != NULL){
        printf("%s", ptr);
    }

    free(ptr);
    fclose(fptr);
    return 0;
}