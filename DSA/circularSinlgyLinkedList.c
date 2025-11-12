#include <stdio.h>
#include <stdlib.h>

int null_rmv; // For clearing input buffer

// ------------------------ Node Structure ------------------------
typedef struct node {
    int data;
    struct node *next;
} node;

// ------------------------ Global Pointers ------------------------
node *head = NULL; // First node
node *tail = NULL; // Last node

// ------------------------ Function Prototypes -------------------
void add_node_end();
void add_node_beginning();
void display();

// ------------------------ Main Function ------------------------
int main() {
    int choice;

    printf("\t\t\t________ Circular Singly Linked List ________\n");

    while(1) {
        printf("\nMENU:\n");
        printf("1. Add Node at End\n");
        printf("2. Add Node at Beginning\n");
        printf("3. Display List\n");
        printf("4. Exit\n");

        printf("\nEnter your choice: ");
        if(scanf("%d", &choice) != 1) {
            printf("Invalid Input! Try Again.\n");
            while((null_rmv = getchar()) != '\n' && null_rmv != EOF); // clear input buffer
            continue;
        }

        while((null_rmv = getchar()) != '\n' && null_rmv != EOF); // clear buffer

        switch(choice) {
            case 1: add_node_end(); break;
            case 2: add_node_beginning(); break;
            case 3: display(); break;
            case 4: 
                printf("Exiting...\n");
                // Free all nodes
                if(head != NULL) {
                    node *temp = head;
                    do {
                        node *next = temp->next;
                        free(temp);
                        temp = next;
                    } while(temp != head);
                }
                exit(0);
            default: printf("Invalid Choice! Try again.\n");
        }
    }

    return 0;
}

// ------------------------ Add Node at End ------------------------
void add_node_end() {
    node *newNode = (node*)malloc(sizeof(node));
    if(newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter data: ");
    if(scanf("%d", &newNode->data) != 1) {
        printf("Invalid input!\n");
        free(newNode);
        return;
    }

    newNode->next = NULL;

    if(head == NULL) { // List empty
        head = tail = newNode;
        tail->next = head; // Circular link
    } else {
        tail->next = newNode;
        tail = newNode;
        tail->next = head; // Circular link
    }

    printf("Node added at the end successfully!\n");
}

// ------------------------ Add Node at Beginning ------------------------
void add_node_beginning() {
    node *newNode = (node*)malloc(sizeof(node));
    if(newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter data: ");
    if(scanf("%d", &newNode->data) != 1) {
        printf("Invalid input!\n");
        free(newNode);
        return;
    }

    if(head == NULL) { // List empty
        head = tail = newNode;
        tail->next = head;
    } else {
        newNode->next = head;
        head = newNode;
        tail->next = head; // Maintain circular link
    }

    printf("Node added at the beginning successfully!\n");
}

// ------------------------ Display List ------------------------
void display() {
    if(head == NULL) {
        printf("List is empty!\n");
        return;
    }

    node *temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while(temp != head);

    printf("\n");
}
