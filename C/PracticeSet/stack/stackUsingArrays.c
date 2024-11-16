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
    return ptr->top == -1;
}

// isFUll Function
int isFull(struct stack * ptr){
    return ptr->top == ptr-> size -1;
}

// Push Function
void pushFun(struct stack * ptr, int val){
    if(isFull(ptr)){
        printf("Stack is Full\n");
    }else{
        ptr-> top ++;
        ptr->arr[ptr->top] = val;
    }
}

// Pop Function
int popFun(struct stack * ptr){
    if(isEmpty(ptr)){
        printf("Stack is Empty\n");
        return -1; // return -1 for the stack empty
    }else{
        int val =  ptr ->arr[ptr-> top];
        ptr->top--;
        return val;
    }
}

// Peek Function
int peekFun(struct stack * sp, int index){
    int arrayInd = sp->top - index + 1; // Formula for the position
    if((arrayInd < 0) || (arrayInd > sp-> top)){
        printf("Invalid position in stack\n");
    }
    else{
        return sp->arr[arrayInd];
    }
}

// StackTop Function
int stackTop(struct stack * sp){
    return sp->arr[sp->top];
}

// StackBottom Function
int stackBottom(struct stack * sp){
    return sp->arr[0];
}

void printStack(struct stack * ptr){
    if(isEmpty(ptr)){
        printf("Stack is Empty\n");
    }else{
        for (int i = ptr->top; i >= 0; i--){
            printf("Element %d at index %d\n", ptr->arr[i], i);
        }
        printf("\n");
    }
}

int main() {

    // Creating a Stack
    struct stack * sp = createStack(10);

    // Pushing element to function
    pushFun(sp,42);
    pushFun(sp,49);
    pushFun(sp,56);
    pushFun(sp,63);
    pushFun(sp,70);

    printf("The Stack before Popping\n");
    printStack(sp);

    printf("\n");

    // pop an element from stack
    printf("Popped %d from the stack\n", popFun(sp));

    printf("\n");

    printf("The Stack after Popping\n");
    printStack(sp);

    printf("\n");

    int value = peekFun(sp, 2);
    printf("Element %d is at index %d\n",value , 2);

    printf("\n");

    printf("Top-most element of stack =  %d\n", stackTop(sp));

    printf("\n");

    printf("Bottom-most element of stack =  %d\n", stackBottom(sp));

    return 0;
}