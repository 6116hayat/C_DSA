#include<stdio.h>


// function for the printing Array
void printArray(int* arr, int n){
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// function for the Adaptive Bubble Sort
void bubbleSortAdaptive(int* arr, int n){
    int temp;
    int isSorted;

    for(int i = 0; i < n-1; i++){ // for number of passes
        printf("Working on pass no %d\n", i + 1);
        isSorted = 1;

        for(int j = 0; j < n - 1 - i; j++){ // for comparison in each pass
            if(arr[j] > arr[j + 1]){
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                isSorted = 0;
            }
        }
        // check if the array is sorted
        if(isSorted){
            return;
        }
    }
}


// function for the Bubble Sort
void bubbleSort(int* arr, int n){
    int temp;

    for(int i = 0; i < n-1; i++){ // for number of passes
        for(int j = 0; j < n - 1 - i; j++){ // for comparison in each pass
            if(arr[j] > arr[j + 1]){
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {

    int arr[] = {12, 54, 65, 7, 23, 9};

    int arr2[] = {4, 15, 47, 98, 102, 110};

    int n = 6;

    // for array 1
    printf("Array before Sort\n");
    printArray(arr, n);

    printf("\n");
    bubbleSort(arr, n);

    printf("Array after Sort\n");
    printArray(arr, n);

    printf("\n");
    
    // for array 2 
    printf("Array2 before Adaptive Sort\n");
    printArray(arr2, n);

    printf("\n");
    bubbleSortAdaptive(arr2, n);

    printf("Array2 after Adaptive Sort\n");
    printArray(arr2, n);


    return 0;
}