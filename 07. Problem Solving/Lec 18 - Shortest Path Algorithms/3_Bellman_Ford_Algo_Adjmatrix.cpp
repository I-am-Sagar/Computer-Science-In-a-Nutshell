/*
Given a graph and a source vertex src in graph, find shortest paths from src to
all vertices in the given graph. The graph may contain negative weight edges.

We have discussed Dijkstra's algorithm for this problem. Dijkstra's algorithm
is a Greedy algorithm and time complexity is O(VLogV) (with the use of Fibonacci
heap). Dijkstra doesn't work for Graphs with negative weight edges.
Bellman-Ford works for such graphs. Bellman-Ford is also simpler than Dijkstra
and suites well for distributed systems. But time complexity of Bellman-Ford is
O(VE), which is more than Dijkstra.

Input: Graph and a source vertex src
Output: Shortest distance to all vertices from src. If there is a negative
weight cycle, then shortest distances are not calculated, negative weight
cycle is reported.

Approach:

1) This step initializes distances from source to all vertices as infinite and
   distance to source itself as 0. Create an array dist[] of size |V| with all
   values as infinite except dist[src] where src is source vertex.

2) This step calculates shortest distances. Do following |V|-1 times where |V|
   is the number of vertices in given graph.
    a) Do following for each edge u-v
        If dist[v] > dist[u] + weight of edge uv, then update dist[v]
        dist[v] = dist[u] + weight of edge uv

3) This step reports if there is a negative weight cycle in graph.
    Do following for each edge u-v
        If dist[v] > dist[u] + weight of edge uv, then
        'Graph contains negative weight cycle'

The idea of step 3 is, step 2 guarantees shortest distances if graph doesn't
contain negative weight cycle. If we iterate through all edges one more time
and get a shorter path for any vertex, then there is a negative weight cycle.

*/

#include<bits/stdc++.h>
using namespace std;

void BellmanFord (int graph[][3], int V, int E, int src) {
    int* distance = new int[V];
    for (int i = 0; i < V; i++)
        distance[i] = INT_MAX;

    distance[src] = 0;

    for (int i = 0; i < V-1; i++) {
        for (int j = 0; j < E; j++) {
            if (distance[graph[j][0]] + graph[j][2] < distance[graph[j][1]])
                distance[graph[j][1]] =  distance[graph[j][0]] + graph[j][2];
        }
    }

    // Following step checks for negative cycles
    for (int i = 0; i < E; i++) {
        int x = graph[i][0];
        int y = graph[i][1];
        int weight = graph[i][2];

        if (distance[x] != INT_MAX && distance[x] + weight < distance[y])
            cout << "Graph contains negative weight cycle." << endl;
    }

    cout << "Vertex    Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout << i << "\t\t" << distance[i] << endl;
}

/* ------------------ MAIN DRIVER CODE ------------------- */
int main() {
    int V = 5;
    int E = 8;
    int graph[][3] = { { 0, 1, -1 }, { 0, 2, 4 },
                       { 1, 2, 3 }, { 1, 3, 2 },
                       { 1, 4, 2 }, { 3, 2, 5 },
                       { 3, 1, 1 }, { 4, 3, -3 } };

    BellmanFord(graph, V, E, 0);
    return 0;
}