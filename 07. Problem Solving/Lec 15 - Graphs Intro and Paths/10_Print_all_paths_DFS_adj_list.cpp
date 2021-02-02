/*  PROBLEM:
    Given a directed graph, a source vertex 'src' and a
    destination vertex 'dst', print all paths from given
    'src' to 'dst'.

    SOLUTION:

    Approach 1: Using DFS
    Start the traversal from source. Keep storing the visited
    vertices in an array, say path[]. If we reach the destination
    vertex, print contents of path[]. The important thing is to
    mark current vertices in path[] as visited also, so that the
    traversal doesn’t go in a cycle.
*/

#include<bits/stdc++.h>
using namespace std;

class Graph {
    int vertices;
    list<int>* adj;
    void printAllPathsUtil (int s, int d, bool visited[], int path[], int& path_index);
public:
    Graph (int V);
    void addEdge (int v, int w);
    void printAllPaths (int s, int d);
};

Graph :: Graph (int V) {
    this->vertices = V;
    adj = new list<int>[V];
}

void Graph :: addEdge(int v, int w) {
    adj[v].push_back(w);
}

// Main Logic of Code
void Graph :: printAllPaths (int s, int d) {
    bool* visited = new bool[vertices];
    for (int i = 0; i < vertices; i++)
        visited[i] = false;

    // An array to store paths
    int* path = new int[vertices];
    int path_index = 0; // Initializing path[] as empty

    // Call the recursive utility function
    printAllPathsUtil(s, d, visited, path, path_index);
}

void Graph :: printAllPathsUtil (int s, int d, bool visited[], int path[], int& path_index) {
    visited[s] = true;
    path[path_index] = s;
    path_index++;

    if (s == d) {
        for (int i = 0; i < path_index; i++)
            cout << path[i] << " ";
        cout << endl;
    }
    else {
        for (auto itr = adj[s].begin(); itr != adj[s].end(); itr++)
            if (!visited[*itr])
                printAllPathsUtil(*itr, d, visited, path, path_index);
    }

    path_index--;
    visited[s] = false;
}

/* -------------- MAIN DRIVER CODE ----------------- */
int main() {
    int V, E;
    cin >> V >> E;

    Graph g(V);
    int a, b;
    for (int i = 0; i < E; i++) {
        cin >> a >> b;
        g.addEdge(a, b);
    }

    int v1, v2;
    cin >> v1 >> v2;
    g.printAllPaths(v1, v2);

    return 0;
}