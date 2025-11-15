//_____________TREE______________

/*            10(r1)
             /  \
        (r2)5    15(r5)
           / \   /  
      (r3)3   7 12(r6)  
             (r4) 

output using inorder traversal: 3 5 7 10 12 15
*/               

#include <stdio.h>
#include <stdlib.h>

//_____Declare a Node_________
typedef struct node{
    int data;
    struct node *left, *right;
}node;


// _____________Function__________
node * createNode(int value);
node inorderTraversal(node * root);
//_____________________________________


int main(){
    node * root = NULL;

    // _____Tree creation___
    root = createNode(10);
    // Level 1
    root->left = createNode(5);
    root->right = createNode(15);

    // Level 2
    root->left->left = createNode(3);
    root->left->right = createNode(7);
    root->right->left = createNode(12);

    // Traversing and printing the tree
    inorderTraversal(root);
    printf("\n");


    return 0;
}

//________CREATE NODE_________
node * createNode(int value){
    node * newNode = (node*)malloc(sizeof(node));
    
    // check if the memory allocation is failed?
    if(newNode == NULL){
        printf("Node Creation Falied!\n");
        exit(1);
    }

    // initalize the new node's field
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    // return the address of the newly created node
    return newNode;  
}



//_____________Using Inorder Traversal Print tree____________

node  inorderTraversal(node * root){
    // main concept----- left-> root -> right 
    // base condition-----> traverse untill the root == NULL

    if(root != NULL){
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}