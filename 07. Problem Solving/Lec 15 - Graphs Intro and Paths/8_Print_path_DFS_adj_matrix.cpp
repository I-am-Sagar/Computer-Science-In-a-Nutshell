#include<bits/stdc++.h>
using namespace std;

bool path (int** adj, int n, int v1, int v2, bool* visited, vector<int> &v) {
    v.push_back(v1);
    visited[v1] = true;
    if (v1 == v2)
        return true;

    for (int i = 0; i < n; i++)
        if (!visited[i] && adj[v1][i] == 1)
            if (path(adj, n, i , v2, visited, v))
                return true;

    v.pop_back();
    return false;
}

/* -------------- MAIN DRIVER CODE ----------------- */
int main() {
    int V, E;
    cin >> V >> E;

    int** adj = new int*[V];
    for (int i = 0; i < V; i++) {
        adj[i] = new int[V];
        for (int j = 0; j < V; j++)
            adj[i][j] = 0;
    }

    int a, b;
    for (int i = 0; i < E; i++) {
        cin >> a >> b;
        adj[a][b] = 1;
        adj[b][a] = 1;
    }

    int v1, v2;
    cin >> v1 >> v2;
    vector<int> v;
    bool* visited = new bool[V]();

    if (path(adj, V, v1, v2, visited, v)){
        for (int i = 0; i < v.size(); i++)
            cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}