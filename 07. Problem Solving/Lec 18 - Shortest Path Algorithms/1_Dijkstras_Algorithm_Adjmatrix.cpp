/* Given a graph and a source vertex in the graph, find shortest paths 
   from source to all vertices in the given graph.

Dijkstra's algorithm is very similar to Prim's algorithm for minimum spanning 
tree. Like Prim's MST, we generate a SPT (shortest path tree) with given source 
as root. We maintain two sets, one set contains vertices included in shortest 
path tree, other set includes vertices not yet included in shortest path tree. 
At every step of the algorithm, we find a vertex which is in the other set 
(set of not yet included) and has a minimum distance from the source.

Algorithm:

1) Create a set sptSet (shortest path tree set) that keeps track of vertices 
   included in shortest path tree, i.e., whose minimum distance from source is 
   calculated and finalized. Initially, this set is empty.

2) Assign a distance value to all vertices in the input graph. Initialize all 
   distance values as INFINITE. Assign distance value as 0 for the source 
   vertex so that it is picked first.

3) While sptSet doesn't include all vertices
    a) Pick a vertex u which is not there in sptSet and has minimum distance 
       value.
    b) Include u to sptSet.
    c) Update distance value of all adjacent vertices of u. To update the 
       distance values, iterate through all adjacent vertices. For every 
       adjacent vertex v, if sum of distance value of u (from source) and 
       weight of edge u-v, is less than the distance value of v, then update 
       the distance value of v.
*/

#include <bits/stdc++.h>
using namespace std;

int V, E;

int minDistance(int dist[], bool sptSet[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}

void printSolution(int dist[], int n) {
    for (int i = 0; i < V; i++)
        printf("%d %d\n", i, dist[i]);
}

void dijkstra(int** graph, int V) {
    int* dist = new int[V];
    bool* sptSet = new bool[V];

    for (int i = 0; i < V; i++)
    dist[i] = INT_MAX, sptSet[i] = false;

    dist[0] = 0;

    for (int count = 0; count < V-1; count++) {
    int u = minDistance(dist, sptSet);

    sptSet[u] = true;

    for (int v = 0; v < V; v++)
        if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u]+graph[u][v] < dist[v])
        dist[v] = dist[u] + graph[u][v];
    }
    printSolution(dist, V);
    delete[] dist, sptSet;
}

/* ------------------ MAIN DRIVER CODE ------------------- */
int main() {
    cin >> V >> E;

    int** edges = new int*[V];
    for (int i = 0; i < V; i++)
        edges[i] = new int[V]();

    int f, s, weight;
    for (int i = 0; i < E; i++) {
        cin >> f >> s >> weight;
        edges[f][s] = weight;
        edges[s][f] = weight;
    }

    dijkstra (edges, V);

    for (int i = 0; i < V; i++)
        delete[] edges[i];
    delete[] edges;

    return 0;
}