// Bubble Sort

#include <stdio.h>

void read(int *array, int n) {
    printf("\nEnter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
}

void display(int *array, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d\t", array[i]);
    }
    printf("\n");
}

void insertionSort(int *array, int n) {
    for (int i = 1; i < n; i++) {
        int key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
    printf("\nThe sorted elements of the array are:\n");
    display(array, n);
}

// Driver Code
int main() {
    int n;
    printf("\nEnter the size of the array: ");
    scanf("%d", &n);
    int array[n];
    read(array, n);
    printf("\nThe entered elements of the array are:\n");
    display(array, n);
    insertionSort(array, n);
    return 0;
}