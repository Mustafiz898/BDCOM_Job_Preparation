#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE * file = NULL;

    file = fopen("random01", "a");
    fprintf(file, "\nWhere are you Jasmin! I need you.");
    return 0;
}