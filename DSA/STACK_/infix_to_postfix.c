#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

char stack[MAX], infix[MAX], postfix[MAX];
int top = -1;
//__________________________________________________
void intoPostfix();
int precedance(char symbol);
void push(char symbol);
char pop();
int is_empty();
//__________________________________________________
int main(){

    // Take the input expression from user
    printf("Enter the expression: ");
    fgets(infix, MAX-1,stdin);
    infix[strcspn(infix, "\n")] = '\0'; // Make it a valid string

    intoPostfix();
    printf("The postfix expression: %s\n",postfix);
    // printf("The stack: %s",stack);
    printf("Is Stack Empty (1=Yes, 0=No): %d\n", is_empty());


    return 0;
}

//_____________________________________________________
void intoPostfix(){
    char c_character, head;
    int j=0;

    for(int i = 0; i < strlen(infix); i++){
        c_character = infix[i];

        switch(c_character){
            case '(':   push(c_character);               //case 1
                        break;                      
            case ')':                                       // case 2
                        while( !is_empty() && (head = pop()) != '('){
                            postfix[j++] = head;
                        }
                        //edge case: If there is '(' present as the last(top) element at the stack
                        if(!is_empty() && stack[top] == '('){
                        pop(); // DISCARD the opening parenthesis
                        }
                        break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':   /*check whether the stack is empty or 
                         top element in the stack is '(' or precedance of top operator of the stack are greater than 
                         or equals to the precedance of the current operator*/

                        while(!is_empty() && stack[top] != '(' && precedance(stack[top]) >= precedance(c_character)){
                            postfix[j++] = pop();
                        }
                        push(c_character);
                        break;
            default: 
                        postfix[j++] = c_character;
        }
    }
    while(!is_empty()){
        char remaining = pop();
        if(remaining == '(' || remaining == ')'){
            printf("Mismatched parentheses found in the stack!\n");
            continue;
        }
        postfix[j++] = remaining;
    }
    postfix[j] = '\0';
}

//___________________________PRECEDANCE FUNCTION_________________________

int precedance(char symbol){

    switch(symbol){
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+': 
        case '-': return 1;
        default: return 0;
    }
}
//_____________________________Is Empty ____________________________________
int is_empty(){
    if(top == -1){
        return 1;
    } else{
        return 0;
    }
}

//__________________________PUSH FUNCTION______________________________

void push(char symbol){
    if(top < MAX-1){
        stack[++top] = symbol;
    } else{
        printf("Overflow Occured!\n");
    }
}

//__________________________POP FUCNTION________________________________
char pop(){
    if(top != -1){
        return stack[top--];
    } else{
        printf("Underflow Occured!\n");
        return 0;
    }
}

