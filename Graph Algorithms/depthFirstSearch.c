// Program to implement Depth First Search Algorithm on undirected graphs.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int vertexName;
    struct node *next;
} node;

typedef struct graph {
    int vertexCount;
    int *parent;
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
    newGraph -> parent = (int *) malloc(newGraph -> vertexCount * sizeof(int));
    for (int i = 0; i < numberOfVertices; i++) {
        newGraph -> adjacencyLists[i] = NULL;
        newGraph -> visitedNodes[i] = false;
        newGraph -> parent[i] = -1;
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
    free(graph -> parent);
    free(graph);
}

static bool isCyclic = false;
static int count = 0, orderCount = 0;

void depthFirstSearch(graph *graph, int currentVertex, int mode) {
    struct node* adjacencyList = graph -> adjacencyLists[currentVertex];
    struct node* current = adjacencyList;

    count++;
    graph -> visitedNodes[currentVertex] = true;
    if (mode == 0)
        printf(" -> %c", currentVertex + 65);

    while (current != NULL) {
        orderCount++;
        int connectedVertex = current -> vertexName;
        if (graph -> visitedNodes[connectedVertex] == false) {
            graph -> parent[connectedVertex] = currentVertex;
            depthFirstSearch(graph, connectedVertex, mode);
        } else if (graph -> parent[currentVertex] != connectedVertex) {
            isCyclic = true;
        }
        current = current -> next;
    }

    orderCount++;
}

void tester() {
    int numberOfVertices, key, startingVertex;
    printf("\nEnter the number of vertices: ");
    scanf("%d", &numberOfVertices);
    graph *graph = createGraph(numberOfVertices);
    printf("\nEnter the adjacency list:");
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
        printf("[%c] -> ", i + 65);
        while (current != NULL) {
            printf("%c -> ", current -> vertexName + 65);
            if (current -> next == NULL)
                printf("NULL\n");
            current = current -> next;
        }
    }

    printf("\nEnter the vertex from which the graph should be traversed from: ");
    scanf("%d", &startingVertex);
    printf("\nThe depth first search sequence is as follows:\n");
    depthFirstSearch(graph, startingVertex, 0);

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
    FILE *f1 = fopen("dfsBest.txt", "a");
    FILE *f2 = fopen("dfsWorst.txt", "a");

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
        depthFirstSearch(graph, 0, 1);

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