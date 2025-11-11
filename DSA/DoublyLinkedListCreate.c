#include <stdio.h>
#include <stdlib.h>

int null_rmv;

//----------------------------------------
typedef struct node{
    int data;
    struct node* prev;
    struct node * next;
}node;
node *head = NULL;

//---------------------------------------------
void add_node();
void display();

//---------------------------------------------
int main(){
    int choice;
    node *CRT, *NXT;

    printf("\t\t\t\t\t________MAIN MENU_________\n\n");
    printf("\t\t\t\t\t1.Add Node\n");
    printf("\t\t\t\t\t2.Display the list\n");
    printf("\t\t\t\t\t4.EXIT\n\n");

    while(1){
        printf("\nEnter choice: ");
        if(scanf("%d", &choice) != 1){                  // In case user input character rather than number
            while((null_rmv = getchar()) != '\n' && null_rmv != EOF);
            printf("Invalid Input-----> Try Again! \n");
            continue;
        }


        while((null_rmv = getchar()) != '\n' && null_rmv != EOF);

        switch(choice){
            case 1: add_node();
                    break;
            case 2: display();
                    break;
            case 3: printf("Exting the program..............\n\n");
                    CRT = head;
                    while(CRT != NULL){
                        NXT = CRT->next;
                        free(CRT);
                        CRT = NXT;
                    }
                    exit(1);

            default: printf("Invalid Choice\n");
                     break;

        }
    }

    return 0;
}

// ----------------------- ADD NODE -------------------------
void add_node(){
    node * new_Node = (node*)malloc(sizeof(node));
    if(new_Node == NULL){
        printf("\t\t\t\t\tNode creation ERROR!\n");
        return;
    }

    printf("Enter the Data: ");
    scanf("%d", &new_Node->data);
    new_Node->prev = NULL;
    new_Node->next = NULL;

    
    if(head == NULL){                   // case-1
        head = new_Node;
    } else{                             // case-2
        node * temp = head;
        while(temp->next != NULL){      
            temp = temp->next;         // traverse to the last node
        }

        temp->next = new_Node;
        new_Node->prev = temp;
    }
    printf("\t\t\t\t\tNode Added Successfull!\n");
}

// ---------------------- DISPLAY LIST ------------------------
void display(){
    node * temp = head;
    printf("\t\t\t\t\tRemaining LIST\n");

    if(head == NULL){                       // If there is no node 
        printf("No List to show!\n");
        return;
    }
    while(temp != NULL){                   // traverse till there's no node left
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}