// Video Link: https://www.youtube.com/watch?v=s-CYnVz-uh4

/*  Pseudocode of BFS:

    BFS(G, s):
        parent[s] = null
        state[s] = "discovered"

        i = 1;
        level[s] = i-1;

        Queue Q = {s}
        while Q is not empty do
            u = deQueue(Q)
            // process vertex 'u' as desired
            for each vertex belonging to Adj[u] do
                // process edge (u, v) as desired
                if state[vertex] = "undiscovered" then
                    level[vertex] = i
                    state[vertex] = "discovered"
                    parent[vertex] = u
                    enQueue (Q, vertex)
            i++

    Explanation:

    We are given a graph G in form of adjacency list and a starting
    vertex s. The code starts with some initializations:

    Like parent of vertex s is null as vertex s is starting vertex.
    Maintaining this parent list is optional in BFS, but this will give
    some fun structure later on. Once we have touched a vertex, we
    should set it's state as "This vertex has been visited or discovered",
    so that we shouldn't get stuck in a loop of two adjacent verticies.

    Next is the level list. This list will store the info that - in how
    many steps from the starting vertex, we will reach to the desired node.
    So we reach vertex 's' in zero steps because we have started from there.

    Like tree's level order traversal, we will use queue for BFS.
    We will now start with vertex 'u'. For every vertex u, we will visit
    it's adjacent neighbours. If the adjacent vertex has not been visited,
    we will enqueue this vertex, set it's state, level and parent. At the
    end of this loop, we will increment 'i' so as to increment the level
    for the next nodes.

    The parent list actually forms a tree, where if we continue to find
    the parent of nodes, we will end up at root 's' in shortest path.
    (Watch above mentioned video for more details).
*/

#include<bits/stdc++.h>
using namespace std;

class Graph {
    int vertices;
    list<int>* adj; // can use vector<int>* as well

public:
    Graph(int V);
    void addEdge(int u, int v);
    void BFS(int s);
};

// Public Methods
Graph :: Graph (int V) {
    this->vertices = V;
    adj = new list<int>[V];
}

void Graph :: addEdge (int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// Main Logic of Code
void Graph :: BFS (int s) {
    int* parent = new int[vertices];
    int* level = new int[vertices];

    bool* visited = new bool[vertices];
    for (int i = 0; i < vertices; i++)
        visited[i] = false;

    visited[s] = true;
    parent[s] = -1;
    int i = 1;
    level[s] = i-1;

    queue<int> q;
    q.push(s);
    cout << "BFS Traversal is:\n";
    while (!q.empty()) {
        int u = q.front();
        cout << u << " ";
        q.pop();

        for (auto itr = adj[u].begin(); itr!=adj[u].end(); itr++)
            if (!visited[*itr]) {
                visited[*itr] = true;
                level[*itr] = i;
                parent[*itr] = u;
                q.push(*itr);
            }
        i++;
    }
    cout << endl;

    cout << "Level of each node is:\n";
    for (int i = 0; i < vertices; i++)
        cout << level[i] << " ";
    cout << endl;

    cout << "Parent of each node is:\n";
    for (int i = 0; i < vertices; i++)
        cout << parent[i] << " ";
    cout << endl;
}

/* -------------- MAIN DRIVER CODE -------------- */
int main() {
    int vertices, edges;
    cin >> vertices >> edges;

    Graph g(vertices);
    int a, b;
    for (int i = 0; i < edges; i++) {
        cin >> a >> b;
        g.addEdge(a, b);
    }

    g.BFS(0);

    return 0;
}