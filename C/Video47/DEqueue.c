#include<stdio.h>
#include<stdlib.h>

// creating Node structure for front and rear
struct Node * f = NULL;
struct Node * r = NULL;

// Defining Node Structure
struct Node {
    int data;
    struct Node * next;
};

// printing Function
void printLinkedList(struct Node * ptr){
    printf("Printing the elements of LinkedList\n");;
    while(ptr != NULL){
        printf("Element: %d\n", ptr-> data);
        ptr = ptr -> next;
    }
}

// enqueue from Rear function
void enqueueR(int val){
    struct Node * n = (struct Node *)malloc(sizeof(struct Node));
    if(n ==  NULL){
        printf("Queue is NULL\n");
    }
    else{
        n->data = val;
        n->next = NULL;
        if(f == NULL){
            f = r = n;
        }
        else{
            r->next = n;
            r = n;
        }
    }
}

// dequeue from Front function
int dequeueF(){
    int val = -1;
    struct Node * ptr = f;

    if(f == NULL){
        printf("Queue is Empty\n");
    }
    else{
        f = f->next;
        val = ptr->data;
        free(ptr);
        return(val);
    }
}

// Enqueue from Front function
void enqueueF(int val){
    struct Node * n = (struct Node *)malloc(sizeof(struct Node));
    if(f == -1){
        printf("front is at -1, nothing can be added\n");
    }
    else{
        n->data = val;

    }
}

// Dequeue from Rear fucntion
int dequeueR(){
    
}

int main() {
    
    return 0;
}