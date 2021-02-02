/*  PROBLEM:
    Given a directed graph, check whether the graph contains a cycle or not.

    SOLUTION:
    DFS can be used to detect cycle in a graph. There is a cycle in a graph,
    only if there is a 'backedge' present in the graph. A back edge is an
    edge that is from a node to itself (self-loop) or one of its ancestor
    in the tree produced by DFS.

    To detect a back edge, we can keep track of vertices currently in recursion
    stack of function for DFS traversal. If we reach a vertex that is already
    in the recursion stack, then there is a cycle in the tree. The edge that
    connects current vertex to the vertex in the recursion stack is a back edge.
    We have used recStack[] array to keep track of vertices in the recursion stack.
*/

#include <bits/stdc++.h>
using namespace std;

// Main Logic of Code
bool hasCycleUtil (vector<int> *adj, bool* visited, bool* recStack, int n, int v) {
    if (!visited[v]) {
        visited[v] = true;
        recStack[v] = true;
        for (auto i = adj[v].begin(); i != adj[v].end(); i++)
            if (!visited[*i] && hasCycleUtil(adj, visited, recStack, n, *i))
                return true;
            else if (recStack[*i])
                return true;
    }
    recStack[v] = false;
    return false;
}

bool hasCycle(vector<int>* adj, int n) {
    bool* visited = new bool[n]();
    bool* recStack = new bool[n]();

    for (int i = 0; i < n; i++)
        if (hasCycleUtil(adj, visited, recStack, n, i))
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
        //adj[b].push_back(a);
    }
    if (hasCycle(adj, n))
        cout << "Cycle exists.\n";
    else
        cout << "Cycle doesn't exist.\n";

    return 0;
}