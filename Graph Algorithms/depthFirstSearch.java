import java.util.LinkedList;
import java.util.Scanner;

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
    int[] parent;
    boolean[] visitedNodes;
    LinkedList<Node>[] adjacencyLists;

    Graph(int numberOfVertices) {
        this.vertexCount = numberOfVertices;
        this.visitedNodes = new boolean[numberOfVertices];
        this.adjacencyLists = new LinkedList[numberOfVertices];
        this.parent = new int[numberOfVertices];
        for (int i = 0; i < numberOfVertices; i++) {
            this.adjacencyLists[i] = new LinkedList<>();
            this.visitedNodes[i] = false;
            this.parent[i] = -1;
        }
    }

    void addEdge(int src, int dest) {
        Node newNode = new Node(dest);
        adjacencyLists[src].addFirst(newNode);
    }
}

public class depthFirstSearch {

    static boolean isCyclic = false;
    static int count = 0, orderCount = 0;

    public static void depthFirstSearch(Graph graph, int currentVertex, int mode) {
        LinkedList<Node> adjacencyList = graph.adjacencyLists[currentVertex];

        count++;
        graph.visitedNodes[currentVertex] = true;
        if (mode == 0)
            System.out.print(" -> " + (char) (currentVertex + 65));

        for (Node current : adjacencyList) {
            orderCount++;
            int connectedVertex = current.vertexName;
            if (!graph.visitedNodes[connectedVertex]) {
                graph.parent[connectedVertex] = currentVertex;
                depthFirstSearch(graph, connectedVertex, mode);
            } else if (graph.parent[currentVertex] != connectedVertex) {
                isCyclic = true;
            }
        }
        
        orderCount++;
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

        System.out.print("\nEnter the vertex from which the graph should be traversed from: ");
        int startingVertex = scanner.nextInt();
        System.out.println("\nThe depth first search sequence is as follows:");
        depthFirstSearch(graph, startingVertex, 0);

        if (isCyclic)
            System.out.println("\n\nThe entered graph is cyclic!");
        else
            System.out.println("\n\nThe entered graph is not cyclic!");

        if (count == numberOfVertices)
            System.out.println("The entered graph is connected!");
        else
            System.out.println("The entered graph is not connected!");
    }

    public static void plotter(int mode) {
        for (int i = 1; i <= 10; i++) {
            Graph graph = new Graph(i);
            for (int j = 0; j < graph.vertexCount; j++) {
                for (int k = 0; k < graph.vertexCount; k++) {
                    // Worst Case - Fully Connected Graph
                    if (mode == 0 && j != k) {
                        graph.addEdge(j, k);
                    }
                    // Best Case - Linear Graph
                    else if (mode == 1 && j == k - 1) {
                        graph.addEdge(j, k);
                    }
                }
            }
            orderCount = count = 0;
            depthFirstSearch(graph, 0, 1);

            if (mode == 1) {
                System.out.println(i + "\t" + orderCount);
            } else if (mode == 0) {
                System.out.println(i + "\t" + orderCount);
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("\nChoose any one of the following options:\n"
                + "1. Tester\n"
                + "2. Generate Performance Data\n");
        int choice = scanner.nextInt();
        switch (choice) {
            case 1:
                tester();
                break;
            case 2:
                plotter(0);
                plotter(1);
                System.out.println("\nPerformance data generation complete!");
                break;
            default:
                System.out.println("Invalid choice!");
                break;
        }
        scanner.close();
    }
}
