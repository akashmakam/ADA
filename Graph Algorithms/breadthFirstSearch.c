// Program to implement Breadth First Search Algorithm on undirected graphs.

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

static int isCyclic = 0, count = 0, orderCount = 0;

void breadthFirstSearch(graph *graph, int startingVertex, int mode) {
    int *queue = (int *) malloc(graph -> vertexCount * sizeof(int));
    int *parent = (int *) malloc(graph -> vertexCount * sizeof(int));
    int front = -1, rear = -1;

    if (mode == 0) {
        isCyclic = count = orderCount = 0;
    }

    for (int i = 0; i < graph -> vertexCount; i++) {
        graph -> visitedNodes[i] = false;
        parent[i] = -1;
    }

    graph -> visitedNodes[startingVertex] = true;
    queue[++rear] = startingVertex;
    count++;

    while (front != rear) {
        int currentVertex = queue[++front];
        if (mode == 0) {
            printf(" -> %c", currentVertex + 65);
        }
        node *current = graph -> adjacencyLists[currentVertex];

        while (current != NULL) {
            orderCount++;
            int connectedVertex = current -> vertexName;

            if (graph -> visitedNodes[connectedVertex] == false) {
                graph -> visitedNodes[connectedVertex] = true;
                parent[connectedVertex] = currentVertex;
                queue[++rear] = connectedVertex;
                count++;
            } else if (parent[currentVertex] != connectedVertex) {
                isCyclic = 1;
            }

            current = current -> next;
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
    switch(choice) {
        case 1: tester(); break;
        case 2:
            for (int i = 0; i < 2; i++)
                plotter(i);
            printf("\nGNU plot file contents ready!\n");
            break;
        default: printf("Invalid choice!\n"); break;
    }
    return 0;
}