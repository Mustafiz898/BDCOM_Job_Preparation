#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, c;
    char * first_ptr = NULL,  * second_ptr = NULL; // escaping wild pointer 

    printf("How many character want to input? ");
    if(scanf("%d", &n) != 1 || n <=0){
    printf("invalid size!");
    }

    while((c = getchar()) != '\n' && c != EOF) {}; // flushing any newline from input buffer

    // Allocating Memory Dynamically
    first_ptr = (char *) calloc(n+1, sizeof(char)); 
    if(first_ptr == NULL){
        printf("Memory Allocation Failed");
        return 1;
    } else{
        printf("Enter chracters you want to input: ");

        for(int item = 0; item < n; item++){
            scanf(" %c", first_ptr + item);      // taking chracter as input
        }
        *(first_ptr + n) = '\0';  // making a valid string 
    }
    while((c = getchar()) != '\n' && c != EOF) {};
    printf("Before Reallocation: %s\n", first_ptr); // printing before resizing the memory

    //Reallocting the memory
    int newSize = n+5;
    second_ptr = (char *) realloc(first_ptr, (newSize+1) * sizeof(char));
    if(second_ptr == NULL){
        printf("\nMemory reallocation failed. Original data preserved.");
        free(first_ptr);
        return 1;
    }
    first_ptr = second_ptr;


    printf("Enter chracters you want to add: ");
    for(int item = n; item < newSize; item++){
        scanf(" %c", first_ptr + item);      // Adding character 
    }
    *(first_ptr + newSize) = '\0'; // Making the string valid

    
    printf("After reallocation : %s", first_ptr);
    free(first_ptr);
    first_ptr = NULL;


    return 0;
}