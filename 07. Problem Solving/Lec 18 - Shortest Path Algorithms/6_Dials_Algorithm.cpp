/*
Can we optimize Dijkstra's shortest path algorithm to work better than O(E*logV)
if maximum weight is small (or range of edge weights is small)?

For example, in the above diagram, maximum weight is 14. Many a times the range
of weights on edges in is in small range (i.e. all edge weight can be mapped to
0, 1, 2 ... w where w is a small number). In that case, Dijkstra's algorithm
can be modified by using different data structure, buckets, which is called
dial implementation of dijkstra's algorithm.

Time complexity is O(E + WV) where W is maximum weight on any edge of graph,
so we can see that, if W is small then this implementation runs much faster
than traditional algorithm. Following are important observations.

- Maximum distance between any two node can be at max w(V – 1)
(w is maximum edge weight and we can have at max V-1 edges between two vertices).

- In Dijkstra algorithm, distances are finalized in non-decreasing, i.e.,
distance of the closer (to given source) vertices is finalized before the
distant vertices.

APPROACH:

1. Maintains some buckets, numbered 0, 1, 2, ... ,wV.
2. Bucket k contains all temporarily labeled nodes with distance equal to k.
3. Nodes in each bucket are represented by list of vertices.
4. Buckets 0, 1, 2,..wV are checked sequentially until the first non-empty
   bucket is found. Each node contained in the first non-empty bucket has the
   minimum distance label by definition.
5. One by one, these nodes with minimum distance label are permanently labeled
   and deleted from the bucket during the scanning process.
6. Thus operations involving vertex include:
    - Checking if a bucket is empty
    - Adding a vertex to a bucket
    - Deleting a vertex from a bucket.
7. The position of a temporarily labeled vertex in the buckets is updated
   accordingly when the distance label of a vertex changes.
8. Process repeated until all vertices are permanently labeled (or distances
   of all vertices are finalized).

Since the maximum distance can be w(V – 1), we create wV buckets (more for
simplicity of code) for implementation of algorithm which can be large if w is big.

*/

#include <bits/stdc++.h>
using namespace std;

// Wrapper class for Graph
class Graph {
    int V;
    list<pair<int, int>> *adj;

public:
    Graph(int V) {
        this->V = V;
        adj = new list<pair<int, int>>[V];
    }

    void addEdge(int u, int v, int w) {
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    void shortestPath(int src, int W);  // Implemented below
};

// Main Logic
void Graph::shortestPath(int src, int W) {
    // With each distance, iterator to that vertex in its bucket is stored
    // so that vertex can be deleted in O(1) at time of updation. So,
    // dist[i].first = distance of ith vertex from src vertex
    // dist[i].second = iterator to vertex i in bucket number
    vector<pair<int, list<int>::iterator> > dist(V);

    // Initialize all distances as infinite (INT_MAX)
    for (int i = 0; i < V; i++)
        dist[i].first = INT_MAX;

    // Create buckets B[]. B[i] keep vertex of distance label i.
    list<int> B[W*V + 1];

    B[0].push_back(src);
    dist[src].first = 0;
    int index = 0;

    while (1) {
        // Go sequentially through buckets till one non-empty bucket is found
        while (B[index].size() == 0 && index < W*V)
            index++;

        // If all buckets are empty, we are done.
        if (index == W * V)
            break;

        // Take top vertex from bucket and pop it
        int u = B[index].front();
        B[index].pop_front();

        // Process all adjacents of extracted vertex 'u' and
        // update their distanced if required.
        for (auto i = adj[u].begin(); i != adj[u].end(); ++i) {
            int v = (*i).first;
            int weight = (*i).second;

            int du = dist[u].first;
            int dv = dist[v].first;

            // If there is shorted path to v through u.
            if (dv > du + weight) {
                // If dv is not INF then it must be in B[dv] bucket,
                // so erase its entry using iterator in O(1)
                if (dv != INT_MAX)
                    B[dv].erase(dist[v].second);

                //  updating the distance
                dist[v].first = du + weight;
                dv = dist[v].first;

                // pushing vertex v into updated distance's bucket
                B[dv].push_front(v);

                // storing updated iterator in dist[v].second
                dist[v].second = B[dv].begin();
            }
        }
    }
    // Print shortest distances stored in dist[]
    printf("Vertex    Distance from Source\n");
    for (int i = 0; i < V; ++i)
        printf("%d\t\t%d\n", i, dist[i].first);
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

    //  maximum weighted edge - 14
    g.shortestPath(0, 14);

    return 0;
}