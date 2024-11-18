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
        return -1;
    }else{
        char val = ptr->arr[ptr->top];
        ptr -> top--;
        return val;
    }
}


// Function for the parenthesis Match
int parenthesisMatch(char * exp){
    // Create and Initialise Stack
    struct stack * s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 100;
    s->top = -1;
    s->arr = (char *)malloc(s->size * sizeof(char));
    for(int i = 0; exp[i] != '\0'; i++){
        if(exp[i] == '('){
            pushFun(s, '(');
        }else if(exp[i] == ')'){
            if(isEmpty(s)){
                return 0;
            }
            popFun(s);
        }
    }
    if(isEmpty(s)){
        return 1;
    }else{
        return 0;
    }
}

int main() {

    char * exp = "8)*(9";

    // Check 
    if(parenthesisMatch(exp)){
        printf("The parenthesis is matching");
    }
    else{
        printf("The parenthesis is not matching");
    }

    return 0;
}