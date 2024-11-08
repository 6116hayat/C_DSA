#include<stdio.h>
#include<stdlib.h>

// Structure Created for storing variables
struct myArray
{
    int total_size;
    int used_size;
    int *ptr;
};

// Function 
void createArray(struct myArray * a, int tSize, int uSize){
    // (*a).total_size = tSize;
    // (*a).used_size = uSize;
    // (*a).ptr = (int *) malloc(tSize*sizeof(int)); 

    a->total_size = tSize;
    a->used_size = uSize;
    a->ptr = (int *) malloc(tSize*sizeof(int)); 
}

// Function to print out the variables info
void show(struct myArray*a){
    for (int i = 0; i < a->used_size; i++)
    {
        printf("%d\n", (a->ptr)[i]);
    }
    
}

// Function to Scan out the variables info
void setVal(struct myArray*a){
    int n;
    for (int i = 0; i < a->used_size; i++)
    {
        printf("Enter element %d", i);
        scanf("%d",&n); 
        (a->ptr)[i] = n;
    }
    
}

// main runnable file
int main(){

    struct myArray marks;
    createArray(&marks, 10, 2);

    printf("We are running setVal now\n");
    setVal(&marks);

    printf("We are running show now\n");
    show(&marks);
    
    return 0;
}