#include<stdio.h>
#include<stdlib.h>

// Structure declared fo the Node
struct Node{
    int data;
    struct Node * next;
};

// Printing the Node 
void printNode(struct Node * ptr){
    while(ptr != NULL){
        printf("Element : %d\n", ptr->data);
        ptr = ptr-> next;
    }
}

// CASE 1: Deleting Node at First
struct Node * DeleteAtFirst(struct Node * head){
    struct Node *  ptr = head;

    head = head -> next;
    free(ptr);

    return(head);
}

// CASE 2: Deleting Node at Index
struct Node * DeleteAtIndex(struct Node * head, int index){
    struct Node * p = head;
    struct Node * q = p -> next;

    for(int i = 0; i < index - 1; i++){
        p = p-> next;
        q = q-> next;
    }


    p-> next = q -> next;
    free(q);

    return head;
}

// CASE 3: Deleting the Node at Last
struct Node * DeleteAtEnd(struct Node * head){
    struct Node * p = head;
    struct Node * q = p->next;

    while(q->next != NULL){
        p = p->next;
        q = q->next;
    }

    p->next = NULL;
    free(q);

    return head;
}

// CASE 4: Deleting the Node after Node
struct Node * DeleteAfterNode (struct Node * head, int value){
    struct Node * p = head;
    struct Node * q = p->next;

    while(q-> data != value && q -> next != NULL){
        p = p -> next;
        q = q -> next;
    }

    if(q->data == value){
        p->next = q->next;
        free(q);
    }

    return head;
}

int main() {

    // Declaring pointers
    struct Node * head;
    struct Node * second;
    struct Node * third;
    struct Node * fourth;
    struct Node * fifth;

    // Allocating memory
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    fifth = (struct Node *)malloc(sizeof(struct Node));

    // Allocating the Data and Linking with different Node
    head->data = 100;
    head->next = second;

    second->data = 99;
    second->next = third;

    third->data = 98;
    third->next = fourth;

    fourth->data = 97;
    fourth->next = fifth;

    fifth->data = 96;
    fifth->next = NULL;

    // Calling the function
    printf("Linked List before Deletion \n\n");
    printNode(head);

    // head = DeleteAtFirst(head);

    // head = DeleteAtIndex(head, 2);

    // head = DeleteAtEnd(head);

    head = DeleteAfterNode(head, 98);

    printf("Linked List after Deletion \n");
    printNode(head);

    return 0;
}