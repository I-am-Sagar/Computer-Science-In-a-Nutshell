/*  PROBLEM:
    Find if there is a path between two vertices in a
    directed graph.
*/

#include <bits/stdc++.h>
using namespace std;

class Graph {
    int vertices;
    list<int>* adj;
public:
    Graph (int V);
    void addEdge (int v, int w);
    bool isReachable (int s, int d);
};

Graph :: Graph (int V) {
    this->vertices = V;
    adj = new list<int>[V];
}

void Graph :: addEdge(int v, int w) {
    adj[v].push_back(w);
}

// Main Logic of code - Using BFS
bool Graph :: isReachable (int s, int d) {
    if (s == d)
        return true;

    bool *visited = new bool[vertices];
    for (int i = 0; i < vertices; i++)
        visited[i] = false;

    queue<int> q;
    q.push(s);
    visited[s] = true;

    while (!q.empty()) {
        s = q.front();
        q.pop();
        for (auto itr = adj[s].begin(); itr != adj[s].end(); itr++) {
            if (*itr == d)
                return true;
            if (!visited[*itr]) {
                visited[*itr] = true;
                q.push(*itr);
            }
        }
    }
    return false;
}

/* ------------------- MAIN DRIVER CODE ----------------- */
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

    if (g.isReachable(v1, v2))
        cout << "Path exists.\n";
    else
        cout << "Path doesn't exist.\n";

    return 0;
}

