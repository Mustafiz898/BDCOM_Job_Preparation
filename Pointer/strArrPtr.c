#include <stdio.h>

// Function to calculate string length
int strLen(char arr[]){
    int count = 0;
    while(arr[count] != '\0'){
        count++;
    }
    return count;
}

// Function to copy string into another Array variable
void strCopy(char *arr, char *dest){
    int i = 0;
    while(arr[i] != '\0'){
        dest[i] = arr[i];
        i++;
    }
    dest[i] = '\0';
}

int main(){
    char source_str[] = "BDCOM Job Preparation";
    char dest_array[100];

    
    int len = strLen(source_str); // string length
    printf("Length of the string: %d\n", len);

    strCopy(source_str, dest_array); // string copy
    for(int i=0; i<len; i++){
        printf("%c", dest_array[i]);
    }

    return 0;
}