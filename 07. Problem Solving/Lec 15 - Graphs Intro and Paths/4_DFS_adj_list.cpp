// Video Link: https://www.youtube.com/watch?v=AfSk24UTFS8
// Extra read: https://techdifferences.com/difference-between-bfs-and-dfs.html

/*
    The DFS algorithm is a recursive algorithm that uses
    the idea of backtracking. It involves exhaustive searches
    of all the nodes by going ahead, if possible, else by backtracking.

    Here, the word backtrack means that when you are moving forward
    and there are no more nodes along the current path, you move
    backwards on the same path to find nodes to traverse. All the
    nodes will be visited on the current path till all the unvisited
    nodes have been traversed after which the next path will be selected.

    The basic idea is as follows:
    a) Pick a starting node and push all its adjacent nodes into a stack.
    b) Pop a node from stack to select the next node to visit and push
       all its adjacent nodes into a stack.
    c) Repeat this process until the stack is empty. However, ensure that
       the nodes that are visited are marked. This will prevent you from
       visiting the same node more than once. If you do not mark the nodes
       that are visited and you visit the same node more than once, you may
       end up in an infinite loop.

Pseudocode of DFS:

DFS-visit() is the basic depth-first-search which will visit all the
which will visit all the vertices reachable from a given source vertex s.
If the graph is undirected, DFS-visit() alone can reach all the nodes.
But in case of directed graphs, we may not visit all the vertices.

    DFS-visit(G, s):    // Recursive
        visited[s] = true
        for vertex v in Adj[s]:
            if (!visited[v]):
                DFS-visit (G, v);

    DFS-visit (G, s):   // Iterative
        stack S
        S.push(s);
        visited[s] = true;
        while stack is not empty:
            vertex v = S.top()
            S.pop()
            for all vertices w in Adj[v]:
                if (!visited[w]):
                    S.push(w)
                    visited[w] = true

The next part is the DFS which will visit the entire graph and not
just the vertices reachable from S. This is helpful in directed graphs.
This DFS function uses DFS-visit() as util function.

    DFS(G):
        no vertex has been visited yet
        for each vertex s in Vertices:
            if (!visited[s]):
                visited[s] = true
                DFS-visit(G, s)

*/

#include<bits/stdc++.h>
using namespace std;

class Graph {
    int vertices;
    list<int>* adj;
    void DFS_visit(int v, bool* visited);

public:
    Graph(int V);
    void addEdge (int u, int v);
    void DFS ();
};

// Public methods
Graph :: Graph(int V) {
    this->vertices = V;
    adj = new list<int>[V];
}

void Graph :: addEdge (int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// Main Logic of code
// Passing visited array from DFS() by reference
void Graph :: DFS_visit(int s, bool* visited) {
    stack <int> S;
    visited[s] = true;
    S.push(s);
    while (!S.empty()) {
        int v = S.top();
        S.pop();

        cout << v << " ";
        for (auto itr = adj[v].begin(); itr != adj[v].end(); itr++)
            if (!visited[*itr]) {
                S.push(*itr);
                visited[*itr] = true;
            }
    }
    cout << endl;
}

void Graph :: DFS() {
    bool* visited = new bool[vertices];
    for (int i = 0; i < vertices; i++)
        visited[i] = false;

    for (int i = 0; i < vertices; i++)
        if (!visited[i])
            DFS_visit(i, visited);
}

/* -------------- MAIN DRIVER CODE ------------ */
int main() {
    int vertices, edges;
    cin >> vertices >> edges;

    Graph g(vertices);
    int a, b;
    for (int i = 0; i < edges; i++) {
        cin >> a >> b;
        g.addEdge(a, b);
    }

    cout << "DFS of given graph is:\n";
    g.DFS();

    return 0;
}

/*  ADDITIONAL POINT:

    Edge classification:

    In DFS, we can see every edge gets visited. In a directed
    graph, every edge gets visited once whereas in an undirected
    graph, every edge gets visited twice.

    When we visit an edge, there is some sort of classification
    based on what could happen at the other end of the edge:

    a) Tree Edges: These are the edges which lead to some node
       which was unvisited earlier. These edges in a graph form
       a tree (forest to be more precise if the edges are
       directed and we cant reach to other part of graph from
       the starting vertex s).

    Remaining three types of edges (useful in directed graphs)
    doesn't lead to unvisited node.

    b) Forward Edges: If a edge takes us from a root of the tree
       (formed by tree edges) or the subtree to it's descendant,
       it's a forward edge.

    c) Backward Edges: If a edge takes us from a node of the tree
       to its ancestor, it's a backward edge.

    d) Cross Edges: All the other edges which are not forward or
       backward edges are cross edges. These are the edges which
       may take us from one tree to another tree in graph's forest
       (formed by tree edges), may be from one node to another in
       same level of a tree, etc.

    In an undirected graphs, forward and cross edges don't exist.
    There are only tree edges and backward edges, in case of
    undirected graphs.
 */