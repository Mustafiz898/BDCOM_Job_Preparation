#include <stdio.h>

int main(){
    int matrix[4][3] = {{10, 50, 70},
                        {65, 15, 25},
                        {89, 56, 78},
                        {45, 62, 18}};

    int (*ptr)[3] = matrix;     // pointer to array
    for(int i=0; i<4; i++){     // i indicates row (outer loop) 
        for(int j=0; j<3; j++){  // j indicates column (inner loop)
            printf("%d", *(*(ptr+i)+j)); //accessing every element 
            if(j<2) printf(", ");
            if(j==2) printf("\n");
        }         
    }
    printf("\n");             
    
    return 0;
}