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

int main() {

    
    // Create and Allocating the linked List
    // struct Node * first = (struct Node *)malloc(sizeof(struct Node));
    // struct Node * second = (struct Node *)malloc(sizeof(struct Node));
    // struct Node * third = (struct Node *)malloc(sizeof(struct Node));
    // struct Node * fourth = (struct Node *)malloc(sizeof(struct Node));
    // struct Node * fifth = (struct Node *)malloc(sizeof(struct Node));

    // // Assign the data links
    // first -> data = 66;
    // first -> next = second;

    // second -> data = 67;
    // second -> next = third;
    
    // third -> data = 68;
    // third -> next = fourth;

    // fourth -> data = 69;
    // fourth -> next = fifth;

    // fifth -> data = 70;
    // fifth -> next = NULL;

    // pushing the elements
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

    return 0;
}