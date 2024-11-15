#include<stdio.h>
#include<stdlib.h>


// Creating a structure for the Stack
struct stack{
    int size;
    int top;
    int * arr;
};

//isFull Function for the stack checking to be full or not 
int isFull(struct stack * ptr){
    if(ptr -> top == ptr -> size - 1){
        return 1;
    }
    else{
        return 0;
    }
}

//isEmpty Function for the stack checking to be empty or not 
int isEmpty(struct stack * ptr){
    if(ptr -> top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

// Function to create value and push in the array
void push(struct stack * ptr, int val){
    if(isFull(ptr)){
        printf("Stack Overflow!! Cannot push %d to the stack\n", val);
    }else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

// Function to create value and push in the array
int pop(struct stack * ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow!! Cannot pop from the Stack\n");
        return -1;
    }else{
        int val = ptr-> arr[ptr->top];
        ptr->top--;
        return val;
    }
}


// Creating Peek function
int peek(struct stack *sp, int i){
    int arrayInd = sp->top - i +1 ;
    if (arrayInd < 0){
        printf("Not a valid position for the stack\n");
        return -1;
    }
    else{
        return sp->arr[arrayInd];
    }
    
}


int main() {

    // pointer 'sp' pointing towards structure stack
    struct stack * sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));
    printf("Stack has been created succesfully\n");

    printf("Before Pushing, Full: %d\n", isFull(sp));
    printf("Before Pushing, Empty: %d\n", isEmpty(sp));

    // This pushes and element in the array
    push(sp, 5);
    push(sp, 6);
    push(sp, 7);
    push(sp, 8);
    push(sp, 9);
    push(sp, 10);
    push(sp, 11);
    push(sp, 12);

    printf("After Pushing, Full: %d\n", isFull(sp));
    printf("After Pushing, Empty: %d\n", isEmpty(sp));

    // printing value inside the stack
    for(int j = 1; j <= sp->top + 1; j++){
        printf("The value at position %d is %d\n", j ,peek(sp,j));
    }

    return 0;
}