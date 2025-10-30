#include<stdio.h>

int main(){
    int matrix[4][3] = {{10, 50, 70},
                        {65, 15, 25},
                        {89, 56, 78},
                        {45, 62, 18}};


    int (*ptr)[3] = &matrix[0];
    ptr++;
    int sum =0;
    for(int i = 0; i<3; i++){
        sum += *(*(ptr)+i);
    }
    printf("The sum value of 2nd row: %d", sum);
    return 0;
}