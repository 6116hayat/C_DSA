#include<stdio.h>
#include<stdlib.h>

// Creating a Doubly Linked List
struct Node{
    int data;
    struct Node * prev;
    struct Node * next;
};

// Function to transverse the doubly linked list 
void linkedListTranversal(struct Node * ptr){

    while(ptr != NULL){
        printf("Element %d \n", ptr -> data);
        ptr = ptr-> next;
    }
}

int main() {

// Creating Nodes
struct Node * head = (struct Node *)malloc(sizeof(struct Node));
struct Node * second = (struct Node *)malloc(sizeof(struct Node));
struct Node * third = (struct Node *)malloc(sizeof(struct Node));

// Assign data and links
head -> data = 1;
head -> prev = NULL;
head -> next = second;

second -> data = 2;
second -> prev = NULL;
second -> next = third;

third -> data = 3;
third -> prev = NULL;
third -> next = NULL;

// Traverse the list
linkedListTranversal(head);

    return 0;
}