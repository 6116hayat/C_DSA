#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Structure For the Stack
struct stack{
    int size;
    int top;
    char * arr;
};

// isEmpty function
int isEmpty(struct stack * ptr){
    if(ptr -> top == -1){
        return 1;
    }else{
        return 0;
    }
}

// isFull function
int isFull(struct stack * ptr){
    if(ptr -> top == ptr-> size -1 ){
        return 1;
    }else{
        return 0;
    }
}

// Function for stackTop
int stackTop(struct stack * sp){
    return sp -> arr[sp -> top];
}

// Push Function
void pushFun(struct stack * ptr, char val){
    if(isFull(ptr)){
        printf("Full Stack\n");
    }else{
        ptr -> top++;
        ptr->arr[ptr->top] = val;
    }
}

// Pop Function
char popFun(struct stack * ptr){
    if(isEmpty(ptr)){
        printf("Stack Empty\n");
        return -1;
    }else{
        char val = ptr->arr[ptr->top];
        ptr -> top--;
        return val;
    }
}

int precedence(char ch){
    if(ch == '*' || ch == '/'){
        return 3;
    }else if(ch == '+'|| ch == '-'){
        return 2;
    }
    else{
        return 0;
    }
}

int isOperator(char ch){
    if(ch == '+'|| ch == '-'|| ch == '*'|| ch == '/'){
        return 1;
    }else{
        return 0;
    }
}

// Function for the infix to postfix
char * infixToPostfix(char * infix){

    // Declare the stack 
    struct stack * sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 100;
    sp->top = -1;
    sp -> arr = (char *) malloc(sp->size * sizeof(char));

    // Declare the postfix 
    char * postfix = (char *)malloc((strlen(infix)+1) * sizeof(char));
    int i = 0; // tracks infix transversal
    int j = 0; // tracks potfix addition
    while(infix[i] != '\0'){
        if(!isOperator(infix[i])){
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else{
            if(precedence(infix[i]) > precedence(stackTop(sp))){
                pushFun(sp, infix[i]);
                i++;
            }
            else{
                postfix[j] = popFun(sp);
                j++;
            }
        }
    }
    while(!isEmpty(sp)){
        postfix[j] = popFun(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

int main() {

    char * infix = "x-y*z";

    printf("Postfix is %s", infixToPostfix(infix));

    return 0;
}