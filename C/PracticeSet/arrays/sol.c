#include<stdio.h>
#include<limits.h>
#include<stdbool.h>

// Program to print the arr
void printArray(int arr[], int size){

    for(int i =0; i < size; i++){
        printf("%d\n",arr[i]);
    }
    printf("\n");
}

// 1) Given an array of integers, print all the elements.
void oneSol(){

    printf("Ques.1: Given an array of integers, print all the elements. \n");
    printf("\n");

    // Creating an Array:
    int arr[] = {8,12,14,16,20};
    int size = sizeof(arr)/sizeof(arr[0]);

    for(int i = 0; i < size; i++){
        printf("%d\n",arr[i]);
    }
}

// 2) Insert the number 42 at the third position in an array.
void twoSol(){

    printf("Ques.2: Insert the number 42 at the third position in an array.\n");
    printf("\n");

    // Creating an Array:
    int arr[10] = {1,2,3,4,5};
    int size = 5;

    printArray(arr, size);

    int element = 42; 
    int index = 3;

    if(size >= 10 ){
        printf("Error: Array is full \n");
        return;
    }

    for(int i = size; i > index; i--){
        arr[i] = arr[i - 1];
    }
    arr[index] = element;
    size++; 

    printArray(arr, size);
}

// 3) Remove the element at the fifth position from an array.
void threeSol(){
    printf("Ques.3: Remove the element at the fifth position from an array.\n");
    printf("\n");

    // Creating an Array:
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = 9;

    printArray(arr, size);

    // int element = 42; 
    int index = 4;

    if(index >= size ){
        printf("Error: Index Out of Bound \n");
        return;
    }

    for(int i = index; i < size - 1; i++){
        arr[i] = arr[i + 1];
    }
    size--; 

    printArray(arr, size);
}

// 4) Find the maximum number in this array: [23, 45, 67, 89, 12].
void fourSol(){

    printf("Program to find max number within an array\n");
    printf("\n");


    int max = INT_MIN; // (negative int assign for the max function)

    int size = 5;

    // Declaring an Array
    int arr[] = {23, 45, 67, 89, 12};

    // Printing an array
    printArray(arr, size);

    for(int i = 0; i <= 5; i++){
        if(arr[i]> max){
            max =arr[i];
        }
    }
    printf("The %d num is Maximum in Array\n", max);


}

// 5) Check if the number 15 is in this array: [3, 6, 9, 12, 15, 18].
void fiveSol(){

    printf("Program to check given number is in the Array: \n");
    printf("\n");

    int size = 6;

    // Declaring the array
    int arr[] = {3, 6, 9, 12, 15, 18};

    printArray(arr, size);

    int element = 15;

    for (int i = 0; i <= size; i++){
        if(arr[i] = element){
            printf("%d is found at index %d", element, i);
        }else{
            printf("Element Not found!!");
        }
    }
    


}

// 6) Find the sum of all the elements in this array: [3, 6, 9, 12, 15, 18].
void sixSol(){

    printf("Program Prints the sum of all the numbers in array\n\n");

    int size = 6;

    // Declaring the array 
    int arr[] = {3, 6, 9, 12, 15, 18};

    printArray(arr, size);

    int sum =  0;

    for(int i = 0; i <= size -1; i++){
        sum += arr[i];
    }
    printf("Sum of all the elements in arrays = %d", sum);

}

// 7) Implement binary search to find the position of the number 7 in this sorted array: [1, 3, 5, 7, 9].
void sevenSol(){

    printf("Program is to find position of num 7  in the Array \n\n");

    int size = 5;

    int arr[] = {1,3,5,7,9};

    printArray(arr, size);

    int start = 0, end = size -1, mid, find = 7, result = -1;

    while (start <= end){

        int mid = start + ((end - start)/2);

        if(arr[mid]== find){
            result = mid;
            break;
        }

        if(arr[mid] < find){
            start = mid +1;
        }
        else{
            end = mid -1 ;
        }
    }

    if(result == -1 ){
        printf("Element not found in array");
    }else{
        printf("Element found at position %d in array ", result);
    }

}

// 8) Reverse the order of elements in this array: [10, 20, 30, 40, 50].
void eightSol(){

    printf("Program to print the reverse of the array\n\n");

    int size = 5;

    int arr[] = {10, 20, 30, 40, 50};

    printf("Original Array\n");
    printArray(arr, size);

    int start = 0, end =  size -1;

    while( start < end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start ++ ;
        end --;
    }

    printf("Reversed Array\n");

    printArray(arr, size);
}

// 10) Find the position of number 42 using linear search in [15, 8, 31, 42, 23, 87].
void tenSol(){

    printf("Program to find element using linear search\n\n");

    int size = 6;

    int arr[] = {15, 8, 31, 42, 23, 87};

    printArray(arr, size);

    int find = 42;
    bool found  = false;

    for(int i = 0; i <  size; i++){
        if(find  == arr[i]){
            printf("%d found at index %d ", find, i);
            found = true;
            break;
        }
    }
    if (found = false) {
        printf("Element not found in the array\n");
    }
}


int main() {

    // oneSol();
    // twoSol();
    // threeSol();
    // fourSol();
    // fiveSol();
    // sixSol();
    // sevenSol();
    // eightSol();
    tenSol();

    return 0;
}