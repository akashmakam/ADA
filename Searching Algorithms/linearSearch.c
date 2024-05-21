// Linear Search

#include <stdio.h>

void read(int *array, int n) {
    printf("\nEnter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
}

void display(int *array, int n) {
    printf("\nThe entered elements of the array are:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t", array[i]);
    }
    printf("\n");
}

int linearSearch(int *array, int n, int key) {
    for (int i = 0; i < n; i++) {
        if (array[i] == key)
            return i+1;
    }
    return -1;
}

int main() {
    int n, key, position;
    printf("\nEnter the size of the array: ");
    scanf("%d", &n);
    int array[n];
    read(array, n);
    display(array, n);
    printf("\nEnter the key to be searched in the array: ");
    scanf("%d", &key);
    position = linearSearch(array, n, key);
    (position != -1)? printf("\nThe key was found at position %d in the array.\n", position):
        printf("\nThe key was not found within the array elements!\n");
    return 0;
}