/*
    To-Do list 
    1) Include the libraries
    2) structure for stack (size, top, arr)
    3) isEmpty fun
    4) isFull fun
    5) push Fun 
    6) pop Fun
    7) parenthesis Fun
    8) main Fun
*/

// 1. Included the Libraries
#include<stdio.h>
#include<stdlib.h>

// 2. structure for the Stack
struct stack {
    int size;
    int top;
    char * arr;
};

// 3. isEmpty fun
int isEmpty(struct stack * ptr){
    if(ptr -> top == -1){
        return 1;
    }else{
        return 0;
    }
}

// 4. isFull fun
int isFull(struct stack * ptr){
    if(ptr -> top == ptr->size -1){
        return 1;
    }else{
        return 0;
    }
}

// 5. push fun
void pushFun(struct stack * ptr, char val){
    if(isFull(ptr)){
        printf("Stack Full\n");
    }else{
        ptr-> top++;
        ptr -> arr[ptr -> top] = val;
    }
}

// pop fun
char popFun(struct stack * ptr){
    if(isEmpty(ptr)){
        printf("Stack Empty\n");
        return -1;
    }else{
        char val = ptr -> arr[ptr -> top];
        ptr -> top --;
        return val;
    }
}

int parenthesisMatch(char * exp){

    // Create and intialize stack
    struct stack * s =(struct stack *)malloc(sizeof(struct stack));
    s -> size = 100;
    s-> top = -1;
    s-> arr = (char * )malloc(s->size * sizeof(char));

    for(int i = 0; exp[i] != '\0'; i++){
        if (exp[i] == '('){
            pushFun(s , '(');
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
    char* exp = "()8)*(9)";

    // Check 
    if (parenthesisMatch(exp)) {
        printf("The parenthesis is matching");
    } else {
        printf("The parenthesis is not matching");
    }

    return 0;
}
