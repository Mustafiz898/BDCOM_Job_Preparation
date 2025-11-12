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
void show_menu();
void add_node();
void display();
void add_node_at_beginning();
void add_node_at_specific_position();
void add_node_AFTER_specific_position();
void delete_at_the_beginning();
void delete_node_at_specific_pos();

//---------------------------------------------
int main(){
    int choice;
    node *CRT, *NXT;


    while(1){
        show_menu();
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
            case 3: add_node_at_beginning();
                    break;
            case 4: add_node_at_specific_position();
                    break;
            case 5: add_node_AFTER_specific_position();
                    break;
            case 6: delete_at_the_beginning();
                    break;
            case 7: delete_node_at_specific_pos();
                    break;

            case 8: printf("Exting the program..............\n\n");
                    CRT = head;
                    while(CRT != NULL){
                        NXT = CRT->next;
                        free(CRT);
                        CRT = NXT;
                    }
                    head = NULL;
                    exit(1);

            default: printf("Invalid Choice\n");
                     break;

        }
    }

    return 0;
}

//------------------------Show Menu -------------------------

void show_menu(){
    printf("\n");
    printf("\t\t\t\t\t________MAIN MENU_________\n\n");
    printf("\t\t\t\t\t1.Add Node\n");
    printf("\t\t\t\t\t2.Display the list\n");
    printf("\t\t\t\t\t3.Insert node at the beginning\n");
    printf("\t\t\t\t\t4.Insert node at specific position\n");
    printf("\t\t\t\t\t5.Insert a node AFTER specific position\n");
    printf("\t\t\t\t\t6 Delete node at the beginning\n");
    printf("\t\t\t\t\t7.Delete Node at specific Position\n");
    printf("\t\t\t\t\t8.EXIT\n\n");
}

// ----------------------- ADD NODE -------------------------
void add_node(){
    node * new_Node = (node*)malloc(sizeof(node));
    if(new_Node == NULL){
        printf("\t\t\t\t\tNode creation ERROR!\n");
        return;
    }

    printf("Enter the Data: ");
    if(scanf("%d", &new_Node->data) != 1){
        printf("Opps! Couldn't take Data input...\n");
        free(new_Node);
        return;
    }

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
    printf("\t\t\t\t\t_________Display LIST___________\n\n");
    
    if(head == NULL){                       // If there is no node 
        printf("No List to show!\n");
        return;
    }

    node * temp = head;
    while(temp != NULL){                   // traverse till there's no node left
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

//---------------------------ADD NODE AT THE BEGINNING ----------------------
void add_node_at_beginning(){
    node * newNode = (node*)malloc(sizeof(node));
    if(newNode == NULL){
        printf("Failed to add 1st node!\n");
        return;
    }

    printf("Enter the data: ");
    if(scanf("%d",&newNode->data) != 1){
        printf("failed to take input!\n");
        free(newNode);
        return;
    }
    newNode->next = NULL;
    newNode->prev = NULL;

    if(head == NULL){
        head = newNode;
    } else{
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
    printf("Node added successfully!\n");

}

//--------------------------------INSERT NODE AT SPECIFIC POSITION-------------------

void add_node_at_specific_position(){
    int pos, counter = 0;
    node * temp = head;

    // If there is no node present 
    if(head == NULL){
        printf("There is no list present!\n");
        return;
    }
    // Count the total nodes
    while(temp != NULL){
        counter++;
        temp = temp->next;
    }
    temp = head;


    // Ask for the position from user 
    printf("Enter the position: ");
    if(scanf("%d",&pos) != 1){
        printf("Invalid Position!\n");
        return;
    }

    // If there is only one node
   if(pos ==1){                     
        add_node_at_beginning();
        return;
    }

    if(counter >= pos){                                // CASE 1

        node * newNode = (node*)malloc(sizeof(node));
        if(newNode == NULL){
            printf("Failed to add 1st node!\n");
            return;
        }
    
        printf("Enter the data: ");
        if(scanf("%d",&newNode->data) != 1){
            printf("failed to take input!\n");
            free(newNode);
            return;
        }
        newNode->next = NULL;
        newNode->prev = NULL;


        // If there is more than one node present
        int current = 1;
        while(current < pos-1 ){
            temp = temp->next;
            current++;
        }

        newNode->next = temp->next;
        if(temp->next != NULL){
            temp->next->prev = newNode;
        }
        temp->next = newNode;
        newNode->prev = temp;
    

        printf("Node added successfully\n");
        
    } else{                                                 //CASE 2
        printf("Position is greater than node number\n");
        return;
    }

}    

//-----------------------INSERT A NODE AFTER A SPECIFIC POSITION------------------
void add_node_AFTER_specific_position(){
    int pos, counter = 0;
    node * temp = head;

    // If there is no node present 
    if(head == NULL){
        printf("There is no list present!\n");
        return;
    }
    // Count the total nodes
    while(temp != NULL){
        counter++;
        temp = temp->next;
    }
    temp = head;


    // Ask for the position from user 
    printf("Enter the position: ");
    if(scanf("%d",&pos) != 1){
        printf("Invalid Position!\n");
        return;
    }

    // If there is only one node
   /*if(pos ==1){                     
        add_node_at_beginning();
        return;
    }*/

    if(counter >= pos){                                // CASE 1

        node * newNode = (node*)malloc(sizeof(node));
        if(newNode == NULL){
            printf("Failed to add 1st node!\n");
            return;
        }
    
        printf("Enter the data: ");
        if(scanf("%d",&newNode->data) != 1){
            printf("failed to take input!\n");
            free(newNode);
            return;
        }
        newNode->next = NULL;
        newNode->prev = NULL;


        // If there is more than one node present
        int current = 1;
        while(current < pos){
            temp = temp->next;
            current++;
        }

        newNode->next = temp->next;
        if(temp->next != NULL){
            temp->next->prev = newNode;
        }
        temp->next = newNode;
        newNode->prev = temp;
    

        printf("Node added successfully\n");
        
    } else{                                                 //CASE 2
        printf("Position is greater than node number\n");
        return;
    }

} 

//---------------------------------DELETE NODE AT THE BEGINNING--------------------------
void delete_at_the_beginning(){

    if(head == NULL){
        printf("No node present\n");
        return;
    } else{
        node * temp = head->next;
        free(head);
        head = temp;

        printf("1st node deleted successfully!");
        return;

    }

}

// --------------------------------DELETE NODE AT THE END--------------------------------
void delete_node_at_specific_pos(){
    int pos, counter=0;
    

    printf("Enter the Position of the Node to Delete: ");
    if(scanf("%d", &pos) != 1){                            // In case user input any character instead of integer 
        printf("Invalid Position!");
        return;
    }
    while((null_rmv = getchar()) != '\n' && null_rmv != EOF);

    node * temp = head;
    // Count the number of node
    while(temp != NULL){
        counter++;
        temp = temp->next;
    }

    if(head == NULL){                     // If there is no node present to delete 
        printf("No node present to delete!\n");
        return;
        
    } else if(pos == 1){                // In case there is only one node present
        delete_at_the_beginning();
        return;
    } else{
        temp = head;

        int current = 1;
        while(current < pos){          // Traverse till specific position 
            temp = temp->next;
            current++;
        }
        
        if(temp->next != NULL){          // Condition check if it's not the last node
            temp->next->prev = temp->prev;
        }
        temp->prev->next = temp->next;

        free(temp);
        printf("Specific Node Deleted Successfully\n");
        return;
    }

}