#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

unsigned int IPv4_to_Number(const char *ip_str);
char* Number_to_IPv4(unsigned int num);

int main() {
    char input[50];

    printf("Enter IPv4 (A.B.C.D) or 32-bit number: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; // remove newline

    // Check if input is a number or IPv4
    int is_number = 1;
    for(int i=0; input[i]; i++){
        if(!isdigit(input[i])){
            is_number = 0;
            break;
        }
    }

    if(is_number){
        // Input is a number
        unsigned int num = strtoul(input, NULL, 10);
        char *ip = Number_to_IPv4(num);
        printf("IPv4 Address: %s\n", ip);
        free(ip);
    } else {
        // Input is IPv4
        unsigned int num = IPv4_to_Number(input);
        if(num != (unsigned int)-1)
            printf("32-bit Number: %u\n", num);
    }

    return 0;
}

// Convert IPv4 string to 32-bit number
unsigned int IPv4_to_Number(const char *address){
    int Index = 0, dots = 0;
    unsigned int final = 0, num = 0;

    while(address[Index]){
        char ch = address[Index];
        if(ch >= '0' && ch <= '9'){
            num = num * 10 + (ch - '0');
            if(num > 255){
                printf("Invalid IP: octet > 255\n");
                return -1;
            }
        } else if(ch == '.'){
            dots++;
            if(Index==0 || address[Index-1]=='.'){
                printf("Invalid IP: empty octet\n");
                return -1;
            }
            final = (final << 8) | num;
            num = 0;
        } else{
            printf("Invalid IP: invalid character '%c'\n", ch);
            return -1;
        }
        Index++;
    }

    if(address[Index-1]=='.' || dots!=3){
        printf("Invalid IP: must contain 3 dots\n");
        return -1;
    }

    final = (final << 8) | num;
    return final;
}

// Convert 32-bit number to IPv4 string
char* Number_to_IPv4(unsigned int num){
    char *ip = malloc(16);
    if(!ip){
        printf("Memory allocation failed!\n");
        exit(1);
    }
    unsigned int A = (num >> 24) & 0xFF;
    unsigned int B = (num >> 16) & 0xFF;
    unsigned int C = (num >> 8) & 0xFF;
    unsigned int D = num & 0xFF;
    sprintf(ip, "%u.%u.%u.%u", A, B, C, D);
    return ip;
}
