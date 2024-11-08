#include<stdio.h>
#include<stdlib.h>

// Creating a Linked List
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

// Case 1 : Deleting the first element from the linked list
struct Node * deleteFirst(struct Node * head){
    struct Node * ptr = head;
    head = head -> next;
    free(ptr);
    return head;
}


// Case 2 : Deleting the element at a given index from the linked list
struct Node * deleteAtIndex(struct Node * head, int index){
    struct Node * p = head;
    struct Node * q = head -> next;

    for(int i = 0; i < index - 1; i++){
        p = p -> next;
        q = q -> next;
    }

    p -> next =  q ->  next;
    free(q);

    return head;
}

// Case 3 : Deleting the element at Last from the linked list
struct Node * deleteAtLast(struct Node * head){
    struct Node * p = head;
    struct Node * q = head -> next;

    while(q -> next != NULL){
        p = p -> next;
        q = q -> next;
    }

    p -> next = NULL;
    free(q);

    return head;
}

// Case 4 : Deleting the element with a given value from the linked list
struct Node * deleteAtValue(struct Node * head, int value){
    struct Node * p = head;
    struct Node * q = head -> next;

    while(q -> data != value && q-> next != NULL){
        p = p -> next;
        q = q -> next;
    }

    if( q-> data == value){
        p -> next = q -> next;
        free(q);
    }

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

    printf("Linked List before Deletion \n");
    linkedListTravesal(head);

    printf("\n"); // for extra line

    // for deleting first element of the list
    // head = deleteFirst(head); 

    // for deleting element at index from the list
    // head = deleteAtIndex(head, 2); 

    // for deleting element at last of the list
    // head = deleteAtLast(head); 

    // for deleting element with given value from the list
    head = deleteAtValue(head, 15); 

    printf("Linked List after Deletion \n");
    linkedListTravesal(head);



    return 0;
}