#include <stdio.h>
#include <stdlib.h>


int main(){
    FILE * file = NULL;

    // Reading file 
    file = fopen("random01", "r");
    if(file == NULL){
        printf("file not found!"); // By any chance if file is not found
        exit(1);
    }

    char * buffer = NULL;
    size_t capacity = 128, len = 0;

    buffer = calloc(capacity, sizeof(char)); // allocating memory dynamically to store data from file
    if(buffer == NULL){
        printf("Memory allocation failed!");
        fclose(file);
        exit(1);
    }

    int ch;
    while((ch = fgetc(file)) != EOF){
        if(len+1 >= capacity){
            capacity *= 2;  // if buffer gets full, double it's capacity

            char *temp = realloc(buffer, capacity * sizeof(char)); // reallocating memory 
            if(temp == NULL){
                printf("reallocation failed!");
                free(buffer);
                fclose(file);
                exit(1);
            }
            buffer = temp;
        }
        buffer[len++] = ch; // implicit typecasting from ASCII  to character value 
    }
    buffer[len] = '\0'; // Making all data to a valid string 

    printf("File Content: \n%s\n", buffer);

    free(buffer);
    buffer = NULL;
    fclose(file);

    return 0;
}