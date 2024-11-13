#include<stdio.h>
#include<stdlib.h>

// Structure for the Node
struct Node{
    int data;
    struct Node * next;
};

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
        return 1; // 2 = false(Linked-List is Full)
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
int pop(struct Node ** top){
    if(isEmpty(*top)){
        printf("Stack Underflow");
    }else{
        struct Node * n = *top;
        *top = (*top) -> next;
        int x = n -> data;
        free(n);
        return x;
    }
}

// Peek function
int peek(struct Node * top, int pos){
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

int main() {

    struct Node * top = NULL;

    // pushing the elements
    top = push(top, 67);
    top = push(top, 68);
    top = push(top, 69);

    printf("Linked-List after PUSH: \n");
    printLinkedList(top);

    printf("\n");

    // popping(removing) the element
    int element = pop(&top);

    printf("Linked-List after POP:\n");
    printLinkedList(top);

    printf("\n");

    printf("removed element : %d \n", element);

    // peek the element at position 2 
    int value = peek(top, 2); 
    if (value != -1) {
        printf("Element at position 2: %d\n", value);
    } else{ 
        printf("Invalid position\n");
    }

    return 0;
}