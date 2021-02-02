/*  PROBLEM:
    Given an undirected graph, check if there is a cycle in the graph.

    SOLUTION:

    We will use a DFS-alike function 'hasCycle()' that will call a
    utility function 'hasCycleUtil()'. hasCycleUtil() uses visited[]
    and parent to detect cycle in a subgraph reachable from vertex v.
    We recur the hasCycleUtil() function for all the vertices
    adjacent to vertex v. The main idea then is:

    If an adjacent vertex is visited and that adjacent vertex is not
    the parent of the current vertex, then there is cycle.

    Time Complexity: O(V+E)
*/

#include <bits/stdc++.h>
using namespace std;

// Main Logic of code
bool hasCycleUtil (vector<int> *adj, bool* visited, int v, int parent) {
    visited[v] = true;
    for (auto i = adj[v].begin(); i != adj[v].end(); i++)
        if (!visited[*i]){
            if (hasCycleUtil(adj, visited, *i, v))
                return true;
        }
        else if (*i != parent)
            return true;
    return false;
}

bool hasCycle (vector<int>* adj, int n) {
    bool* visited = new bool[n]();
    for (int i = 0; i < n; i++)
        if (!visited[i])
            if (hasCycleUtil(adj, visited, i, -1))
                return true;
    return false;
}

/* -------------- MAIN DRIVER CODE ----------------- */
int main() {
    int n, e;
    cin >> n >> e;

    vector<int>* adj = new vector<int>[n];
    int a, b;
    for (int i = 0; i < e; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    if (hasCycle(adj, n))
        cout << "Cycle exists.\n";
    else
        cout << "Cycle doesn't exist.\n";

    return 0;
}