#include <stdio.h>

int main() {
    printf("C Code compiled for:\n");
    
    #if defined(__x86_64__) || defined(_M_X64) || defined(__LP64__)
        printf("Architecture: 64-bit\n");
    #elif defined(__i386__) || defined(_M_IX86) || defined(__ILP32__)
        printf("Architecture: 32-bit\n");
    #else
        printf("Architecture: Unknown/Other\n");
    #endif

    // পয়েন্টারের সাইজ ব্যবহার করেও বোঝা যায় (সাধারণত)
    printf("Pointer Size: %zu bytes (Typically 8 bytes for 64-bit, 4 for 32-bit)\n", sizeof(void*));
    
    return 0;
}