import java.util.*;
import java.io.FileWriter;
import java.io.IOException;

class Node {
    int vertexName;
    Node next;

    Node(int vertexName) {
        this.vertexName = vertexName;
        this.next = null;
    }
}

class Graph {
    int vertexCount;
    boolean[] visitedNodes;
    LinkedList<Node>[] adjacencyLists;

    @SuppressWarnings("unchecked")
    Graph(int numberOfVertices) {
        this.vertexCount = numberOfVertices;
        this.visitedNodes = new boolean[numberOfVertices];
        this.adjacencyLists = new LinkedList[numberOfVertices];
        for (int i = 0; i < numberOfVertices; i++) {
            this.adjacencyLists[i] = new LinkedList<>();
            this.visitedNodes[i] = false;
        }
    }

    void addEdge(int src, int dest) {
        Node newNode = new Node(dest);
        adjacencyLists[src].addFirst(newNode);
    }
}

public class topologicalSort {

    static int count = 0, orderCount = 0;
    static int stackIndex = 0;

    public static void depthFirstSearch(Graph graph, int currentVertex, int[] stack) {
        LinkedList<Node> adjacencyList = graph.adjacencyLists[currentVertex];

        count++;
        graph.visitedNodes[currentVertex] = true;

        for (Node current : adjacencyList) {
            orderCount++;
            int connectedVertex = current.vertexName;
            if (!graph.visitedNodes[connectedVertex]) {
                depthFirstSearch(graph, connectedVertex, stack);
            }
        }
        
        orderCount++;
        stack[stackIndex++] = currentVertex;

    }

    public static void topologicalSorting(Graph graph, int mode) {
        int[] stack = new int[graph.vertexCount];
        stackIndex = 0;

        for (int i = 0; i < graph.vertexCount; i++) {
            if (!graph.visitedNodes[i]) {
                depthFirstSearch(graph, i, stack);
            }
        }

        if (mode == 0) {
            System.out.println("\nThe topological sort order is:");
            for (int i = stackIndex - 1; i >= 0; i--) {
                System.out.printf("%c ", stack[i] + 65);
            }
            System.out.println();
        }
    }

    public static void tester() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("\nEnter the number of vertices: ");
        int numberOfVertices = scanner.nextInt();
        Graph graph = new Graph(numberOfVertices);
        System.out.println("\nEnter the adjacency list:");
        for (int i = 0; i < graph.vertexCount; i++) {
            System.out.printf("\nFor vertex %c - Enter '1' if the following vertices are adjacent to it:\n", i + 65);
            for (int j = 0; j < graph.vertexCount; j++) {
                System.out.printf("Vertex %c: ", j + 65);
                int key = scanner.nextInt();
                if (key == 1) {
                    graph.addEdge(i, j);
                }
            }
        }

        System.out.println("\nThe entered graph in the form of an adjacency linked list is as follows:");
        for (int i = 0; i < graph.vertexCount; i++) {
            LinkedList<Node> current = graph.adjacencyLists[i];
            System.out.printf("[%c] -> ", i + 65);
            for (Node node : current) {
                System.out.printf("%c -> ", node.vertexName + 65);
            }
            System.out.println("NULL");
        }

        topologicalSorting(graph, 0);
        scanner.close();
    }

    public static void plotter() {
        try {
            FileWriter bestCase = new FileWriter("topoBest.txt");
            FileWriter worstCase = new FileWriter("topoWorst.txt");
    
            for (int i = 1; i <= 10; i++) {
                Graph graphBest = new Graph(i);
                Graph graphWorst = new Graph(i);
    
                for (int j = 0; j < i; j++) {
                    for (int k = 0; k < i; k++) {
                        // Best Case - Linear Graph
                        if (j == k - 1) {
                            graphBest.addEdge(j, k);
                        }
                        // Worst Case - Fully Connected Graph
                        if (j != k) {
                            graphWorst.addEdge(j, k);
                        }
                    }
                }
    
                orderCount = count = 0;
                topologicalSorting(graphBest, 1);
                bestCase.write(i + "\t" + orderCount + "\n");
    
                orderCount = count = 0;
                topologicalSorting(graphWorst, 1);
                worstCase.write(i + "\t" + orderCount + "\n");
            }
    
            bestCase.close();
            worstCase.close();
        } catch (IOException e) {
            System.out.println("An error has occurred.");
            e.printStackTrace();
        }
    }    

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("\nChoose any one of the following options:\n"
                + "1. Tester\n"
                + "2. Generate Performance Data\n");
        int choice = in.nextInt();
        switch (choice) {
            case 1:
                tester();
                break;
            case 2:
                plotter();
                System.out.println("\nPerformance data generation complete!");
                break;
            default:
                System.out.println("Invalid choice!");
                break;
        }
        in.close();
    }
}