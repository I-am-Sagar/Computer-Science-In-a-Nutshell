#include<bits/stdc++.h>
using namespace std;

void printBFS (int** edges, int n, int start_vertex, bool* visited) {
    queue<int> pending_vertices;
    pending_vertices.push(0);
    visited[start_vertex] = true;

    while (!pending_vertices.empty()) {
        int current_vertex = pending_vertices.front();
        pending_vertices.pop();
        cout << current_vertex << " ";
        for (int i = 0; i < n; i++) {
            if (i == current_vertex)
                continue;
            if (edges[current_vertex][i] == 1 && !visited[i]) {
                pending_vertices.push(i);
                visited[i] = true;
            }
        }
    }
    cout << endl;
}

void BFS(int** edges, int n) {
    bool* visited = new bool[n]();
    for (int i = 0; i < n; i++)
        if (!visited[i])
            printBFS(edges, n, i, visited);
    delete[] visited;
}

/* ---------------- MAIN DRIVER CODE ---------------- */
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

    BFS(graph, vertices);

    for (int i = 0; i < vertices; i++)
        delete[] graph[i];
    delete[] graph;

    return 0;
}