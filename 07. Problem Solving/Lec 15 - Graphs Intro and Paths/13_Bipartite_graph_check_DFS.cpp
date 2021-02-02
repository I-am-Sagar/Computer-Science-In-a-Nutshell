/*  Below is the algorithm to check bipartiteness of
    graph using DFS:

    1. Use a color[] array which stores 0 or 1 for every
       node which denotes opposite colors.
    2. Call the function DFS from any node.
    3. If the node u has not been visited previously, then
       assign !color[v] to color[u] and call DFS again to
       visit nodes connected to u.
    4. If at any point, color[u] is equal to !color[v], then
       the node is bipartite.
    5. Modify the DFS function such that it returns a boolean
       value at the end.
*/

#include<bits/stdc++.h>
using namespace std;

// Main Logic of code
bool isBipartite (vector<int> adj[], int v, bool visited[], int color[]) {
    for (int u : adj[v]) {
        if (!visited[u]) {
            visited[u] = false;
            color[u] = !color[v]; // Or use color[u] = 1 - color[v];
            if (!isBipartite(adj, u, visited, color))
                return false;
        }
        else if (color[u] == color[v])
            return false;
    }
    return true;
}

/* -------------- MAIN DRIVER CODE ------------------ */
int main() {
    int V, E;
    cin >> V >> E;

    vector<int> adj[V];
    bool visited[V] = {false};
    int color[V] = {-1};

    int a, b;
    for (int i = 0; i < E; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    visited[0] = true;
    color[0] = 0;

    if (isBipartite(adj, 0, visited, color))
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}
