#include <stdio.h>
#include <stdlib.h>

int null_rmv;

typedef struct node{
    int data;
    struct node* link;
}node;
node *head = NULL;

void add_node();
void display();
void reverse_list();



int main(){
    int choice;
    node *CRT, *NXT;

    printf("\t\t\t\t\t________MAIN MENU_________\n\n");
    printf("\t\t\t\t\t1.Add Node / Add at the end \n");
    printf("\t\t\t\t\t2.Display the list\n");
    printf("\t\t\t\t\t3.Reverse the list\n");
    printf("\t\t\t\t\t4.EXIT\n\n");

    while(1){
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        while((null_rmv = getchar()) != '\n' && null_rmv != EOF);

        switch(choice){
            case 1: add_node();
                    break;
            case 2: display();
                    break;
            case 3: reverse_list();
                    break;
            case 4: printf("EXting ..............\n\n");
                    CRT = head;
                    while(CRT != NULL){
                        NXT = CRT->link;
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

//--------------------------

void add_node(){
    node * temp = head;
    node * newNode = (node*)malloc(sizeof(node));

    if(newNode == NULL){
        printf("\t\t\t\t\tNew node creatrion error!\n");
        return;
    }
    printf("Enter the data: ");
    scanf("%d", &newNode->data);
    while((null_rmv = getchar()) != '\n' && null_rmv != EOF);
    newNode->link = NULL;

    if(head == NULL){
        head = newNode;
    } else{
        while(temp->link != NULL){
            temp = temp->link;
        }
        temp->link = newNode;
    }
    printf("\t\t\t\t\tNew Added Successfully!\n");
}

//---------------------------------
void display(){
    node * temp = head;
    if(temp == NULL){
        printf("\t\t\t\t\tThere's no node to show!\n");
        return;
    }
    
    printf("\t\t\t\t\t----Remaining List----\n");
    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

//--------------

void reverse_list(){
    node * prev = NULL;
    node * current = head;
    node * next = head;
    if(head == NULL || head->link == NULL){
        printf("\t\t\t\t\tNot Enough Node to Reverse!\n");
        return;
    }

    while(current != NULL){
        next = next->link;
        current->link = prev;
        prev = current;
        current = next;
    }
    head = prev;
    printf("\t\t\t\t\tList reverse successful!\n");
}