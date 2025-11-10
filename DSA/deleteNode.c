#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node * next;
}node;

struct node *head = NULL;
//--------------------------------------------------------
void add_node();
void display();
void delete_at_start();
void delete_at_end();
void delete_at_specific();
//---------------------------------------------------------
typedef enum num{add_Node=1,
                 Display, 
                 Delete_at_start,
                 Delete_at_end, 
                 Delete_at_specific,
                 Exit
                }number;
//---------------------------------------------------------

int main(){

    int choice, ch;
    node *CRT, *NXT;

    printf("----------------------Main Menu______________\n");
    printf("1. Add Node.\n");
    printf("2. Display\n");
    printf("3. DELETE from the Beginning Position\n");
    printf("4. DELETE at the END\n");
    printf("5. DELETE at Specific Position\n");
    printf("6. EXIT\n\n");

    while(1){
        printf("\nEnter Your Choice: ");
        if(scanf("%d", &choice) !=1){
            printf("Invalid Choice!\n");
            while((ch = getchar()) != '\n' && ch != EOF);
            continue;
        }
        
        number select = (number) choice;

        switch(select){

            case add_Node:
                add_node();
                break;
            case Display:
                display();
                break;
            case Delete_at_start:
                delete_at_start();
                break;
            case Delete_at_end:
                delete_at_end();
                break;
            case Delete_at_specific:
                delete_at_specific();
                break;

            case Exit:
                printf("Exiting the Program................\n\n");
                CRT = head;
                while(CRT != NULL){
                    NXT = CRT->next;
                    free(CRT);
                    CRT = NXT;
                }
                head = NULL;
                exit(0);

            default:
                printf("Invalid Choice!\n");
                break;

        }
    }

    return 0;
}

//-------------------------------------------------------------
void add_node(){
    int ch;
    node * temp;
    temp = head;

    node * new_Node = (node*) malloc(sizeof(node));
    if(new_Node == NULL){
        printf("New Node Creation Error!!");
        return;
    }

    printf("Enter the Data(Any int NUMBER): ");
    scanf("%d", &new_Node->data);
    while((ch = getchar()) != '\n' && ch != EOF);
    new_Node->next = NULL;

    if(head == NULL){
        head = temp = new_Node;
    } else{
        while(temp->next != NULL){
            temp = temp->next;

        }
        temp->next = new_Node;
    }
}

//---------------------------------------------------------------
void display(){
    node * temp1;
    temp1 = head;

    while(temp1 != NULL){
        printf("%d ", temp1->data);
        temp1 = temp1->next;
    }

    if(head == NULL){
        printf("List is Enpty!\n");
        return;
    }
    printf("\n");
}

//----------------------------------------------------------------

void delete_at_start(){
    node *temp;
    temp = head;
  
    if(head == NULL){
        printf("No node to delete!\n");
        return;
    }
    temp = temp->next;
    free(head);
    head = temp;
    printf("Successfully Deleted 1st node!\n");
}

//---------------------------------------------------------------

void delete_at_end(){
    node * temp;
    temp = head;

    // case 1
    if(head == NULL){
        printf("No Node to delete!\n");
        return;
    }
    //case 2
    else if(head->next == NULL){
        free(head);
        head = NULL;
        printf("Deletion at the end Successful!\n");
        return;
    }

    while(temp->next->next != NULL){
        temp = temp->next;
    }
    node * last_node = temp->next;
    free(last_node);
    temp->next = NULL;

    printf("Deletion at the end Successful!\n");
}
//-----------------------------------------------------------------

void delete_at_specific(){
    node * temp;
    temp = head;
    int pos, ch;

    printf("Enter the Position of the NOde: ");
    scanf("%d", &pos);
    while((ch = getchar()) != '\n' && ch != EOF);

    if(pos == 1){
        delete_at_start();
        return;
    }

    if(head == NULL){
        printf("\nNo node to delete!\n");
        return;
    } else if(head->next == NULL){
        free(head);
        head = NULL;
        printf("\nNode deleted successfully!\n");
    } else{
        int i = 1;
        while(i < pos-1){
            temp = temp->next;
            i++;
        }
        node * current_node = temp->next;
        temp->next = current_node->next;
        free(current_node);
        current_node = NULL;

        printf("Node deleted successfully!\n");

        return;
    }
}