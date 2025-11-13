#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int ch;

typedef struct stackNode{
    int data;
    struct stackNode *link;
}node;

node *TOP = NULL;
//________________________________
void push();
void pop();
void peek();
void display();
void menu_show();
//_____________________________________

int main(){

    int choice;

    while(1){
        menu_show();
        printf("\n\nEnter Your Choice: ");
        if(scanf("%d", &choice) != 1){
            printf("Invalid Choice! try again\n");
            while((ch = getchar()) != '\n' && ch != EOF);
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
                    node * temp = TOP;
                    while(temp != NULL){
                        TOP = temp->link;
                        free(temp);
                        temp = TOP;
                    }
                    TOP = NULL;
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

//_________________Push Data__________________
void push(){
node * newNode = (node*)malloc(sizeof(node));
if(newNode == NULL){
    printf("Falied to create newNode!");
    return;
}

// Insert the data what you want to push
printf("Enter the data you want to Push: ");
if(scanf("%d", &newNode->data) != 1){
    printf("Invalid type data!\n");
    free(newNode);
    return;
}
while((ch= getchar()) != '\n' && ch != EOF);

// Push Logic
newNode->link = TOP;
TOP = newNode;

printf("Data Push Successful!\n");

}


//_________________Pop Data___________________
void pop(){
    if(TOP == NULL){
        printf("No node/ data to pop!\n");
        return;
    } else{
        printf("The data %d is being popped!\n", TOP->data);
        node * temp = TOP;
        TOP = TOP->link;
        free(temp);

    }
}

//_________________Peek Data__________________
void peek(){
    if(TOP == NULL){
        printf("No Data / Node present!");
        return;
    } else{
        printf("The TOP element: %d", TOP->data);
    }
}

//________________Display STACK________________
void display(){
    node * temp = TOP;
    if(TOP == NULL){
        printf("No Data / Node present!");
        return;
    }
    else{
        printf("\n____________DISPLAYED DATA___________\n\n");
        while(temp != NULL){
            printf("[%d] -->", temp->data);
            temp = temp->link;
        }
        printf("NULL\n");
        return;
    }
}