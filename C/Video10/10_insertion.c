#include <stdio.h>

// Creating an display function
void display(int arr[], int n)
{

    // Traversal Operation Used
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Creating Insertion function
int indInsertion(int arr[], int size, int element, int capacity, int index)
{
    if (size >= capacity){
        return -1;
    }
    for (int i = size - 1; i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[index] = element;
    return 1;
}

int main()
{
    // Declaring array
    int arr[100] = {7, 8, 12, 27, 88};
    int size = 5;
    int element = 45;
    int index = 3;
    display(arr, size);
    indInsertion(arr, size, element, 100, index);
    size += 1;
    display(arr, size);

    return 0;
}