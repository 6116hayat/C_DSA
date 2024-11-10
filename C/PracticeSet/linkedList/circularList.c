#include<stdio.h>
#include<stdlib.h>

// Structure for the Node 
struct Node{
    int data;
    struct Node * next;
};

// function to print List with do-while Loop
void printList(struct Node * head){

    struct Node * ptr = head;

    do{
        printf("Element : %d\n", ptr ->data);
        ptr = ptr -> next;
    } while (ptr != head);
    
}

int main() {

    // Creating and Allocating memory  
    struct Node * head = (struct Node *)malloc(sizeof(struct Node));
    struct Node * second = (struct Node *)malloc(sizeof(struct Node));
    struct Node * third = (struct Node *)malloc(sizeof(struct Node));
    struct Node * fourth = (struct Node *)malloc(sizeof(struct Node));
    struct Node * fifth = (struct Node *)malloc(sizeof(struct Node));

    // Linking the Nodes
    head->data = 88;
    head->next = second;

    second->data = 89;
    second->next = third;

    third->data = 90;
    third->next = fourth;

    fourth->data = 91;
    fourth->next = fifth;

    fifth->data = 92;
    fifth->next = NULL;

    printf("Circular Linked List before Insertion \n");
    printList(head);
    
    return 0;
}