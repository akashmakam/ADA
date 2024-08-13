#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct graph {
    int vertexCount;
    int **adjacencyMatrix;
    int *inDegree;
} graph;

graph *createGraph(int vertexCount) {
    graph *newGraph = (graph *) malloc(sizeof(graph));
    newGraph->vertexCount = vertexCount;
    newGraph->inDegree = (int *) calloc(vertexCount, sizeof(int));
    newGraph->adjacencyMatrix = (int **) malloc(vertexCount * sizeof(int *));
    for (int i = 0; i < vertexCount; i++) {
        newGraph->adjacencyMatrix[i] = (int *) calloc(vertexCount, sizeof(int));
    }
    return newGraph;
}

void freeGraph(graph *graph) {
    free(graph->inDegree);
    for (int i = 0; i < graph->vertexCount; i++) {
        free(graph->adjacencyMatrix[i]);
    }
    free(graph->adjacencyMatrix);
    free(graph);
}

int count = 0;

void sourceRemovalTopologicalSort(graph *graph, int mode) {
    int *inDegree = graph->inDegree;
    int vertexCount = graph->vertexCount;
    int *zeroInDegreeQueue = (int *) malloc(vertexCount * sizeof(int));
    int front = 0, rear = -1;
    int *topologicalOrder = (int *) malloc(vertexCount * sizeof(int));
    int topologicalIndex = 0;

    // Calculate in-degrees
    for (int i = 0; i < vertexCount; i++) {
        for (int j = 0; j < vertexCount; j++) {
            if (graph->adjacencyMatrix[j][i] == 1) {
                inDegree[i]++;
            }
        }
    }

    // Find all vertices with zero in-degree
    for (int i = 0; i < vertexCount; i++) {
        if (inDegree[i] == 0) {
            zeroInDegreeQueue[++rear] = i;
        }
    }

    // Process vertices with zero in-degree
    while (front <= rear) {
        int vertex = zeroInDegreeQueue[front++];
        topologicalOrder[topologicalIndex++] = vertex;
        for (int i = 0; i < vertexCount; i++) {
            count++;
            if (graph->adjacencyMatrix[vertex][i] == 1) {
                inDegree[i]--;
                if (inDegree[i] == 0) {
                    zeroInDegreeQueue[++rear] = i;
                }
            }
        }
    }

    if (mode == 0) {
        printf("\nThe topological sort order is:\n");
        for (int i = 0; i < topologicalIndex; i++) {
            printf("-> %c ", topologicalOrder[i] + 65);
        }
        printf("\n");
    }

    free(zeroInDegreeQueue);
    free(topologicalOrder);
}

void tester() {
    int vertexCount, key;
    printf("\nEnter the number of vertices of the graph: ");
    scanf("%d", &vertexCount);
    graph *graph = createGraph(vertexCount);

    printf("\nEnter the adjacency matrix:\n");
    for (int i = 0; i < vertexCount; i++) {
        for (int j = 0; j < vertexCount; j++) {
            printf("Is there an edge from %c to %c (1/0): ", i + 65, j + 65);
            scanf("%d", &key);
            graph->adjacencyMatrix[i][j] = key;
        }
        printf("\n");
    }

    printf("\nThe entered graph in the form of an adjacency matrix is as follows:\n");
    for (int i = 0; i < vertexCount; i++) {
        printf("[%c] -> ", i + 65);
        for (int j = 0; j < graph->vertexCount; j++) {
            printf("%d ", graph->adjacencyMatrix[i][j]);
        }
        printf("\n");
    }

    printf("\nPerforming topological sort using source removal algorithm:\n");
    sourceRemovalTopologicalSort(graph, 0);

    freeGraph(graph);
}

void plotter(int mode) {
    FILE *f1 = fopen("sourceBest.txt", "a");
    FILE *f2 = fopen("sourceWorst.txt", "a");
    for (int k = 1; k <= 10; k++) {
        graph *graph = createGraph(k);
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                if (mode == 0) {
                    if (i != j) {
                        graph->adjacencyMatrix[i][j] = 1;
                    }
                } else {
                    graph->adjacencyMatrix[i][i + 1] = 1;
                }
            }
        }
        count = 0;
        sourceRemovalTopologicalSort(graph, 1);
        if (mode == 1)
            fprintf(f2, "%d\t%d\n", k, count);
        else
            fprintf(f1, "%d\t%d\n", k, count);
        freeGraph(graph);
    }
    fclose(f1);
    fclose(f2);
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
        case 2: plotter(0); plotter(1); break;
        case 3: exit(0);
        default: printf("\nInvalid option!\n");
    }
    return 0;
}