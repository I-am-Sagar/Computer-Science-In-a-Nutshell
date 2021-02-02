// We can make our task little bit simpler by introducing priority queues.

#include <bits/stdc++.h>
using namespace std;

// Wrapper class for Graph
class Graph {
    int V;
    // In a weighted graph, we need to store vertex
    // and weight pair for every edge
    vector<pair<int, int>> *adj;
public:
    Graph(int V) {
        this->V = V;
        adj = new vector<pair<int, int>> [V];
    }

    void addEdge(int u, int v, int w) {
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    void prims(); // Implemented below
};

// Main Logic of code
void Graph::prims() {
    // Create a priority queue to store vertices that are yet to be added in MST.
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    int src = 0; // Taking vertex 0 as source

    // Create a vector for keys and initialize all keys as infinite (INT_MAX)
    vector<int> key(V, INT_MAX);

    // To store parent array which in turn store MST
    vector<int> parent(V, -1);

    // To keep track of vertices included in MST
    vector<bool> inMST(V, false);

    // Insert source itself in priority queue and initialize its key as 0.
    pq.push(make_pair(0, src));
    key[src] = 0;

    // Loop till priority queue becomes empty
    while (!pq.empty()) {
        // The first vertex in pair is the minimum key vertex, get it from pq.
        // Vertex label is stored in second of pair. It has to be done this way
        // to keep the vertices sorted key (key must be first item in pair).
        int u = pq.top().second;
        pq.pop();

        inMST[u] = true;  // Include vertex in MST

        // 'i' is used to get all adjacent vertices of a vertex
        vector<pair<int, int>>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i) {
            // Get vertex label and weight of current adjacent of u.
            int v = (*i).first;
            int weight = (*i).second;

            // If v is not in MST and weight of (u,v) is smaller than current key of v
            if (inMST[v] == false && key[v] > weight) {
                // Updating key of v
                key[v] = weight;
                pq.push(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }
    // Print edges of MST using parent array
    for (int i = 1; i < V; ++i)
        printf("%d - %d\n", parent[i], i);
}

/* ------------------ MAIN DRIVER CODE ------------------- */
int main() {
    int V = 9;
    Graph g(V);

    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    g.prims();

    return 0;
}

/* Additional Point:

Let's say - we want to find Minimum Product MST. A minimum product spanning tree
for a weighted, connected and undirected graph is a spanning tree with weight
product less than or equal to the weight product of every other spanning tree.

This problem can be solved using standard minimum spanning tree algorithms like
krushkal's and prim's algorithm, but we need to modify our graph to use these
algorithms. Minimum spanning tree algorithms tries to minimize total sum of
weights, here we need to minimize total product of weights.

We can use property of logarithms to overcome this problem. As we know,

  log(w1* w2 * w3 * …. * wN) = log(w1) + log(w2) + log(w3) ….. + log(wN)

We can replace each weight of graph by its log value, then we apply any minimum
spanning tree algorithm which will try to minimize sum of log(wi) which
in-turn minimizes weight product.

*/