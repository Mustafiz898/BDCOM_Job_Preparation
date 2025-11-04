#include <stdio.h>

int main(){
    FILE *fptr = NULL;
    char arr[50] = "Tumi Ekta Baccha. Tai beshi valo lage.";
    int x = 143;

    // File creation
    fptr = fopen("random01", "w");
    if(fptr == NULL) return 1;

    fputs("Hello, Jasmin Madam!\n", fptr);
    fputs("I love u so much madam.\n", fptr);
    fprintf(fptr,"%s %d", arr, x);

    // File closing must 
    fclose(fptr);
    return 0;
}