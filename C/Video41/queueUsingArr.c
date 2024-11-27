#include<stdio.h>
#include<stdlib.h> 

// structure for the Queue
struct queue{
    int size;
    int f;
    int r;
    int * arr;
};

// isFull Function
int isFull(struct queue * q){
    if(q->r==q->size-1){
        return 1; // true
    }else{
        return 0; // false
    }
}

// isEmpty function
int isEmpty(struct queue * q){
    if(q->f == q->r){
        return 1; //true
    }else{
        return 0; // false
    }
}

// Enqueue Function
void enqueue(struct queue * q, int val){
    if(isFull(q)){
        printf("This Queue is Full \n");
    }else{
        q->r = q->r +1;
        q->arr[q->r] = val;
        printf("Inserted %d \n", val);
    }
}

// Dequeue Function
int dequeue(struct queue * q){
    int a = -1; // if Empty it will give -1
    if(isEmpty(q)){
        printf("No element to Dequeue \n");
    }else{
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}

// print Function
void printQueue(struct queue * q){
    if(isEmpty(q)){
        printf("The Queue is Empty\n");
    }else{
        printf("Queue Elements are: \n");
        for(int i = q->f +1; i <= q->r; i++){
            printf("%d ", q->arr[i]);
        }
        printf("\n");
    }
}

int main() {

    struct queue q;
    q.size = 100;
    q.f = q.r = -1;
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