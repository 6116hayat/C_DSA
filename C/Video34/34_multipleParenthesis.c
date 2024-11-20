#include<stdio.h>
#include<stdlib.h>

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
        return '\0'; //return null char to indicate empty
    }else{
        char val = ptr->arr[ptr->top];
        ptr -> top--;
        return val;
    }
}

int match(char a, char b){
    if(a == '{' && b == '}'){
        return 1;
    }
    if(a == '(' && b == ')'){
        return 1;
    }
    if(a == '[' && b == ']'){
        return 1;
    }
    return 0;
}

// Function for the Multi parenthesis Match
int parenthesisMatch(char * exp){
    // Create and Initialise Stack
    struct stack * s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 100;
    s->top = -1;
    s->arr = (char *)malloc(s->size * sizeof(char));
    char popped_ch;

    // Expression iterate
    for(int i = 0; exp[i] != '\0'; i++){
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '['){
            pushFun(s, exp[i]);
        }else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']' ){
            if(isEmpty(s)){
                return 0;
            }
            popped_ch = popFun(s);
            if(!match(popped_ch, exp[i])){
                return 0;
            }
        }
    }
    if(isEmpty(s)){
        return 1;
    }else{
        return 0;
    }
}

int main() {

    char * exp = "{7-(3-2)+[8+(99-11)]}";

    // Check 
    if(parenthesisMatch(exp)){
        printf("The parenthesis is matching");
    }
    else{
        printf("The parenthesis is not matching");
    }

    return 0;
}