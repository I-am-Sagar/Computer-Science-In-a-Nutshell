/*  Topological sorting for Directed Acyclic Graph (DAG) is a linear 
    ordering of vertices such that for every directed edge uv, vertex
    u comes before v in the ordering. Topological Sorting for a graph 
    is not possible if the graph is not a DAG.

    We can modify DFS to find Topological Sorting of a graph. In DFS, 
    we start from a vertex, we first print it and then recursively call 
    DFS for its adjacent vertices. In topological sorting, we use a 
    temporary stack. We don’t print the vertex immediately, we first 
    recursively call topological sorting for all its adjacent vertices, 
    then push it to a stack. Finally, print contents of stack. 
    Note that a vertex is pushed to stack only when all of its adjacent 
    vertices (and their adjacent vertices and so on) are already in stack.
*/

#include<bits/stdc++.h>
using namespace std;

// Main Logic of Code: Adjacency List Implementation
void topologicalSortUtil (vector<int>* adj, int n, int v, bool visited[], stack<int> &s) {
    visited[v] = true;
    for (auto i = adj[v].begin(); i != adj[v].end(); i++)
        if (!visited[*i])
            topologicalSortUtil(adj, n, *i, visited, s);
    s.push(v);
}

void topologicalSort (vector<int>* adj, int n) {
    stack<int> s;
    bool visited[n] = {false};

    for (int i = 0; i < n; i++)
        if (!visited[i])
            topologicalSortUtil(adj, n, i, visited, s);

    // Printing the stack
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

/* ---------------- MAIN DRIVER CODE -------------------- */
int main() {
    int n, e;
    cin >> n >> e;

    vector<int>* graph = new vector<int>[n];
    int a, b;
    for (int i = 0; i < e; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
    }

    topologicalSort(graph, n);

    return 0;
}

/* ADDITIONAL POINT: 

    Following is the adjacency matrix version of above code:

    void topologicalSortUtil (int** adj, int n, int curr_vertex, bool* visited, stack<int> &s) {
        visited[curr_vertex] = true;
        for (int i = 0; i < n; i++)
            if (adj[curr_vertex][i] != 0 && !visited[i])
                topologicalSortUtil (adj, n, i, visited, s);
        s.push(curr_vertex);
    }

    void topologicalSort (int** adj, int n) {
        // Everything is same
    }

*/