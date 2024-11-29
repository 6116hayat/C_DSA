#include<stdio.h>
#include<stdlib.h>

// Defining Node And Queue Structure
struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to check if the queue is empty
int isEmpty(struct Queue* q) {
    return (q->front == NULL);
}

// printLinked-List
void printLinkedList(struct Node* ptr) {
    printf("Printing the elements of this linked list:\n");
    while (ptr != NULL) {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// enqueue Function
void enqueue(struct Queue* q, int val) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    if (n == NULL) {
        printf("Queue is Full\n");
    } else {
        n->data = val;
        n->next = NULL;
        if (q->rear == NULL) {
            q->front = q->rear = n;
        } else {
            q->rear->next = n;
            q->rear = n;
        }
    }
}

// Dequeue Function
int dequeue(struct Queue* q) {
    int val = -1;
    if (q->front == NULL) {
        printf("Queue is Empty\n");
    } else {
        struct Node* ptr = q->front;
        q->front = q->front->next;
        val = ptr->data;
        free(ptr);
        if (q->front == NULL) {
            q->rear = NULL;
        }
    }
    return val;
}

int main() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;

    printLinkedList(q->front);
    printf("Dequeuing element %d\n", dequeue(q));
    enqueue(q, 34);
    enqueue(q, 4);
    enqueue(q, 7);
    enqueue(q, 17);
    printf("Dequeuing element %d\n", dequeue(q));
    printf("Dequeuing element %d\n", dequeue(q));
    printf("Dequeuing element %d\n", dequeue(q));
    printf("Dequeuing element %d\n", dequeue(q));
    printLinkedList(q->front);

    // Free the remaining nodes
    while (!isEmpty(q)) {
        dequeue(q);
    }

    // Free the queue structure
    free(q);

    return 0;
}

