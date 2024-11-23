#include<stdio.h>
#include<stdlib.h>

// Structure for the Node
struct Node{
    int data;
    struct Node * next;
};

struct Node * top = NULL; // top pointer = declared a global variable 

// Print Linkedlist 
void printLinkedList(struct Node * ptr){
    while(ptr != NULL){
        printf("Element : %d \n", ptr->data);
        ptr = ptr -> next;
    }
}

// isEmpty function
int isEmpty(struct Node * top){
    if (top == NULL){
        return 1; // 1 = true(Linked-List is Empty)
    }else{
        return 0; // 0 = false(Linked-List is not Empty)
    }
}

// isFull function
int isFull(struct Node* top){
    struct Node * p = (struct Node *)malloc(sizeof(struct Node));
    if(p == NULL){
        return 1; // 1 = false(Linked-List is Full)
    }else{
        return 0; // 0 = false(Linked-List is not Full)
    }
}

// push Function
struct Node * push(struct Node * top, int x){
    if(isFull(top)){
        printf("Stack Overflow\n");
    }else{
        struct Node * n = (struct Node *)malloc(sizeof(struct Node));
        n -> data = x;
        n -> next = top;
        top = n;
    }
}

// pop Function
int pop(struct Node * tp){
    if(isEmpty(tp)){
        printf("Stack Underflow");
    }else{
        struct Node * n = tp;
        top = tp -> next;
        int x = n -> data;
        free(n);
        return x;
    }
}

// Peek function
int peek(int pos){
    struct Node * ptr = top;
    for(int i = 0; (i < pos - 1 && ptr != NULL); i ++){
        ptr = ptr -> next;
    }
    if(ptr != NULL){
        return ptr -> data;
    }
    else{
        return -1; 
    }
}

// StackTop function
int stackTop(struct Node * top){
    if(isEmpty(top)){
        printf("Stack is empty\n");
        return -1;
    }
    return top-> data;
}

// StackBottom function
int stackBottom(struct Node * top){
    if(isEmpty(top)){
        printf("stack is empty\n");
        return -1;
    }
    struct Node * temp = top;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    return temp -> data;

}

int main() {

    // pushing the elements

    top = push(top, 65);
    top = push(top, 66);
    top = push(top, 67);
    top = push(top, 68);
    top = push(top, 69);

    printf("Linked-List after PUSH: \n");
    printLinkedList(top);

    printf("\n");

    // popping(removing) the element
    int element = pop(top);

    printf("Linked-List after POP:\n");
    printLinkedList(top);

    printf("\n");

    printf("removed element : %d \n", element);

    printf("\n");

    printf("Element at position 2: %d \n", peek(2));

    printf("\n");

    // peek function using for loop
    for(int i = 1; i < 4; i++){
        printf("Value at Position %d is : %d\n", i , peek(i));
    }

    printf("\n");

    // stackTop function
    printf("Top element is %d \n", stackTop(top));

    printf("\n");

    // stackBottom function
    printf("Bottom element is %d \n", stackBottom(top));


    return 0;
}