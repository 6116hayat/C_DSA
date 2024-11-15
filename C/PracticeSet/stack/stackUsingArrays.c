#include<stdio.h>
#include<stdlib.h>

// Structure for the stack
struct stack{
    int size;
    int top;
    int * arr;
};

// Create Stack Function
struct stack * createStack(int size){
    struct stack * sp = (struct stack * )malloc(sizeof(struct stack));
    sp->size =  size;
    sp->top = -1;
    sp-> arr = (int *)malloc(sp->size * sizeof(int));
    return sp;
}

// isEmpty Function
int isEmpty(struct stack * ptr){
    if(ptr->top == -1 ){
        return 1; // true
    }
}

// isFUll Function
int isFull(struct stack * ptr){
    if(ptr->top == ptr-> size -1 ){
        return 1; // true 
    }
}

// Push Function
// void pushFun(struct stack * ptr, int val){
//     if
// }

int main() {
    
    return 0;
}