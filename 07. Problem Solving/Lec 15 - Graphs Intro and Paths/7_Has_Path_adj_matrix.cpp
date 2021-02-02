#include<bits/stdc++.h>
using namespace std;

bool isReachable(int** edges, int n, int s, int d) {
    if (s == d)
        return true;

    bool hasRoute = false;
    bool visited[n+1] = {false};
    queue<int> vertices;

    visited[s] = true;
    vertices.push(s);
    while (!vertices.empty() && !hasRoute) {
        int current = vertices.front();
        vertices.pop();
        for (int i = 0; i < n; i++) {
            if (edges[current][i] != 0 && !visited[i]) {
                if (i == d) {
                    hasRoute = true;
                    break;
                }
                visited[i] = true;
                vertices.push(i);
            }
        }
    }
    return hasRoute;
}

/* ------------------- MAIN DRIVER CODE ----------------- */
int main() {
    int V, E;
    cin >> V >> E;

    int** graph = new int*[V];
    for (int i = 0; i < V; i++)
        graph[i] = new int[V];

    int a, b;
    for (int i = 0; i < E; i++) {
        cin >> a >> b;
        graph[a][b] = 1;
    }

    int v1, v2;
    cin >> v1 >> v2;

    if (isReachable(graph, V, v1, v2))
        cout << "Path exists.\n";
    else
        cout << "Path doesn't exist.\n";

    for (int i = 0; i < V; i++)
        delete[] graph[i];
    delete[] graph;

    return 0;
}

