#include <stdio.h>
#include <string.h>

void subString(char *arr, char *new);

int main(){
    char arr[] = "pwwkew";
    printf("String: %s\n", arr);
    int size = strlen(arr);
    char new[size];
    
    subString(arr, new);
    printf("Sub-String: %s\n", new);
    
    return 0;
}


void subString(char *arr, char *new){

    int len = strlen(arr);
    int left=0, right=0, startIndex = 0, maxLen = 0;
    static char newString[50];
    
    // tracker for all 256 characters to check presence
    int char_map[256] = {0};  // initally no character present
    
    // if there is no character present in the string
    if(arr==NULL){
        printf("No string present!\n");
        return;
    }

    // continue till right index of the string is less than length of the string 
    while(right<len){

        // if the next right character is present in the substring window
        while(char_map[arr[right]] == 1){
            char_map[arr[left]] = 0;   // remove presence    
            left++;               // shrink the window from left till repeating character
        }

        char_map[arr[right]] = 1;
        int current_len = right - left +1;

        if(current_len > maxLen){
           maxLen = current_len;      // update max length
           startIndex = left;         // keep track of the left index for new array
        } 
        right++;   // expand the window to right
    }

    strncpy(new, arr+startIndex, maxLen);
    new[maxLen] = '\0';
}