#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Graph {
private:
    int V;  // Number of vertices (departments)
    vector<vector<int>> adjMatrix; // Adjacency matrix to store distances
    
public:
    // Constructor
    Graph(int v) {
        V = v;
        adjMatrix.resize(V, vector<int>(V, 0));
    }

    // Function to add an edge (distance between two departments)
    void addEdge(int u, int v, int weight) {
        adjMatrix[u][v] = weight;
        adjMatrix[v][u] = weight; // For undirected graph
    }

    // Function to implement Prim's algorithm to find MST
    void primMST() {
        vector<int> parent(V, -1);  // Parent array to store MST
        vector<int> key(V, INT_MAX); // Key values to pick minimum weight edge
        vector<bool> inMST(V, false); // To check if vertex is in MST
        
        key[0] = 0; // Start from the first vertex
        parent[0] = -1; // First node has no parent
        
        // Loop through all vertices
        for (int count = 0; count < V - 1; count++) {
            // Find the vertex with the minimum key value
            int u = minKey(key, inMST);
            inMST[u] = true; // Add u to MST
            
            // Update key value and parent index of the adjacent vertices
            for (int v = 0; v < V; v++) {
                if (adjMatrix[u][v] && !inMST[v] && adjMatrix[u][v] < key[v]) {
                    key[v] = adjMatrix[u][v];
                    parent[v] = u;
                }
            }
        }
        
        // Print the edges in the MST
        printMST(parent);
    }

    // Helper function to find vertex with minimum key value
    int minKey(const vector<int>& key, const vector<bool>& inMST) {
        int min = INT_MAX, minIndex;
        for (int v = 0; v < V; v++) {
            if (!inMST[v] && key[v] < min) {
                min = key[v];
                minIndex = v;
            }
        }
        return minIndex;
    }

    // Function to print the MST edges
    void printMST(const vector<int>& parent) {
        cout << "Edge \tWeight\n";
        for (int i = 1; i < V; i++) {
            cout << parent[i] << " - " << i << " \t" << adjMatrix[i][parent[i]] << endl;
        }
    }

    // Function to display the adjacency matrix (graph)
    void displayGraph() {
        cout << "Adjacency Matrix:\n";
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int V, u, v, weight, choice;

    // Taking input for the graph
    cout << "Enter the number of departments (vertices): ";
    cin >> V;
    
    Graph g(V);
    
    // Taking input for the edges (distances between departments)
    cout << "Enter the edges in the format: u v weight (0-based index)\n";
    cout << "Enter -1 -1 to stop.\n";
    while (true) {
        cout << "Enter edge (u v weight): ";
        cin >> u >> v >> weight;
        if (u == -1 && v == -1) break;
        g.addEdge(u, v, weight);
    }

    do {
        cout << "\nMenu:\n";
        cout << "1. Display the graph (Adjacency Matrix)\n";
        cout << "2. Find Minimum Spanning Tree (MST) using Prim's Algorithm\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                g.displayGraph();
                break;
            case 2:
                g.primMST();
                break;
            case 3:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 3);

    return 0;
}
