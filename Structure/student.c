#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct student{
    char *name;
    char *course_enrolled[2];
    int roll;
    float CGPA;
}std;

void Search_Student(std *s);
void Add_Student(std *s);

int main(){
    int choice;
    std s[5];
    std *ptr = &s[0];
    // student 01 information
    (ptr+0)->name = "Mustafiz";
    (ptr+0)->course_enrolled[0] = "Math";
    (ptr+0)->course_enrolled[1] = "physics";
    (ptr+0)->roll = 1;
    (ptr+0)->CGPA = 2.64;

    // student 02 information
    (ptr+1)->name = "Jasmin";
    (ptr+1)->course_enrolled[0] = "English";
    (ptr+1)->course_enrolled[1] = "Electronics";
    (ptr+1)->roll = 2;
    (ptr+1)->CGPA = 3.60;



    //************************ */
    printf("1. Search Student\n");
    printf("2. Add Student\n");
    printf("Enter your choice from (1-2): ");
    ;

    if(scanf("%d", &choice) == 1){
        Search_Student(ptr);
    }


    return 0;
}

void Search_Student(std s[]){
    int entered_roll;
    printf("Enter the roll number: ");
    scanf("%d", &entered_roll);

    for(int i = 0; i<5; i++){
        if(entered_roll == (s+i)->roll){
            printf("Name: %s\n", (s+i)->name);
            printf("Enrolled Course: %s, %s\n", (s+i)->course_enrolled[0], (s+i)->course_enrolled[1]);
            printf("Roll: %d\n", (s+i)->roll);
            printf("CGPA: %.2f\n", (s+i)->CGPA);
            break;
        }
    }
};