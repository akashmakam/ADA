// Program to implement Topological Sorting using Depth First Search Algorithm on directed graphs.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int vertexName;
    struct node *next;
} node;

typedef struct graph {
    int vertexCount;
    bool *visitedNodes;
    struct node **adjacencyLists;
} graph;

node *createNode(int vertexName) {
    node *newNode = (node *) malloc(sizeof(node));
    newNode -> vertexName = vertexName;
    newNode -> next = NULL;
    return newNode;
}

graph *createGraph(int numberOfVertices) {
    graph *newGraph = (graph *) malloc(sizeof(graph));
    newGraph -> vertexCount = numberOfVertices;
    newGraph -> visitedNodes = (bool *) malloc(numberOfVertices * sizeof(bool));
    newGraph -> adjacencyLists = (node **) malloc(numberOfVertices * sizeof(node *));
    for (int i = 0; i < numberOfVertices; i++) {
        newGraph -> adjacencyLists[i] = NULL;
        newGraph -> visitedNodes[i] = false;
    }
    return newGraph;
}

void freeGraph(graph *graph) {
    free(graph -> visitedNodes);
    for (int i = 0; i < graph -> vertexCount; i++) {
        node *current = graph -> adjacencyLists[i], *nextNode = NULL;
        while (current != NULL) {
            nextNode = current -> next;
            free(current);
            current = nextNode;
        }
    }
    free(graph -> adjacencyLists);
    free(graph);
}

static int count = 0, orderCount = 0;

void depthFirstSearch(graph *graph, int currentVertex, int *stack, int *stackIndex) {
    graph -> visitedNodes[currentVertex] = true;
    node *current = graph -> adjacencyLists[currentVertex];

    count++;

    while (current != NULL) {
        orderCount++;
        int connectedVertex = current -> vertexName;
        if (!graph -> visitedNodes[connectedVertex]) {
            depthFirstSearch(graph, connectedVertex, stack, stackIndex);
        }
        current = current -> next;
    }
    orderCount++;

    stack[(*stackIndex)++] = currentVertex;
}

void topologicalSort(graph *graph, int mode) {
    int *stack = (int *) malloc(graph -> vertexCount * sizeof(int));
    int stackIndex = 0;

    for (int i = 0; i < graph -> vertexCount; i++) {
        if (!graph -> visitedNodes[i]) {
            depthFirstSearch(graph, i, stack, &stackIndex);
        }
    }

    if (mode == 0) {
        printf("\nThe topological sort order is:\n");
        for (int i = stackIndex - 1; i >= 0; i--) {
            printf("%c ", stack[i] + 65);
        }
        printf("\n");
    }

    free(stack);
}

void tester() {
    int numberOfVertices, key;
    printf("\nEnter the number of vertices: ");
    scanf("%d", &numberOfVertices);
    graph *graph = createGraph(numberOfVertices);
    printf("\nEnter the adjacency list:\n");
    for (int i = 0; i < graph -> vertexCount; i++) {
        printf("\nFor vertex %c - Enter '1' if the following vertices are adjacent to it:\n", i + 65);
        for (int j = 0; j < graph -> vertexCount; j++) {
            printf("Vertex %c: ", j + 65);
            scanf("%d", &key);
            if (key == 1) {
                node *newNode = createNode(j);
                newNode -> next = graph -> adjacencyLists[i];
                graph -> adjacencyLists[i] = newNode;
            }
        }
    }

    printf("\nThe entered graph in the form of an adjacency linked list is as follows:\n");
    for (int i = 0; i < graph -> vertexCount; i++) {
        node *current = graph -> adjacencyLists[i];
        if (current == NULL)
            printf("[%c] -> NULL\n", i + 65);
        else {
            printf("[%c] -> ", i + 65);
            while (current != NULL) {
                printf("%c -> ", current -> vertexName + 65);
                if (current -> next == NULL)
                    printf("NULL\n");
                current = current -> next;
            }
        }
    }

    topologicalSort(graph, 0);

    freeGraph(graph);
}

void plotter(int mode) {
    FILE *f1 = fopen("topoBest.txt", "a");
    FILE *f2 = fopen("topoWorst.txt", "a");

    for (int i = 1; i <= 10; i++) {
        graph *graph = createGraph(i);
        for (int j = 0; j < graph -> vertexCount; j++) {
            for (int k = 0; k < graph -> vertexCount; k++) {
                // Worst Case - Fully Connected Graph
                if (mode == 0) {
                    if (j != k) {
                        node *newNode = createNode(k);
                        newNode -> next = graph -> adjacencyLists[j];
                        graph -> adjacencyLists[j] = newNode;
                    }
                // Best Case - Linear Graph
                } else if (mode == 1) {
                    if (j == k - 1) {
                        node *newNode = createNode(k);
                        newNode -> next = graph -> adjacencyLists[j];
                        graph -> adjacencyLists[j] = newNode;
                    }
                }
            }
        }
        orderCount = count = 0;
        topologicalSort(graph, 1);

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
    "2. Generate Performance Data\n");
    scanf("%d", &choice);
    switch(choice) {
        case 1: tester(); break;
        case 2:
            plotter(0);
            plotter(1);
            printf("\nGNU plot file contents ready!\n");
            break;
        default: printf("Invalid choice!\n"); break;
    }
    return 0;
}