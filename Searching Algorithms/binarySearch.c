// Binary Search

#include <stdio.h>

int count = 0;

void read(int *array, int n) {
    printf("\nEnter the elements of the array:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &array[i]);
}

void display(int *array, int n) {
    printf("\nThe entered elements of the array are:\n");
    for (int i = 0; i < n; i++)
        printf("%d\t", array[i]);
    printf("\n");
}

// Iterative approach
/*
int binarySearch(int *array, int n, int key, int start, int end) {
    int mid;
    count = 0;
    while (start <= end) {
        count++;
        mid = (start + end)/2;  
        if (key == array[mid])
            return mid;
        else if (key > array[mid])
            start = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}
*/

// Recursive approach
int binarySearch(int *array, int n, int key, int start, int end) {
    if (start > end)
        return -1;
    int mid = (start + end) / 2;
    count++;
    if (key == array[mid])
        return mid;
    else if (key > array[mid])
        return binarySearch(array, n, key, mid + 1, end);
    else
        return binarySearch(array, n, key, start, mid - 1);
}

int main() {
    int n, key, position;
    printf("\nEnter the size of the array: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Array size must be positive.\n");
        return 1;
    }
    int array[n];
    read(array, n);
    display(array, n);
    printf("\nEnter a key to be searched in the array: ");
    scanf("%d", &key);
    position = binarySearch(array, n, key, 0, n - 1);
    if (position != -1)
        printf("\nThe key was found at position %d of the array.\n", position);
    else
        printf("\nThe key was not found within the array elements!\n");
    printf("To search the key element, %d function calls occurred.\n", count);
    return 0;
}