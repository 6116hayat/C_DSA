#include<stdio.h>
#include<stdlib.h>

struct Node * f = NULL;
struct Node * r = NULL;

// Defining Node Structure
struct Node{
    int data;
    struct Node * next;
};

// printLinked-List
void printLinkedList(struct Node * ptr){
    printf("Printing the elements of this linked\n");
    while(ptr != NULL){
        printf("Element: %d\n", ptr ->data);
        ptr = ptr -> next;
    }
}

// enqueue Function
void enqueue(int val){
    struct Node * n = (struct Node *)malloc(sizeof(struct Node));
    if(n == NULL){
        printf("Queue is Full\n");
    }
    else{
        n->data = val;
        n->next = NULL;
        if(f == NULL){
            f = r = n;
        }
        else{
            r ->next = n ;
            r = n;
        }
    }
}

// Dequeue Function
int dequeue(){
    int val = -1;
    struct Node * ptr = f;

    if(f == NULL){
        printf("Queue Empty\n");
    }
    else{
        f = f ->next;
        val = ptr->data;
        free(ptr);
        return (val);
    }
}

int main()
{
    printLinkedList(f);
    printf("Dequeuing element %d\n", dequeue());
    enqueue(34);
    enqueue(4);
    enqueue(7);
    enqueue(17);
    printf("Dequeuing element %d\n", dequeue());
    printf("Dequeuing element %d\n", dequeue());
    printf("Dequeuing element %d\n", dequeue());
    printf("Dequeuing element %d\n", dequeue());
    printLinkedList(f);
    return 0;
}