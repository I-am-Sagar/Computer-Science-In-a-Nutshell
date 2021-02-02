/*
1) Initialize distances of all vertices as infinite.

2) Create an empty set.  Every item of set is a pair (weight, vertex).
   Weight (or distance) is used used as first item  of pair as first item is
   by default used to compare two pairs.

3) Insert source vertex into the set and make its distance as 0.

4) While Set doesn't become empty, do following
    a) Extract minimum distance vertex from Set. Let the extracted vertex be u.
    b) Loop through all adjacent of u and do following for every vertex v.
        // If there is a shorter path to v through u.
        If dist[v] > dist[u] + weight(u, v)
            (i) Update distance of v, i.e., do dist[v] = dist[u] + weight(u, v)
            (ii) If v is in set, update its distance in set by removing it first,
                then inserting with new distance
            (iii) If v is not in set, then insert it in set with new distance.

5) Print distance array dist[] to print all shortest paths.
*/

#include <bits/stdc++.h>
using namespace std;

// Wrapper Class for Graph
class Graph {
    int V;
    vector<pair<int, int>> *adj;    // because weighted graph, hence pair.

public:
    Graph(int V) {
        this->V = V;
        adj = new vector<pair<int, int>> [V];
    }

    void addEdge(int u, int v, int w) {
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    void dijkstra(int src);     // Implemented below
};

// Main Logic
void Graph::dijkstra(int src) {
    // Create a set to store the vertices that are being processed.
    set<pair<int, int>> vertices;

    // Create a vector for distances and initialize them with INFINITY
    vector<int> distances(V, INT_MAX);

    // Insert source itself in set and initialize it's distance to 0
    vertices.insert(make_pair(0, src));
    distances[src] = 0;

    // Loop till vertices are empty.
    while (!vertices.empty()) {
        // The first vertex in Set is the minimum distance vertex.
        pair<int, int> tmp = *(vertices.begin());
        vertices.erase(vertices.begin());

        // Vertex label is stored in second of pair. It has to be done this way
        // to keep the vertices sorted as per the distance. 'distance' must be
        // first item in pair.
        int u = tmp.second;

        // 'i' is used to get all adjacent vertices of a vertex
        vector<pair<int, int>> :: iterator i;

        for (i = adj[u].begin(); i != adj[u].end(); ++i) {
            // Get vertex label and weight of current adjacent of u.
            int v = (*i).first;
            int weight = (*i).second;

            //  If there is shorter path to v through u.
            if (distances[v] > distances[u] + weight) {
                // If distance of v is not INF then it must be in our set,
                // so removing it and inserting again with updated less distance.
                // Note : We extract only those vertices from Set for which
                // distance is finalized. So for them, we would never reach here.
                if (distances[v] != INT_MAX)
                    vertices.erase(vertices.find(make_pair(distances[v], v)));

                // Updating distance of v
                distances[v] = distances[u] + weight;
                vertices.insert(make_pair(distances[v], v));
            }
        }
    }
    // Print shortest distances stored in dist[]
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; ++i)
        printf("%d \t\t %d\n", i, distances[i]);
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

    g.dijkstra(0);

    return 0;
}