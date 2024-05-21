/*
Program to implement searching algorithms such as linear and binary search to find an element in an array.
*/

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

int linearSearch(int *array, int n, int key) {
    for (int i = 0; i < n; i++) {
        if (array[i] == key)
            return i;
    }
    return -1;
}

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

// Driver Code
int main() {
    int n, key, position, option;
    printf("\nEnter the size of the array: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Array size must be positive.\n");
        return 1;
    }
    int array[n];
    read(array, n);
    display(array, n);
    while (1) {
        printf("\nChoose any one of the searching algorithms to find the specific element:\n"
        "1. Linear search\n"
        "2. Binary search\n"
        "3. Exit\n");
        scanf("%d", &option);
        if (option == 3)
            return 0;
        printf("\nEnter a key to be searched in the array: ");
        scanf("%d", &key);
        switch(option) {
            case 1:
                position = linearSearch(array, n, key);
                if (position != -1)
                    printf("\nThe key was found at position %d of the array.\n", position);
                else
                    printf("\nThe key was not found within the array elements!\n");
                break;
            case 2:
                position = binarySearch(array, n, key, 0, n - 1);
                if (position != -1)
                    printf("\nThe key was found at position %d of the array.\n", position);
                else
                    printf("\nThe key was not found within the array elements!\n");
                printf("To search the key element, %d function calls occurred.\n", count);
                count = 0;
                break;
            default:
                printf("\nInvalid option!\n");
        }
    }
    return 0;
}