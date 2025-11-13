#include <stdio.h>
#include <stdlib.h>

// Node for singly linked list
typedef struct node{
    int data;
    struct node * next;

}node;

struct node * Head = NULL, *new_node=NULL, *temp =NULL;

int main(){
    int choice;

    while(1){
    printf("Do you want to create a node?\nEnter 0 or 1: ");
    scanf("%d", &choice);
    if(choice == 0)
        break;
    
    new_node = (node*) malloc(sizeof(node)); // Allocating memory for the new node

    // Input data and address of the next node
    printf("Enter the Data: ");
    scanf("%d", &new_node->data);
    new_node->next = NULL;


    if(Head == NULL){    // if there is only one node
        Head = temp = new_node;
    } else{                // else insert the address of new_node to previous node
        temp->next = new_node;
        temp = new_node;
    }

    }

    temp = Head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }

    free(new_node);
    new_node = NULL;
    return 0;
}