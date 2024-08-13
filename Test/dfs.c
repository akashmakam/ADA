#include <stdio.h>
#include <stdlib.h>

typedef struct graph {
    int vertexCount;
    int *visitedNodes;
    int **adjacencyMatrix;
    int *parent;
} graph;

graph *createGraph(int vertexCount) {
    graph *newGraph = (graph *) malloc(sizeof(graph));
    newGraph -> vertexCount = vertexCount;
    newGraph -> visitedNodes = (int *) malloc(vertexCount * sizeof(int));
    newGraph -> parent = (int *) malloc(vertexCount * sizeof(int));
    newGraph -> adjacencyMatrix = (int **) malloc(vertexCount * sizeof(int *));
    for (int i = 0; i < vertexCount; i++) {
        newGraph -> parent[i] = -1;
        newGraph -> visitedNodes[i] = 0;
        newGraph -> adjacencyMatrix[i] = (int *) calloc(vertexCount, sizeof(int));
    }
    return newGraph;
}

void freeGraph(graph *graph) {
    free(graph -> visitedNodes);
    free(graph -> parent);
    for (int i = 0; i < graph -> vertexCount; i++) {
        free(graph -> adjacencyMatrix[i]);
    }
    free(graph -> adjacencyMatrix);
    free(graph);
}

static int count = 0, orderCount = 0, isCyclic = 0;

void depthFirstSearch(graph *graph, int currentVertex, int mode) {
    graph -> visitedNodes[currentVertex] = 1;
    count++;
    if (mode == 0)
        printf(" -> %c", currentVertex + 65);
    for (int i = 0; i < graph -> vertexCount; i++) {
        if (graph -> adjacencyMatrix[currentVertex][i] == 1) {
            orderCount++;
            if (!(graph -> visitedNodes[i])) {
                graph -> parent[i] = currentVertex;
                depthFirstSearch(graph, i, mode);
            } else if (graph -> visitedNodes[currentVertex] != i) {
                isCyclic = 1;
            }
        }
    }
    orderCount++;
}

void tester() {
    int vertexCount, key;
    printf("\nEnter the number of vertices of the graph: ");
    scanf("%d", &vertexCount);
    graph *graph = createGraph(vertexCount);

    printf("\nEnter the adjacency matrix:\n");
    for (int i = 0; i < vertexCount; i++) {
        for (int j = 0; j < vertexCount; j++) {
            printf("Is there an edge between %c and %c (1/0): ", i + 65, j + 65);
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

    int startingVertex;
    printf("\nChoose a vertex to start the breadth first search: ");
    scanf("%d", &startingVertex);
    printf("\nThe breadth first search sequence is as follows:\n");
    depthFirstSearch(graph, startingVertex, 0);

    if (isCyclic)
        printf("\n\nThe input graph is cyclic.\n");
    else
        printf("\n\nThe input graph is not cyclic.\n");
    if (count == vertexCount)
        printf("The input graph is connected.\n");
    else
        printf("The input graph is not connected.\n");

    freeGraph(graph);
}

void plotter(int mode) {
    FILE *f1 = fopen("dfsBest.txt", "a");
    FILE *f2 = fopen("dfsWorst.txt", "a");
    for (int k = 1; k <= 10; k++) {
        graph *graph = createGraph(k);
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                if (mode == 0) {
                    if (i != j)
                        graph -> adjacencyMatrix[i][j] = 1;
                } else {
                    if (i == (j - 1))
                        graph -> adjacencyMatrix[i][j] = 1;
                }
            }
        }
        orderCount = count = 0;
        depthFirstSearch(graph, 0, 1);
        if (mode == 0)
            fprintf(f2, "%d\t%d\n", k, orderCount);
        else
            fprintf(f1, "%d\t%d\n", k, orderCount);
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