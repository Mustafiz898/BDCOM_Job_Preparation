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
node * insertNode(node *root, int value);
node inorderTraversal(node * root);
node preorderTraversal(node *root);
node postorderTraversal(node *root);
//_____________________________________


int main(){
    node * root = NULL;

    // _____Tree creation___
    root = insertNode(root, 10);
    root = insertNode(root, 5);
    root = insertNode(root, 3);
    root = insertNode(root, 7);
    root = insertNode(root, 15);
    root = insertNode(root, 12);
    // Traversing and printing the tree
    printf("Inorder: ");
    inorderTraversal(root);
    printf("\n");
    printf("Preorder: ");
    preorderTraversal(root);
    printf("\n");
    printf("Postorder: ");
    postorderTraversal(root);
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

//_______________Preorder Traversal_________

node preorderTraversal(node *root){
    if(root != NULL){
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

//_______________Postorder Traversal_________

node postorderTraversal(node *root){
    if(root != NULL){
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

//________________________INSERTION USING RECURSIVE FUNCTION_______________

node * insertNode(node * root, int value){
    // Check if the root is NULL
    if(root == NULL) return createNode(value);
    
    // Recusrsive case
    if(value < root->data){
        root->left = insertNode(root->left, value);
    } else{
        // if the new value is greater than or equals to the current root
        root->right = insertNode(root->right, value);
    }

    return root; // This is most important---to keep track of the root of the tree
}