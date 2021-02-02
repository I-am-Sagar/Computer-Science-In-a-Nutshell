#include <bits/stdc++.h>
using namespace std;

void printDFS (int** edges, int n, int start_vertex, bool* visited) {
    cout << start_vertex << " ";
    visited[start_vertex] = true;

    for (int i = 0; i < n; i++) {
        if (i == start_vertex)
            continue;
        if (edges[start_vertex][i] == 1 && !visited[i])
            printDFS(edges, n, i, visited);
    }
}

void DFS (int** edges, int n) {
    bool* visited = new bool[n]();
    for (int i = 0; i < n; i++)
        if (!visited[i])
            printDFS(edges, n, i, visited);
    cout << endl;
    delete[] visited;
}

/* ------------ MAIN DRIVER CODE --------------- */
int main() {
    int vertices, edges;
    cin >> vertices >> edges;

    int** graph = new int*[vertices];
    for (int i = 0; i < vertices; i++)
        graph[i] = new int[vertices];
    int a, b;
    for (int i = 0; i < edges; i++) {
        cin >> a >> b;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    DFS(graph, vertices);

    for (int i = 0; i < vertices; i++)
        delete[] graph[i];
    delete[] graph;

    return 0;
}