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
    
    file = fopen("random01", "a+"); // Append mode 
    if (file == NULL) {
        printf("File not found!\n");
        free(ptr);
        return 1;
    }
    
    // fseek(file, 0L, SEEK_END);
    fputs("Cool Down. ", file);


    rewind(file);
   

    int ch, len = 0;
    while ((ch = fgetc(file)) != EOF) {
        printf("%c", (ptr[len++] = ch));
    }

    ptr[len] = '\0';

    free(ptr);
    fclose(file);
    return 0;
}
