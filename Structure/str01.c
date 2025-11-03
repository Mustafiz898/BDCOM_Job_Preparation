#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma pack(1)  // Structure packing 

struct student{
    char *name;
    float age;
    int id;
}s1,s2;

int main(){
    char * Name = "Mustafizur";
    s1.name = (char *)malloc(strlen(Name) + 1);
    if(s1.name == NULL){
        return 1;
    }
    strcpy(s1.name, Name);
    s1.age = 25.9;
    s1.id = 101;

    struct student s2 = {"Shuvo", 26.5, 102};


    printf("Name: %s\n", s1.name);
    printf("Age: %.2f\n", s1.age);
    printf("Id: %d\n", s1.id);

    printf("Name: %s\n", s2.name);
    printf("Age: %.2f\n", s2.age);
    printf("Id: %d\n", s2.id);

    struct student *ptr = &s2;

    printf("age of s2 is %f\n", ptr->age);

    printf("The size of S2 is: %d Byte", sizeof(s2));

    free(s1.name);
    return 0;
}