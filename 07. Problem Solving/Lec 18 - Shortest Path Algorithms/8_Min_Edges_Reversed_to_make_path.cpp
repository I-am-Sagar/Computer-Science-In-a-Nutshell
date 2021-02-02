/*
Given a directed graph and a source node and destination node, we need to find
how many edges we need to reverse in order to make at least 1 path from source
node to destination node.

This problem can be solved assuming a different version of the given graph.
In this version we make a reverse edge corresponding to every edge and we
assign that a weight 1 and assign a weight 0 to original edge.

Now we can see that we have modified the graph in such a way that, if we move
towards original edge, no cost is incurred, but if we move toward reverse edge
1 cost is added. So if we apply Dijkstra's shortest path on this modified graph
from given source, then that will give us minimum cost to reach from source to
destination i.e. minimum edge reversal from source to destination.
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
        //adj[v].push_back(make_pair(u, w));  This is directed graph
    }

    vector<int> shortestPath(int src);  // Implemented below
};

vector<int> Graph::shortestPath(int src) {
    // set to store vertices that are being processed.
    set <pair<int, int>> vertices;

    // Create a vector for distances and initialize all distances as infinite
    vector<int> dist(V, INT_MAX);

    // Insert source itself in Set and initialize its distance as 0.
    vertices.insert(make_pair(0, src));
    dist[src] = 0;

    // Loop while vertices set is empty
    while(!vertices.empty()) {
        // The first vertex in Set is the minimum distance vertex.
        pair<int, int> tmp = *(vertices.begin());
        vertices.erase(vertices.begin());

        // vertex label is stored in second of pair.
        int u = tmp.second;

        vector< pair<int, int> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i) {
            // Get vertex label and weight of current adjacent of u.
            int v = (*i).first;
            int weight = (*i).second;

            //  If there is shorter path to v through u.
            if (dist[v] > dist[u] + weight) {
                // If distance of v is not INF then it must be in our set,
                // so removing it and inserting again with updated less distance.
                if (dist[v] != INT_MAX)
                    vertices.erase(vertices.find(make_pair(dist[v], v)));

                // Updating distance of v
                dist[v] = dist[u] + weight;
                vertices.insert(make_pair(dist[v], v));
            }
        }
    }
    return dist;
}

// Following method adds reverse edge of each original edge in the graph.
// It gives reverse edge a weight = 1 and all original edges a weight of 0.
// Now, the length of the shortest path will give us the answer.
// If shortest path is p: it means we used p reverse edges in the shortest path.
Graph modelGraphWithEdgeWeight(int edge[][2], int E, int V) {
    Graph g(V);
    for (int i = 0; i < E; i++) {
        //  original edge : weight 0
        g.addEdge(edge[i][0], edge[i][1], 0);

        //  reverse edge : weight 1
        g.addEdge(edge[i][1], edge[i][0], 1);
    }
    return g;
}

// Following method returns minimum number of edges to be reversed
int getMinEdgeReversal(int edge[][2], int E, int V, int src, int dest) {
    //  get modified graph with edge weight
    Graph g = modelGraphWithEdgeWeight(edge, E, V);

    //  get shortes path vector
    vector<int> dist = g.shortestPath(src);

    // If distance of destination is still infinite, not possible
    if (dist[dest] == INT_MAX)
        return -1;
    else
        return dist[dest];
}

/* ------------------ MAIN DRIVER CODE ------------------- */
int main() {
    int V = 7;
    int edge[][2] = {{0, 1}, {2, 1}, {2, 3}, {5, 1}, {4, 5}, {6, 4}, {6, 3}};
    int E = sizeof(edge) / sizeof(edge[0]);
    int minEdgeToReverse = getMinEdgeReversal(edge, E, V, 0, 6);

    if (minEdgeToReverse != -1)
        cout << minEdgeToReverse << endl;
    else
        cout << "Not possible" << endl;

    return 0;
}

