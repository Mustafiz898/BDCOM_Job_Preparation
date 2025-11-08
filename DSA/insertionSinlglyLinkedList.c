#include <stdio.h>
#include <stdlib.h>

//_____________ Declaring node type_________ 
typedef struct node{
    int data;
    struct node * next;
}node;

struct node * Head = NULL;

enum number{a=1,b,c,d,e}; // Use of enum for handling invalid choice in the main function

//_____________Function Prototyping__________
void add_Node_End();
void add_beginning();
void add_At_Spec_Pos();
void Display();


//______________Main Function___________
int main(){
    int choice;
    node * current, *NXT;

    printf("________MAIN MENU_________\n\n");
    printf("1.Add Node / Add at the end \n");
    printf("2.Add at the beginning\n");
    printf("3.At Specific Position\n");
    printf("4.Display\n");
    printf("5.Exit\n");
    

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
                add_Node_End();
                break;
            case b:
                add_beginning();
                break;
            case c:
                add_At_Spec_Pos();
                break;
            case d:
                Display();
                break;
            case e:   
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

//__________________Add New Node Or Insert Node at the End________________

void add_Node_End(){
    int ch;
    node * temp;
    temp = Head;

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
        while(temp->next != NULL){
            temp = temp->next;

        }
        temp->next = new_Node;
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
    int ch;

    node *s_Node = (node*) malloc(sizeof(node));
    if(s_Node == NULL){
        printf("Start Node Creation Error!\n");
        exit(1);
    }

    printf("Enter the data: ");
    scanf("%d", &s_Node->data);
    while((ch = getchar())!= '\n' && ch != EOF);
    
    // 
    s_Node->next = Head;
    Head = s_Node;

    printf("\nNode added Successfully!\n");
}

//____________________Insert Node After Any Position_______________
void add_At_Spec_Pos(){
    unsigned int pos, counter = 1;
    node * temp, *n_Node;
    temp = Head;

    printf("Enter the position for New Node: ");
    scanf("%d", &pos);

    if(Head == NULL){
        printf("No Node Present!\n");
        return;
    }

    while(temp->next != NULL){
        counter++;
        temp = temp->next;
    }

    if(counter > pos-1 && pos>1){
        temp = Head;
        for(int i=1; i< (pos-1); i++){
            temp = temp->next;
        }

        n_Node = (node*) malloc(sizeof(node));
        if(n_Node == NULL){
            printf("n_Node Error!\n");
            exit(1);
        }

        printf("Enter the data for n_Node: ");
        scanf("%d", &n_Node->data);
        while(getchar() != '\n' && getchar() != EOF);

        n_Node->next = temp->next;
        temp->next = n_Node;

        printf("New Node at %dth Position added Successfully!\n", pos);

    } else if(pos == 1){
        add_beginning();

    }else{
        printf("Invalid  Position!\n");
        return;
    }

}