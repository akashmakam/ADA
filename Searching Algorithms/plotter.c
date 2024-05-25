// Plotter code

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count = 0;

// Function to perform a linear search for 'key' in 'array' of size 'n'
// Returns the index of 'key' if found, otherwise returns -1
int linearSearch(int *array, int n, int key) {
    for (int i = 0; i < n; i++) {
        if (array[i] == key)
            return i+1;
    }
    return n;
}

// Function to perform a binary search for 'key' in 'array' of size 'n'
// within the range from 'start' to 'end'
// Returns the index of 'key' if found, otherwise returns -1
int binarySearch(int *array, int n, int key, int start, int end) {
    if (start > end)
        return n - 1;
    int mid = (start + end) / 2;
    count++;
    if (key == array[mid])
        return mid;
    else if (key > array[mid])
        return binarySearch(array, n, key, mid + 1, end);
    else
        return binarySearch(array, n, key, start, mid - 1);
}

// Function to plot the performance of the linear search algorithm
void linearSearchPlotter() {
    srand(time(NULL));
    int *arr;
    int n = 2, key, r;
    FILE *f1, *f2, *f3;
    f1 = fopen("linearbest.txt", "a");
    f2 = fopen("linearavg.txt", "a");
    f3 = fopen("linearworst.txt", "a");

    while (n <= 1024) {
        arr = (int *)malloc(n * sizeof(int));

        // Best case: key is the first element
        for (int i = 0; i < n; i++)
            arr[i] = 1; // Fills the array with 1's
        r = linearSearch(arr, n, 1); // Performs linear search on the array with 1 as the key
        fprintf(f1, "%d\t%d\n", n, r); // Appends the position of the found key into the file

        // Average case: key is a random element
        for (int i = 0; i < n; i++)
            arr[i] = rand() % n; // Fills the array with random numbers
        key = arr[n/2]; // Generates a random key to be searched
        r = linearSearch(arr, n, key); // Performs linear search on the array with a random key
        fprintf(f2, "%d\t%d\n", n, r); // Appends the position of the found key into the file

        // Worst case: key is not present
        for (int i = 0; i < n; i++)
            arr[i] = 0; // Fills the array with 0's
        r = linearSearch(arr, n, 1); // Performs linear search on the array with 1 as the key
        fprintf(f3, "%d\t%d\n", n, r); // Appends the position of the found key into the file

        n = n * 2;
        free(arr);
    }

    fclose(f1);
    fclose(f2);
    fclose(f3);
}

// Function to plot the performance of the binary search algorithm
void binarySearchPlotter() {
    srand(time(NULL));
    int *arr;
    int n, key, r;
    FILE *f1, *f2, *f3;
    f1 = fopen("binarybest.txt", "a");
    f2 = fopen("binaryavg.txt", "a");
    f3 = fopen("binaryworst.txt", "a");

    n = 2;
    while (n <= 1024) {
        arr = (int *)malloc(n * sizeof(int));

        // Best case: key is the middle element
        for (int i = 0; i < n; i++)
            arr[i] = i;
        int mid = (n - 1) / 2;
        key = arr[mid];
        count = 0;
        r = binarySearch(arr, n, key, 0, n - 1);
        fprintf(f1, "%d\t%d\n", n, count);

        // Average case: key is a random element
        for (int i = 0; i < n; i++)
            arr[i] = i;
        key = arr[n/2];
        count = 0;
        r = binarySearch(arr, n, key, 0, n - 1);
        fprintf(f2, "%d\t%d\n", n, count);

        // Worst case: key is not present
        for (int i = 0; i < n; i++)
            arr[i] = i;
        key = n + 1; // Key not present in the array
        count = 0;
        r = binarySearch(arr, n, key, 0, n - 1);
        fprintf(f3, "%d\t%d\n", n, count);

        n = n * 2;
        free(arr);
    }

    fclose(f1);
    fclose(f2);
    fclose(f3);
}

// Main function to call the plotter functions
int main() {
    linearSearchPlotter();
    binarySearchPlotter();
    return 0;
}