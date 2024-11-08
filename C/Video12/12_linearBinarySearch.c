#include <stdio.h>

// Function for Linear Search
int linearSearch(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return -1;
}

// Function for Binary Search
int binarySearch(int arr[], int size, int element)
{
    int low, mid, high;

    low = 0;
    high = size - 1;

    // Start Searching
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == element)
        {
            return mid;
        }

        if (arr[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    // Searching ends
    return -1;
}

int main()
{
    // Unsorted Array for linear search
    // int arr[] = {1, 3, 5, 100, 102, 150, 56, 4, 78};
    // int size = sizeof(arr) / sizeof(int);

    // Sorted Array for Binary search
    int arr[] = {1, 3, 5, 56, 4, 78, 100, 102, 150};
    int size = sizeof(arr) / sizeof(int);

    int element = 100;
    int searchIndex = binarySearch(arr, size, element);
    printf("The element %d was found at index %d \n", element, searchIndex);

    return 0;
}