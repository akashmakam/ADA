#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int linearSearch(int *array, int n, int key, int mode) {
    int flag = 0, i;
    for (i = 0; i < n; i++) {
        if (array[i] == key) {
            flag = 1;
            if (mode == 0)
                printf("The key was found at position %d of the array!\n", i + 1);
            break;
        }
    }
    if (mode == 0 && flag == 0)
        printf("The key was not found in the array!\n");
    return i;
}

void tester() {
    int n, key;
    printf("Enter the number of elements of the array: ");
    scanf("%d", &n);
    int array[n];
    printf("\nEnter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    printf("Enter the key to be searched in the array: ");
    scanf("%d", &key);
    linearSearch(array, n, key, 0);
}

void plotter() {
    srand(time(NULL));
    int n = 2, count;
    FILE *f1 = fopen("linearBest.txt", "w");
    FILE *f2 = fopen("linearWorst.txt", "w");
    FILE *f3 = fopen("linearAverage.txt", "w");
    while (n <= 1024) {
        int *array = (int *) malloc(sizeof(int)*n);

        for (int i = 0; i < n; i++) {
            array[i] = 1;
        }
        // Best case
        count = linearSearch(array, n, 1, 1);
        fprintf(f1, "%d %d\n", n, count + 1);

        // Worst case
        count = linearSearch(array, n, 0, 1);
        fprintf(f2, "%d %d\n", n, count);

        // Average case
        for (int i = 0; i < n; i++) {
            array[i] = rand() % n;
        }
        count = linearSearch(array, n, array[n/2], 1);
        fprintf(f3, "%d %d\n", n, count);
        n *= 2;
    }
    fclose(f1);
    fclose(f2);
    fclose(f3);
}

int main() {
    int option;
    printf("\nChoose any one of the following:\n"
    "1. Tester\n"
    "2. Plotter\n"
    "3. Exit\n");
    scanf("%d", &option);
    switch(option) {
        case 1: tester(); break;
        case 2: plotter(); break;
        case 3: exit(0);
        default: printf("\nInvalid option!\n");
    }
    return 0;
}