/*
Given a graph where every edge has weight as either 0 or 1. A source vertex is
also given in the graph. Find the shortest path from source vertex to every
other vertex.

In normal BFS of a graph all edges have equal weight but in 0-1 BFS some edges
may have 0 weight and some may have 1 weight. In this we will not use bool array
to mark visited nodes but at each step we will check for the optimal distance
condition. We use double ended queue to store the node. While performing BFS if a
edge having weight = 0 is found node is pushed at front of double ended queue and
if a edge having weight = 1 is found, it is pushed at back of double ended queue.

The approach is similar to Dijkstra that the if the shortest distance to node is
relaxed by the previous node then only it will be pushed in the queue.

The above idea works in all cases, when pop a vertex (like Dijkstra), it is the
minimum weight vertex among remaining vertices. If there is a 0 weight vertex
adjacent to it, then this adjacent has same distance. If there is a 1 weight
adjacent, then this adjacent has maximum distance among all vertices in dequeue
(because all other vertices are either adjacent of currently popped vertex or
adjacent of previously popped vertices).
*/

#include <bits/stdc++.h>
using namespace std;

// Wrapper class for Graph
class Graph {
    int V;
    vector<pair<int, int>> *adj;

public:
    Graph(int V) {
        this->V = V;
        adj = new vector<pair<int, int>>[V];
    }

    void addEdge(int u, int v, int w) {
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    void ZeroOneBFS(int src);  // Implemented below
};

void Graph::ZeroOneBFS(int src) {
    int* dist = new int[V];
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;

    // Doubly ended queue keeps track of edges during BFS
    deque<int> dq;
    dist[src] = 0;
    dq.push_back(src);

    while (!dq.empty()) {
        int v = dq.front();
        dq.pop_front();

        for (int i = 0; i < adj[v].size(); i++) {
            // checks for the shortest distance to the nodes
            if (dist[adj[v][i].first] > dist[v] + adj[v][i].second) {
                dist[adj[v][i].first] = dist[v] + adj[v][i].second;

                // Put destination vertex connected by 0 edge to front and
                // vertex connected by 1 edge to back so that vertices are
                // processed in ascending order of weights.
                if (adj[v][i].second == 0)
                    dq.push_front(adj[v][i].first);
                else
                    dq.push_back(adj[v][i].first);
            }

        }
    }

    // printing the dist array that stores the shortest distances
    for (int i = 0; i < V; i++)
        cout << i << " : " << dist[i] << "\n";
}

/* ------------------ MAIN DRIVER CODE ------------------- */
int main() {
    int V = 9;
    Graph g(V);
    g.addEdge(0, 1, 0);
    g.addEdge(0, 7, 1);
    g.addEdge(1, 7, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 0);
    g.addEdge(2, 5, 0);
    g.addEdge(2, 8, 1);
    g.addEdge(3, 4, 1);
    g.addEdge(3, 5, 1);
    g.addEdge(4, 5, 1);
    g.addEdge(5, 6, 1);
    g.addEdge(6, 7, 1);
    g.addEdge(7, 8, 1);

    g.ZeroOneBFS(0);
    return 0;
}
