#include<stdio.h>
#include<stdlib.h>

// Define Structure of node
struct Node{
    int data;
    struct Node * next;
};

void linkedListTravesal(struct Node * ptr){

    while(ptr!= NULL){
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }

}

// CASE 1: creating the function to Insert Node At first 
struct Node * insertAtFirst(struct Node *head, int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = head;
    return ptr;
}

// CASE 3: creating the function to Insert Node at END 
struct Node * insertAtEnd(struct Node *head, int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node * p = head;

    while(p->next!=NULL){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;

    return head;

}

// CASE 4: creating the function to Insert Node after Node
struct Node * insertAfterNode(struct Node *head, struct Node *prevNode, int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    

    ptr->next = prevNode-> next;
    prevNode->next = ptr;

    return head;

}

// CASE 2: creating the function to insert node at Index
struct Node * insertAtIndex(struct Node *head, int data, int index){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node * p = head;
    int i = 0;

    while(i!= index-1){
        p = p->next;
        i++;
    }

    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;

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
    fifth->next = NULL;

    printf("Linked List before Insertion \n");

    linkedListTravesal(head);

    printf("\n");

    printf("Linked List before Insertion \n");

    // head = insertAtFirst(head, 5);
    // linkedListTravesal(head);

    // head = insertAtIndex(head, 27, 2);
    // linkedListTravesal(head);

    head = insertAtEnd(head, 27);
    linkedListTravesal(head);

    // head = insertAfterNode(head, second, 88);
    // linkedListTravesal(head);
    
    return 0;
}