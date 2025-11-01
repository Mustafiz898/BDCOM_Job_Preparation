#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    char *ptr = NULL, *start = NULL; // discarding wild pointer 

    printf("How many value wants to input? ");
    scanf("%d", &n);
    getchar();

    ptr = (char *) malloc((n+1) * sizeof(char));  // allocating memory
    if(ptr == NULL){
        printf("Memory Allocation Failed!");
        return 1;

    } else{
        for(int i=0; i<n; i++){
            scanf(" %c", (ptr+i));
        }
        *(ptr + n) = '\0';  // Making a valid string 
    }

    start = ptr; // keeping the pointer to the starting position 

    // Printing output 
    while(*ptr!='\0'){
        printf("%c", *ptr);
        ptr++;
    }
    printf("\n"); // for clear output 
    free(start); // Finally freeing memory
    start = NULL; // discarding dangling popinter  
    return 0;
}