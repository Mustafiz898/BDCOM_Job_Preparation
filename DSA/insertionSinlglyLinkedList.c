#include <stdio.h>
#include <stdlib.h>

//_____________ Declaring node type_________ 
typedef struct node{
    int data;
    struct node * next;
}node;

struct node * Head = NULL, *temp = NULL;

enum number{a=1,b,c,d,e,f}; // Use of enum for handling invalid choice in the main function

//_____________Function Prototyping__________
void add_Node();
void add_beginning();
// void add_end();
// void add_At_Spec_Pos();
void Display();


//______________Main Function___________
int main(){
    int choice;
    node * current, *NXT;

    printf("________MAIN MENU_________\n\n");
    printf("1.Add Node\n");
    printf("2.Add at the beginning\n");
    printf("3.Add at the end\n");
    printf("4.After Specific Position\n");
    printf("5.Display\n");
    printf("6.Exit\n");
    

    while(1){
        // Enter Choice
        printf("\nEnter your choice: ");
        if(scanf("%d", &choice) != 1){                  // In case user input character rather than number
            while((getchar() != '\n' && !feof(stdin)));
            printf("Invalid Input-----> Try Again! \n");
            continue;
        }

        enum number ch = (enum number) choice;  // In case, if user input any invalid number except menu number

        switch(ch){
            case a:
                add_Node();
                break;
            case b:
                add_beginning();
                break;
            /*case c:
                add_end();
                break;
            case d:
                add_At_Spec_Pos();*/
            case e:
                Display();
                break;
            case f:
                
                current = Head;
                while(current != NULL){
                    NXT = current->next;
                    free(current);
                    current = NXT;
                }
                exit(0);
            default:
                printf("Invalid input!\n");
                break;
        }
    }

    return 0;
}

//__________________Add New Node________________

void add_Node(){
    int ch;
    node * new_Node = (node*) malloc(sizeof(node));
    if(new_Node == NULL){
        printf("New Node Creation Error!!");
        return;
    }

    printf("Enter the Data(Any int NUMBER): ");
    scanf("%d", &new_Node->data);
    while((ch = getchar()) != '\n' && ch != EOF);
    new_Node->next = NULL;

    if(Head == NULL){
        Head = temp = new_Node;
    } else{
        temp->next = new_Node;
        temp = new_Node;
    }
}

//___________________Display Linked List_____________

void Display(){
    node * temp1;
    temp1 = Head;

    while(temp1 != NULL){
        printf("%d ", temp1->data);
        temp1 = temp1->next;
    }
    printf("\n");
}

//__________________Insertion at beginning________________

void add_beginning(){
    node * temp1;
    temp1 = Head;

    node *s_Node = (node*) malloc(sizeof(node));
    if(s_Node == NULL){
        printf("Start Node Creation Error!\n");
        exit(1);
    }

    printf("Enter the data: ");
    scanf("%d", &s_Node->data);
    while(getchar()!= '\n' && getchar() != EOF);
    

    s_Node->next = temp1;
    Head = s_Node;

    printf("\nNode added Successfully!\n");
}