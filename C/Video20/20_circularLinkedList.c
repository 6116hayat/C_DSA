#include<stdio.h>
#include<stdlib.h>

// Creating a Linked List
struct Node{
    int data;
    struct Node * next;
};

void linkedListTravesal(struct Node * head){

    struct Node * ptr = head;

// We are using Do-While loop cause of 2 reasons
// i) do-while kickstarts the program to print the Linked list
// ii) do-while loop atleast runs one time 
    do{
        printf("Element is %d \n", ptr -> data);
        ptr = ptr -> next;
    }while(ptr != head);
}

struct Node * insertAtFirst(struct Node * head, int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr -> data = data;


    struct Node * p = head -> next;
    while(p ->  next != head){
        p = p -> next;
    }
    // At this point, p points to the last node of this circular linked list

    p-> next = ptr;
    ptr -> next = head;

    head = ptr;
    return head;
}

int main() {
    
    struct Node * head;
    struct Node * second;
    struct Node * third;
    struct Node * fourth;
    struct Node * fifth;

    // Allocate memory for nodes in the linked list in HEAP
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    fifth = (struct Node *)malloc(sizeof(struct Node));

    // Link first and second nodes
    head->data = 7;
    head->next = second;

    // Link second and third nodes
    second->data = 11;
    second->next = third;

    // Link third and fourth nodes
    third->data = 15;
    third->next = fourth;

    // Link fourth and fifth nodes
    fourth->data = 19;
    fourth->next = fifth;

    // Terminate the list at the fifth node
    fifth->data = 23;
    fifth->next = head;

    printf("Circular Linked List before Insertion \n");
    linkedListTravesal(head);

    head =  insertAtFirst(head, 80);
    printf("Circular Linked List After Insertion \n");
    linkedListTravesal(head);

    return 0;
}