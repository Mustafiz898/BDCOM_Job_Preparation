#include <stdio.h>
#include <stdlib.h>

int ch;

typedef struct node{
    int data;
    struct node * next;
}node;

//-----------------------------------------------
node * add_node();
void display(node **node);

int main(){

    node * newNode = add_node();
    display(&newNode);
    return 0;
}
//---------------------------------------
node * add_node(){

    node * newnode = (node*)malloc(sizeof(node));
    if(newnode == NULL){
        printf("NewNode creation ERROR!");
        exit(1); 
    }
    printf("Enter the Data: ");
    scanf("%d",&newnode->data);

    while((ch = getchar()) != '\n' && ch != EOF);
    newnode->next = NULL;
    printf("New Node added successfully!\n");

/*    if(*head == NULL){
        *head = newnode;
        printf("1st node added successfully!\n");
        return;

    } else{
        node * temp = *head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newnode;
        printf("New node added successfully\n");
        return;
    }*/
    return newnode;
}

//----------------------------

void display(node **ANYnode){
    node * temp = *ANYnode;
    if(temp == NULL){
        printf("No Node to display!\n");
        return;
    }
    printf("Displayed Data: \n");
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
