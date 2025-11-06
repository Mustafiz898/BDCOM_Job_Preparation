#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Main structure 
typedef struct student{
    char * name;
    char * department;
    char * hobby[16];
    char * Unique_id;
}std;

// Prototyping necessary functions
void add_student(std * student, int * n);
// void update_Student_Info(std * student);
void display_student(std * student, int * n);

int main(){
    int choice, no_of_student, current_student = 0;
    int * counter = &current_student;
    no_of_student = 5;

    std student_array[no_of_student];
    std * student = &student_array[0];

    printf("-----------------------Student Information Management System----------------\n");
    printf("---------------------------------Main Menu----------------------------------\n");
    printf("1. Enter Student Information\n");
    printf("2. Update Student Information\n");
    printf("3. Display All Student Information\n");
    printf("\n\n-----------------------------------------------------------------------\n");
    

    while(1){
        printf("\nEnter your choice: ");

        scanf("%d", &choice);
        switch(choice){
            case 1:
                add_student(student, counter);
                break;
            /*case 2: 
                update_Student_Info(student);
                break;*/
            case 3:
                display_student(student, counter);
                break;
            default:
                printf("invalid Choice");
                
        }

    }
    return 0;
}


//------------- FUNCTION FOR ADDING STUDENT---------------------- 
void add_student(struct student * student, int * n){
    printf("------------------Add Student Information--------------------\n");
    printf("-------------------------------------------------------------\n\n");
    int current_student_no;
    int size = 20;

    current_student_no = *n; 

    // Memory allocation 
    (student + current_student_no)->name = calloc(size+1, sizeof(char)); // memory for name 
    (student + current_student_no)->department = calloc(size+1, sizeof(char));// memry for department 
    
    for(int i=0; i<16; i++)
        (student + current_student_no)->hobby[i] = calloc(size+1, sizeof(char)); // memory for hobby

    (student + current_student_no)->Unique_id = calloc(size+1, sizeof(char));// memory for Unique_id


    
    // Memory Allocation Check
    if(!(student + current_student_no)->name || !(student + current_student_no)->department  || ! (student + current_student_no)->Unique_id){
        printf("Memory Allocation Error!");
        exit(1);

    } else{ // memory allocation successful
        int c;
        // Input Name 
        printf("Enter the student name: ");
        while((c = getchar()) != '\n' && c != EOF) {};
        fgets((student + current_student_no)->name, size, stdin);
        (student + current_student_no)->name[strcspn((student + current_student_no)->name, "\n")] = '\0'; // removing trailing new line

        // Input Department 
        printf("Enter Department: ");
        fgets((student + current_student_no)->department, size, stdin);
        (student + current_student_no)->department[strcspn((student + current_student_no)->department, "\n")] = '\0';

        // Input Unique Id
        printf("Enter Unique Id: ");
        fgets((student + current_student_no)->Unique_id, size, stdin);
        (student + current_student_no)->Unique_id[strcspn((student + current_student_no)->Unique_id, "\n")] = '\0';

        // Input Hobby
        int count;
        printf("How many hobbis?(Minimum 2 OR Max 16): ");
        scanf("%d", &count);
        while((c = getchar()) != '\n' && c != EOF) {};

        for(int i=0; i<count; i++){
            printf("Enter your %dth hobby: ", i+1);
            fgets((student + current_student_no)->hobby[i], size, stdin);
            (student + current_student_no)->hobby[i][strcspn((student + current_student_no)->hobby[i], "\n")] = '\0';
        }

        printf("Student Information Successfully Added\n");
        (*n)++;
    }
}

//-------------FUNCTION TO DISPLAY STUDENT------------------

void display_student(std * student, int * n){
    printf(" ID         Name          Department       Hobbies\n");
    for(int i=0; i<*n; i++){
        printf(" %-11s%-14s%-17s", (student+i)->Unique_id,(student+i)->name,(student+i)->department);

        for(int j=0; j<16; j++){
            if ((student+i)->hobby[j] && strlen((student+i)->hobby[j]) > 0) {
                printf("%s", (student+i)->hobby[j]);
                if(j < 15 && (student+i)->hobby[j+1] && strlen((student+i)->hobby[j+1]) > 0)
                    printf(", ");
            }
        }

        printf("\n");

    
    }
}