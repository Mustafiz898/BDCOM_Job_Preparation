#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ---------Declaring Node ----------------------
typedef struct node{
    char *name;
    struct node * next;
}node;
struct node *Head = NULL, *temp = NULL;

//---------- Function To Add, display node ------
void addNode();
void display(node * n);

// -----------------------------------------------
int main(){
    int choice, Data;

    while(1){
        printf("Enter(1/0): add node--> 1 | display --> 0:   ");  // Giving a choice to add or display node 
        scanf("%d", &choice);
        int c;
        while((c = getchar()) != '\n' && c != EOF);

        if(choice == 1){
            addNode(); // Add a new node
        } else{
            display(Head); // Display The Linked List 
            break;
        }
    }
    node *current = Head;
    node *next;
    while (current != NULL) {
        next = current->next;
        free(current->name); 
        free(current);
        current = next;
    }

    return 0;
}

// ________________ ADD NODE____________

void addNode(){
    char name[30];
    node *newNode = NULL;

    printf("Enter the Data (Name): ");
    fgets(name, 30, stdin);
    name[strcspn(name, "\n")] = '\0';

    
    size_t len = strlen(name);

    if(len == 0 && len > 30){
        printf("Return Valid Input!");
        return;
    }

    newNode = (node*) malloc(sizeof(node));
    if(newNode == NULL){
        printf("Error!!");
        exit(1);
    }
    
    newNode->name = malloc(len+1);
    if(newNode->name == NULL){
        printf("Name input ERROR!");
        free(newNode);
        exit(1);
    } else{
        strcpy(newNode->name, name);
    }

    
    newNode->next = NULL;

    if(Head == NULL){
        Head = temp = newNode;
    } else{
        temp->next = newNode;
        temp = newNode;
    }

}

//________________DISPLAY NODE__________________

void display(node * head){
    temp = head;
    while(temp != NULL){
        printf("%s ", temp->name);
        temp = temp->next;
    }
}