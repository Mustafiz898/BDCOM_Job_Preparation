#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file = NULL;
    char *ptr = NULL;

    ptr = malloc(200);
    if (ptr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    file = fopen("random01", "r+");
    if (file == NULL) {
        printf("File not found!\n");
        free(ptr);
        return 1;
    }
    
    fseek(file, 0L, SEEK_END);
    fputs("Cool Down.", file);
    printf("Position: %d\n", ftell(file)); // ftell() is used to findout the current position 


    // rewind(file);  // rewind() is used to move the pointer to the beginning 
    fseek(file, -10,SEEK_END);  // SEEK_END, SEEK_CUR, SEEK_SET
   

    int ch, len = 0;
    while ((ch = fgetc(file)) != EOF) {
        printf("%c", (ptr[len++] = ch));
    }

    ptr[len] = '\0';
    
    // Clear EOF flag before writing
    // clearerr(file);

    

    free(ptr);
    fclose(file);
    return 0;
}
