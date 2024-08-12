#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void tester() {
    int n, count = 0;
    printf("\nEnter the number of vertices:\n");
    scanf("%d", &n);
    int array[n][n];

    printf("\nEnter the elements of the directed graph (adjacency matrix):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &array[i][j]);
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                count++;
                array[i][j] = (array[i][j] || (array[i][k] && array[k][j]));
            }
        }
    }

    printf("\nApplying Warshall's algorithm, we get the transitive closure of the graph as:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", array[i][j]);
        }
        printf("\n");
    }

    printf("\nThe number of passes required is %d.", count);
}

void plotter() {
    int count, n = 1;
    FILE *f1;
    srand(time(NULL));
    f1 = fopen("warshallWorst.txt", "w");
    while (n != 10) {
        count = 0;
        int array[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j)
                    array[i][j] = 1;
                else
                    array[i][j] = 0;
            }
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    count++;
                    array[i][j] = (array[i][j] || (array[i][k] && array[k][j]));
                }
            }
        }
        fprintf(f1, "%d %d\n", n, count);
        n++;
    }
    fclose(f1);
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