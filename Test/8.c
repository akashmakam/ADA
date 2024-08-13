#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct graph {
    int vertexCount;
    bool *visitedNodes;
    int **adjacencyMatrix;
} graph;

graph *createGraph(int numberOfVertices) {
    graph *newGraph = (graph *)malloc(sizeof(graph));
    newGraph->vertexCount = numberOfVertices;
    newGraph->visitedNodes = (bool *)malloc(numberOfVertices * sizeof(bool));
    newGraph->adjacencyMatrix = (int **)malloc(numberOfVertices * sizeof(int *));
    for (int i = 0; i < numberOfVertices; i++) {
        newGraph->adjacencyMatrix[i] = (int *)calloc(numberOfVertices, sizeof(int));
        newGraph->visitedNodes[i] = false;
    }
    return newGraph;
}

void freeGraph(graph *graph) {
    free(graph->visitedNodes);
    for (int i = 0; i < graph->vertexCount; i++) {
        free(graph->adjacencyMatrix[i]);
    }
    free(graph->adjacencyMatrix);
    free(graph);
}

static int isCyclic = 0, count = 0, orderCount = 0;

void breadthFirstSearch(graph *graph, int startingVertex, int mode) {
    int *queue = (int *)malloc(graph->vertexCount * sizeof(int));
    int *parent = (int *)malloc(graph->vertexCount * sizeof(int));
    int front = -1, rear = -1;

    if (mode == 0) {
        isCyclic = count = orderCount = 0;
    }

    for (int i = 0; i < graph->vertexCount; i++) {
        graph->visitedNodes[i] = false;
        parent[i] = -1;
    }

    graph->visitedNodes[startingVertex] = true;
    queue[++rear] = startingVertex;
    count++;

    while (front != rear) {
        int currentVertex = queue[++front];
        if (mode == 0) {
            printf(" -> %c", currentVertex + 65);
        }

        for (int i = 0; i < graph->vertexCount; i++) {
            if (graph->adjacencyMatrix[currentVertex][i] == 1) { // Check for adjacency
                orderCount++;
                if (graph->visitedNodes[i] == false) {
                    graph->visitedNodes[i] = true;
                    parent[i] = currentVertex;
                    queue[++rear] = i;
                    count++;
                } else if (parent[currentVertex] != i) {
                    isCyclic = 1;
                }
            }
        }
    }

    free(queue);
    free(parent);
}

void tester() {
    int numberOfVertices, key, startingVertex;
    printf("\nEnter the number of vertices: ");
    scanf("%d", &numberOfVertices);
    graph *graph = createGraph(numberOfVertices);

    printf("\nEnter the adjacency matrix:\n");
    for (int i = 0; i < graph->vertexCount; i++) {
        for (int j = 0; j < graph->vertexCount; j++) {
            printf("Is there an edge between %c and %c (1/0): ", i + 65, j + 65);
            scanf("%d", &key);
            graph->adjacencyMatrix[i][j] = key;
        }
    }

    printf("\nThe entered graph in the form of an adjacency matrix is as follows:\n");
    for (int i = 0; i < graph->vertexCount; i++) {
        printf("[%c] -> ", i + 65);
        for (int j = 0; j < graph->vertexCount; j++) {
            printf("%d ", graph->adjacencyMatrix[i][j]);
        }
        printf("\n");
    }

    printf("\nEnter the vertex from which the graph should be traversed from: ");
    scanf("%d", &startingVertex);
    printf("\nThe breadth first search sequence is as follows:\n");
    breadthFirstSearch(graph, startingVertex, 0);

    if (isCyclic)
        printf("\n\nThe entered graph is cyclic!\n");
    else
        printf("\n\nThe entered graph is not cyclic!\n");

    if (count == numberOfVertices)
        printf("The entered graph is connected!\n");
    else
        printf("The entered graph is not connected!\n");

    freeGraph(graph);
}

void plotter(int mode) {
    FILE *f1 = fopen("bfsBest.txt", "a");
    FILE *f2 = fopen("bfsWorst.txt", "a");

    for (int i = 1; i <= 10; i++) {
        graph *graph = createGraph(i);
        for (int j = 0; j < graph->vertexCount; j++) {
            for (int k = 0; k < graph->vertexCount; k++) {
                if (mode == 0) {
                    if (j != k) {
                        graph->adjacencyMatrix[j][k] = 1; // Fully Connected Graph
                    }
                } else if (mode == 1) {
                    if (j == k - 1) {
                        graph->adjacencyMatrix[j][k] = 1; // Linear Graph
                    }
                }
            }
        }
        orderCount = count = i;
        breadthFirstSearch(graph, 0, 1);

        if (mode == 1)
            fprintf(f1, "%d\t%d\n", i, orderCount);
        else if (mode == 0)
            fprintf(f2, "%d\t%d\n", i, orderCount);
        freeGraph(graph);
    }
    fclose(f1);
    fclose(f2);
}

int main() {
    int choice;
    printf("\nChoose any one of the following options:\n"
           "1. Tester\n"
           "2. Plotter\n");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            tester();
            break;
        case 2:
            plotter(0);
            plotter(1);
            printf("\nGNU plot file contents ready!\n");
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }
    return 0;
}