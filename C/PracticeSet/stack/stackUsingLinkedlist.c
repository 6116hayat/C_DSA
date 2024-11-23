#include<stdio.h>
#include<stdlib.h>

// Structure for Node
struct Node{
    int data;
    struct Node * next;
};

struct Node * top = NULL; // top pointer declared global variable 

// Print linked list
void printLinkedList(struct Node * ptr){
    while(ptr!= NULL){
        printf("Element = %d\n", ptr -> data);
        ptr = ptr-> next;
    }
}

// isEmpty
int isEmpty(struct Node * top){
    if(top == NULL ){
        return 1; // Stack is Empty
    }else{
        return 0; // stack is not Full
    }
}

// isFull
int isFull (struct Node * top){
    struct Node * p = (struct Node *)malloc(sizeof(struct Node));
    if(p == NULL){
        return 1; // stack is Full
    }else{
        return 0; // stack is not full
    }
}

// push structure 
struct Node * push(struct Node * top, int val){
    if(isFull(top)){
        printf("Stack Overflow");
    }else{
        struct Node * n = (struct Node *)malloc(sizeof(struct Node));
        n -> data = val;
        n -> next = top;
        top = n;
    }
}

// Pop structure
int pop(struct Node *  tp){
    if(isEmpty(top)){
        printf("Stack Underflow");
    }else{
        struct Node * n = tp;
        top = tp -> next;
        int val = n -> data;
        free(n);
        return val;
    }
}

// stackTop
int stackTop(struct Node * top){
    if(isEmpty(top)){
        printf("stack is empty");
        return -1;
    }else{
        return top ->data;
    }
}

// stackBottom
int stackBottom(struct Node * top){
    if(isEmpty(top)){
        printf("Stack is Empty");
        return -1;
    }
    struct Node * temp = top;
    while(temp->next != NULL){
        temp = temp -> next;
    }
    return temp -> data;
}


int main() {

    // Pushing the Elements
    top = push(top , 86);
    top = push(top , 87);
    top = push(top , 88);
    top = push(top , 89);
    top = push(top , 90);
    top = push(top , 91);

    printf("Linked list After Push\n");
    printLinkedList(top);

    printf("\n");

    // Popping the Element
    int element = pop(top);

    printf("Linked list After pop\n");
    printLinkedList(top);

    printf("\n");

    printf("Element removed : %d \n", element);

    printf("\n");

    // stackTop function
    printf("Top element is %d \n", stackTop(top));

    printf("\n");

    // stackBottom function
    printf("Bottom element is %d \n", stackBottom(top));


    return 0;
}