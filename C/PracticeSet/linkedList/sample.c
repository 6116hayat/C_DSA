// Program to learn creating an Linked List along with priting it

#include <stdio.h>
#include <stdlib.h>

// Declare structure of node
struct Node{
    int data;
    struct Node * next;
};

// tranverse along the node
void printLinkedList(struct Node * ptr){

    while( ptr !=  NULL){
        printf("Element: %d \n", ptr -> data);
        ptr = ptr -> next;
    }
}

int main()
{

    // Declare pointers
    struct Node * head; // Head Pointer
    struct Node * second; // second Pointer

    // Allocate memory
    head =  (struct Node *)malloc(sizeof(struct Node )); // head Node allocate in memory
    second =  (struct Node *)malloc(sizeof(struct Node )); // second Node allocate in memory

    // Linking Nodes
    head -> data = 7;
    head -> next = second;

    second -> data = 10;
    second -> next = NULL;

    printLinkedList(head);

    return 0;
}