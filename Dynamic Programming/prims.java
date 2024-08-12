// Prims algorithm using Adjacency Matrix

import java.util.*;

class Graph {
    int vertexCount;
    Boolean[] visitedNodes;
    char[][] adjacencyMatrix;

    Graph(int vertexCount) {
        this.vertexCount = vertexCount;
        visitedNodes = new Boolean[vertexCount];
        adjacencyMatrix = new char[vertexCount][vertexCount];

        for (int i = 0; i < vertexCount; i++) {
            visitedNodes[i] = false;
        }
    }
}

class Prims {
    void tester() {
        Scanner in = new Scanner(System.in);

        System.out.print("\nEnter the number of vertices: ");
        int vertexCount = in.nextInt();

        Graph graph = new Graph(vertexCount);

        System.out.println("\nEnter the adjacency matrix:");
        for (int i = 0; i < graph.vertexCount; i++) {
            System.out.printf("\nFor vertex %c - Enter the weights if the following vertices are adjacent to it:\n", i + 65);
            for (int j = 0; j < graph.vertexCount; j++) {
                System.out.printf("Vertex %c: ", j + 65);
                String key = in.nextLine();
                if () {
                    
                }
            }
        }
    }
}