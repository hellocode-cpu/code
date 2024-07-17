#include <iostream>
#include <vector>

using namespace std;

bool isSafe(int vertex, vector<vector<int>>& graph, vector<int>& color, int c, int V) {
    for (int i = 0; i < V; i++) {
        if (graph[vertex][i] == 1 && color[i] == c) {
            return false;
        }
    }
    return true;
}

bool helper(int i, int V, int k, vector<vector<int>>& graph, vector<int>& color) {
    if (i == V) {
        return true;  // All vertices are colored
    }

    for (int j = 0; j < k; j++) {
        if (isSafe(i, graph, color, j, V)) {
            color[i] = j;
            if (helper(i + 1, V, k, graph, color)) {
                return true;
            }
            color[i] = -1;  // Backtrack
        }
    }

    return false;
}

bool graphColoring(vector<vector<int>>& graph, int k, int V) {
    vector<int> color(V, -1);  // Initialize colors for all vertices as -1

    if (helper(0, V, k, graph, color)) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int V, k;
    cout << "Enter the number of vertices: ";
    cin >> V;
    vector<vector<int>> graph(V, vector<int>(V, 0));

    cout << "Enter the adjacency matrix of the graph (V x V):\n";
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            cin >> graph[i][j];
        }
    }

    cout << "Enter the number of colors: ";
    cin >> k;

    if (graphColoring(graph, k, V)) {
        cout << "The graph can be colored with " << k << " colors.\n";
    } else {
        cout << "The graph cannot be colored with " << k << " colors.\n";
    }

    return 0;
}
/*


int main() {
    // Sample example
    int V = 4;
    vector<vector<int>> graph = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };
    int k = 3;

    if (graphColoring(graph, k, V)) {
        cout << "The graph can be colored with " << k << " colors.\n";
    } else {
        cout << "The graph cannot be colored with " << k << " colors.\n";
    }

    // User input
    cout << "\nEnter the number of vertices: ";
    cin >> V;
    graph = vector<vector<int>>(V, vector<int>(V, 0));

    cout << "Enter the adjacency matrix of the graph (V x V):\n";
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            cin >> graph[i][j];
        }
    }

    cout << "Enter the number of colors: ";
    cin >> k;

    if (graphColoring(graph, k, V)) {
        cout << "The graph can be colored with " << k << " colors.\n";
    } else {
        cout << "The graph cannot be colored with " << k << " colors.\n";
    }

    return 0;
}


*/
