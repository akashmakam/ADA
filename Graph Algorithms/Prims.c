#include <stdio.h>
#include <stdlib.h>

typedef struct graph {
    int vertexCount, *visitedNodes, *parent, **adjacencyMatrix;
} Graph;

Graph *createGraph(int vertexCount) {
    Graph *newGraph = (Graph *) malloc(sizeof(Graph));
    if (newGraph == NULL) {
        printf("\nMemory could not be allocated for the new graph!\n");
        exit(1);
    }
    newGraph -> vertexCount = vertexCount;
    newGraph -> visitedNodes = (int *) malloc(sizeof(int) * vertexCount);
    newGraph -> parent = (int *) malloc(sizeof(int) * vertexCount);
    newGraph -> adjacencyMatrix = (int **) malloc(sizeof(int *) * vertexCount);
    for (int i = 0; i < vertexCount; i++) {
        newGraph -> visitedNodes[i] = 0;
        newGraph -> parent[i] = -1;
        newGraph -> adjacencyMatrix[i] = (int *) calloc(vertexCount, sizeof(int));
    }
    return newGraph;
}

void prims(Graph *graph, int startingVertex) {
    int minimum = 9999;
    Graph *minimumSpanningTree = createGraph(graph -> vertexCount);
    graph -> visitedNodes[startingVertex] = 1;
    for (int i = 0; i < graph -> vertexCount; i++) {
        for (int j = 0; j < graph -> vertexCount; j++) {
            if (graph -> visitedNodes[i] && graph -> adjacencyMatrix[i][j] != -1 && graph -> adjacencyMatrix[i][j] < minimum) {
                minimum = graph -> adjacencyMatrix[i][j];
                graph -> visitedNodes[j] = 1;
            }
            minimumSpanningTree -> adjacencyMatrix[i][j] = graph -> adjacencyMatrix[i][j];
        }
    }
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
    printf("\nChoose a vertex to start the depth first search: ");
    scanf("%d", &startingVertex);
    printf("\nThe depth first search sequence is as follows:\n");
    depthFirstSearch(graph, startingVertex, 0);

    freeGraph(graph);
}