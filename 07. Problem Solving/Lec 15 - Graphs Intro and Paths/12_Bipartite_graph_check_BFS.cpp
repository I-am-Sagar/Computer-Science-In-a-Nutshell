/*  A Bipartite graph is a graph whose vertices can be divided
    into two independent sets, U and V, such that every edge
    connects a vertex from U to V or a vertex from V to U.
    In other words no edge connects the vertices belonging to
    same set.

    A bipartite graph is possible if the graph coloring is possible
    using two colors such that vertices in a set are colored with
    the same color.

    Note: A graph represented by hexagon is bipartite but a graph
    represented by pentagon is not bipartite.

    Algorithm:

    We will consider two colors: 0(RED) and 1(BLUE). The visited array
    will be an integer array, with every element initialized as -1.
    While we visit every node, we will assign that node either RED or BLUE.
    1. Assign RED color to the source vertex (putting into set U).
    2. Color all the neighbors with BLUE color (putting into set V).
    3. Color all neighbor’s neighbor with RED color (putting into set U).
    4. This way, assign color to all vertices such that it satisfies all
       the constraints of m way coloring problem where m = 2.
    5. While assigning colors, if we find a neighbor which is colored with
       same color as current vertex, then the graph cannot be colored with
       2 vertices (or graph is not Bipartite)

    In above code, we always start with source 0 and assume that vertices
    are visited from it. One important observation is a graph with no edges
    is also Bipartite.
*/

#include<bits/stdc++.h>
using namespace std;

// Main Logic of Code
bool isBipartiteUtil (int** graph, int n, int src, int* color) {
    color[src] = 1;
    // Queue for BFS Traversal
    queue<int> q;
    q.push(src);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        // Return false if there is a self loop
        if (graph[u][u] == 1)
            return false;

        // Find all the non-colored adjacent vertices
        for (int v = 0; v < n; v++)
            if (graph[u][v] == 1 && color[v] == -1) {
                // Assign alternate color to this adjacent v of node u
                color[v] = 1 - color[u];
                q.push(v);
            }
            // An edge from u to v exists and destination v
            // is colored with the same color as u
            else if (graph[u][v]==1 && color[v]==color[u])
                return false;
    }
    // All vertices are colored with alternate colors
    return true;
}

bool isBipartite (int** graph, int n) {
    int color[n] = {-1};
    // Following code is to handle disconnected graph
    for (int i = 0; i < n; i++)
        if (color[i] == -1)
            if (!isBipartiteUtil(graph, n, i, color))
                return false;
    return true;
}

/* ---------------- MAIN DRIVER CODE ----------------- */
int main() {
    int V, E;
    cin >> V >> E;

    int** graph = new int*[V];
    for (int i = 0; i < V; i++)
        graph[i] = new int[V];

    int a, b;
    for (int i = 0; i < E; i++){
        cin >> a >> b;
        graph[a][b] = 1;
    }

    isBipartite(graph, V) ? (cout << "Yes\n") : (cout << "No\n");
    return 0;
}