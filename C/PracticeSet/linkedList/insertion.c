#include<stdio.h>
#include<stdlib.h>

// Declaring the structure of a Node
struct Node{
    int data;
    struct Node * next;
};

// function to print Linked-list
void printNode(struct Node * ptr){
    while(ptr != NULL){
        printf("Element: %d \n", ptr-> data);
        ptr = ptr -> next;
    }
}


// CASE 1: Insert Node at first 
struct Node * NodeAtfirst(struct Node * head, int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = head;
    return ptr;
}

// CASE 2: Insert Node at Index
struct Node * NodeAtIndex(struct Node * head, int data, int index){
    struct Node *  ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node * p = head;

    int i = 0;

    while(i != index-1){
        p = p->next;
        i++;
    }

    ptr -> next = p -> next;
    p -> next = ptr;

    return head;

}

// CASE 3: Insert at End
struct Node * NodeAtEnd(struct Node * head, int data){
    struct Node * ptr =  (struct Node *)malloc(sizeof(struct Node));
    ptr -> data = data;

    struct Node * p = head;

    while(p->next != NULL){
        p = p->next;
    }
    
    p->next = ptr;
    ptr->next = NULL;

    return head;
}

// CASE 4: Insert after Node 
struct Node * NodeAfterNode(struct Node * head, struct Node * prevNode, int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr -> data = data;

    ptr -> next = prevNode -> next;
    prevNode -> next = ptr;

    return head;

}

int main() {

    // Declare a pointer
    struct Node * head;
    struct Node * second;
    struct Node * third;
    struct Node * fourth;
    struct Node * fifth;

    // Allocate memory
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    fifth = (struct Node *)malloc(sizeof(struct Node));

    // Linking the pointer
    head -> data = 17;
    head -> next = second;

    second -> data = 18;
    second -> next = third;

    third -> data = 19;
    third -> next = fourth;

    fourth -> data = 20;
    fourth -> next = fifth;

    fifth -> data = 21;
    fifth -> next = NULL;

    printf("LinkedList Node before insertion\n");
    printNode(head);

    // head = NodeAtfirst(head, 89); 

    // head = NodeAtIndex(head, 78, 3);

    // head = NodeAtEnd(head, 100);

    // head = NodeAfterNode(head, second, 33);

    printf("LinkedList Node after insertion\n");
    printNode(head);

    return 0;
}