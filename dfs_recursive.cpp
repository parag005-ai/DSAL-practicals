#include <iostream>
using namespace std;

#define MAX 10

class Graph {
    int adjMatrix[MAX][MAX];
    int numVertices;
    bool visited[MAX];

public:
    void create();
    void display();
    void dfs(int start);  // Recursive DFS
    void resetVisited();
    bool isValidNode(int node);
};

// Reset visited array
void Graph::resetVisited() {
    for (int i = 0; i < numVertices; i++) {
        visited[i] = false;
    }
}

// Check if node is valid
bool Graph::isValidNode(int node) {
    return (node >= 0 && node < numVertices);
}

// Input graph data
void Graph::create() {
    cout << "\nEnter number of vertices ";
    cin >> numVertices;

    if (numVertices <= 0 || numVertices > MAX) {
        cout << "Invalid input! Using default size " << MAX << ".\n";
        numVertices = MAX;
    }

    cout << "Enter adjacency matrix (" << numVertices << "x" << numVertices << "):\n";
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            cin >> adjMatrix[i][j];
        }
    }
    resetVisited(); // Initialize visited array
}

// Display adjacency matrix
void Graph::display() {
    cout << "\nADJACENCY MATRIX:\n   ";
    for (int i = 0; i < numVertices; i++) {
        cout << i << " ";
    }
    cout << "\n";
    for (int i = 0; i < numVertices; i++) {
        cout << i << " |";
        for (int j = 0; j < numVertices; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << "\n";
    }
}

// Recursive DFS
void Graph::dfs(int start) {
    if (!isValidNode(start)) {
        cout << "Invalid start node!\n";
        return;
    }

    visited[start] = true;
    cout << start << " ";

    for (int i = 0; i < numVertices; i++) {
        if (!visited[i] && adjMatrix[start][i] == 1) {
            dfs(i);  // Recursive call
        }
    }
}

int main() {
    Graph g;
    int choice, start;
    char repeat;

    do {
        cout << "\n1. Create Graph\n2. Display\n3. DFS (Recursive)\n4. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                g.create();
                break;
            case 2:
                g.display();
                break;
            case 3:
                cout << "Enter starting node: ";
                cin >> start;
                g.resetVisited(); // Reset before new DFS call
                g.dfs(start);
                cout << "\n";
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice!\n";
        }

        cout << "\nContinue? (y/n): ";
        cin >> repeat;
    } while (repeat == 'y' || repeat == 'Y');

    return 0;
}