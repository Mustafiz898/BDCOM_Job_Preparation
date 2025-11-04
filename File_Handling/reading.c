#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE * fptr= NULL;
    // char arr[10];
    char * ptr;
    ptr = (char *)calloc(10, sizeof(char));


    fptr = fopen("random01", "r");
    if(fptr == NULL){
        printf("File not found!");
        exit(1);
    }
    
    while(!feof(fptr)){
        fgets(ptr, 10, fptr);
        printf("%s", ptr);
    }

    free(ptr);
    fclose(fptr);
    return 0;
}