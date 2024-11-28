#include<stdio.h>
#include<stdlib.h>

// structure for the Queue
struct circularQueue{
    int size;
    int f;
    int r;
    int * arr;
};


// isFull Function
int isFull(struct circularQueue * q){
    if((q->r + 1)%q->size == q->f){
        return 1; // true
    }else{
        return 0; // false
    }
}

// isEmpty function
int isEmpty(struct circularQueue * q){
    if(q->f == q->r){
        return 1; //true
    }else{
        return 0; // false
    }
}

// Enqueue Function
void enqueue(struct circularQueue * q, int val){
    if(isFull(q)){
        printf("Queue Overflow");
    }
    else{
        q->r = (q->r +1) % q->size;
        q->arr[q->r]=val;
    }
}

// Dequeue Function
int dequeue(struct circularQueue * q){
    int val = -1;
    if(isEmpty(q)){
        printf("Empty Queue");
    }
    else{
        q->f = (q->f +1)% q->size;
        val = q->arr[q -> f];
    }
    return val;
}

// print Function
void printQueue(struct circularQueue * q){
    if(isEmpty(q)){
        printf("The Queue is Empty\n");
    }else{
        printf("Queue Elements are: \n");
        int i = (q->f + 1)% q-> size;
        while(i != (q->r +1)%q->size){
            printf("%d ",q->arr[i]);
            i = (i + 1)%q-> size;
        }
        printf("\n");
    }
}

int main() {

    struct circularQueue q;
    q.size = 5;
    q.f = 0;
    q.r = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));

    // Test the function
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    printQueue(&q);

    dequeue(&q);
    printQueue(&q);

    enqueue(&q, 65);
    printQueue(&q);

    return 0;
}