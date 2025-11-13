#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX_SIZE 5

int my_STACK[MAX_SIZE];
int TOP = -1;

//________________________________
bool is_empty();
bool is_full();
void push();
void pop();
void peek();
void display();
void menu_show();
//_____________________________________

int main(){

    int choice, ch;

    while(1){
        menu_show();
        printf("\n\nEnter Your Choice: ");
        if(scanf("%d", &choice) != 1){
            printf("Invalid Choice! try again\n");
            continue;
        }
        while((ch = getchar()) != '\n' && ch != EOF);

        switch(choice){
            case 1: push();
                    break;
            case 2: pop();
                    break;
            case 3: peek();
                    break;
            case 4: display();
                    break;
            case 5: printf("Exiting the program......\n");
                    exit(0);
            
            default: 
                    printf("Invalid choice! try again");
                    break;
        }
    }

    return 0;
}
//___________________Main Menu_________________
void menu_show(){
    printf("\n______Main Menu______\n\n");
    printf("1. Push Data\n");
    printf("2. Pop Data\n");
    printf("3. Peek Data\n");
    printf("4. Display Stack\n");
    printf("5. Terminate Program!!\n\n");
}
//___________________Is Empty__________________
bool is_empty(){
    if(TOP == -1){           // Underflow check
        return true;
    } else{
        return false;
    }
}

//___________________Is FULL__________________
bool is_full(){
    if(TOP == MAX_SIZE -1){         // Overflow check
        return true;
    } else{
        return false;
    }
}

//_________________Push Data__________________
void push(){
    int data;
    printf("Enter the Data want to Push: ");
    scanf("%d", &data);

    if(is_full()){
        printf("Stack is FULL!\n");
        return;
    } else{
        TOP++;
        my_STACK[TOP] = data;
        printf("Data is pushed successfully!\n");
    }
}
//_________________Pop Data___________________
void pop(){
    if(is_empty()){
        printf("Stack is empty!\n");
        return;
    } else{
        printf("Data %d is poped successfully!\n", my_STACK[TOP]);
        TOP--;
    }
}
//_________________Peek Data__________________
void peek(){
    if(is_empty()){
        printf("Stack is Empty!\n");
        return;
    } else{
        printf("Top Element: %d\n", my_STACK[TOP]);
    }

}

//________________Display STACK________________
void display(){
    if(is_empty()){
        printf("No element present in the stack to DISPLAY!\n");
        return;
    } else{
        printf("Stack Element: ");
        for(int i = TOP; i>=0; i--){
            printf("%d ", my_STACK[i]);
        }
        printf("\n");
    }
}