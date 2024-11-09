#include<stdio.h>
#include<stdlib.h>


// Declared a structure Node
struct Node{
    int data;
    struct Node * prev;
    struct Node * next;
};


// function to Print Node
void printList(struct Node * ptr){
    while(ptr != NULL){
        printf("Element: %d \n",ptr->data);
        ptr = ptr -> next;
    }
}


int main() {

    // Creating and Allocating Node
    struct Node * head = (struct Node *)malloc(sizeof(struct Node));
    struct Node * second = (struct Node *)malloc(sizeof(struct Node));
    struct Node * third = (struct Node *)malloc(sizeof(struct Node));
    struct Node * fourth = (struct Node *)malloc(sizeof(struct Node));
    struct Node * fifth = (struct Node *)malloc(sizeof(struct Node));

    // Adding Data and Linking Nodes
    head->data = 55;
    head -> prev =  NULL;
    head -> next = second;

    second ->data = 56;
    second -> prev =  head;
    second -> next = third;

    third ->data = 57;
    third -> prev =  second;
    third -> next = fourth;

    fourth ->data = 58;
    fourth -> prev =  third;
    fourth -> next = fifth;

    fifth->data = 59;
    fifth -> prev =  fourth;
    fifth -> next = NULL;

    printf("Linked List :\n");
    printList(head);

    
    return 0;
}