#include<stdio.h>
#include<stdlib.h>

// Declaring a structure for the Node
struct Node{
    int data;
    struct Node * next; // Pointer declared to point next element
};

//function to print the Node
void printNode(struct Node * ptr){
    while(ptr-> next != NULL){
        printf("Element: %d \n", ptr -> data);
        ptr = ptr -> next;
    }
}

int main() {

    // Declaring a pointer
    struct Node * head;
    struct Node * second;
    struct Node * third;
    struct Node * fourth;
    struct Node * fifth;

    // Assign memory for the Node
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    fifth = (struct Node *)malloc(sizeof(struct Node));

    // Assing data and link the pointers 
    head-> data = 55;
    head-> next = second;

    second-> data = 65;
    second-> next = third;

    third-> data = 75;
    third-> next = fourth;

    fourth-> data = 85;
    fourth-> next = fifth;

    fifth-> data = 95;
    fifth-> next = NULL;

    printf("Printing the Whole Node: \n");  

    // printNode function being Called
    printNode(head);


    return 0;
}