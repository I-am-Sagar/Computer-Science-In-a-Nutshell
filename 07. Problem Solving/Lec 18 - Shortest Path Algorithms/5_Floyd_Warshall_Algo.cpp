/*
The Floyd Warshall Algorithm is for solving the All Pairs Shortest Path problem.
The problem is to find shortest distances between every pair of vertices in a
given edge weighted directed Graph.

Floyd Warshall Algorithm:

We initialize the solution matrix same as the input graph matrix as a first step.
Then we update the solution matrix by considering all vertices as an
intermediate vertex. The idea is to one by one pick all vertices and updates
all shortest paths which include the picked vertex as an intermediate vertex
in the shortest path. When we pick vertex number k as an intermediate vertex,
we already have considered vertices {0, 1, 2, .. k-1} as intermediate vertices.
For every pair (i, j) of the source and destination vertices respectively,
there are two possible cases.

1) k is not an intermediate vertex in shortest path from i to j.
   We keep the value of dist[i][j] as it is.
2) k is an intermediate vertex in shortest path from i to j.
   We update the value of -
    dist[i][j] = dist[i][k] + dist[k][j] if dist[i][j] > dist[i][k] + dist[k][j]
*/

#include<bits/stdc++.h>
using namespace std;

// Recursive Function to print path of given vertex u from source vertex v
void printPath(int** path, int v, int u) {
    if (path[v][u] == v)
        return;
    printPath(path, v, path[v][u]);
    cout << path[v][u] << " ";
}

// Main Logic
void FloydWarshall(vector<vector<int>> adjMatrix, int V) {

    int** cost = new int*[V];
    int** path = new int*[V];

    for (int i = 0; i < V; i++) {
        cost[i] = new int[V];
        path[i] = new int[V];

        // Initialize cost and path arrays now.
        // Initial cost would be same as weight.
        for (int j = 0; j < V; j++) {
            cost[i][j] = adjMatrix[i][j];

            if (i == j)
                path[i][j] = 0;
            else if (cost[i][j] != INT_MAX)
                path[i][j] = i;
            else
                path[i][j] = -1;
        }
    }
    // Run Floyd Warshall Algo
    for (int k = 0; k < V; k++) {
        for (int v = 0; v < V; v++) {
            for (int u = 0; u < V; u++) {
                // If vertex k is on the shortest path from v to u,
                // then update the value of cost[v][u], path[v][u]
                if (cost[v][k] != INT_MAX && cost[k][u] != INT_MAX
                    && cost[v][k] + cost[k][u] < cost[v][u]) {
                    cost[v][u] = cost[v][k] + cost[k][u];
                    path[v][u] = path[k][u];
                }
            }
            // if diagonal elements become negative, the
            // graph contains a negative weight cycle
            if (cost[v][v] < 0) {
                cout << "Negative Weight Cycle Found!!";
                return;
            }
        }
    }

    // Printing solution
    for (int v = 0; v < V; v++) {
        for (int u = 0; u < V; u++) {
            if (cost[v][u] == INT_MAX)
                cout << setw(5) << "inf";
            else
                cout << setw(5) << cost[v][u];
        }
        cout << endl;
    }
    cout << endl;
    for (int v = 0; v < V; v++) {
        for (int u = 0; u < V; u++) {
            if (u != v && path[v][u] != -1) {
                cout << "Shortest Path from vertex " << v <<
                    " to vertex " << u << " is (" << v << " ";
                printPath(path, v, u);
                cout << u << ")" << endl;
            }
        }
    }
}

/* ------------------ MAIN DRIVER CODE ------------------- */
int main() {
    int V = 4;

    vector<vector<int>> adjMatrix {
        {0, INT_MAX, -2, INT_MAX},
        {4, 0, 3, INT_MAX},
        {INT_MAX, INT_MAX, 0, 2},
        {INT_MAX, -1, INT_MAX, 0},
    };

    FloydWarshall(adjMatrix, V);

    return 0;
}