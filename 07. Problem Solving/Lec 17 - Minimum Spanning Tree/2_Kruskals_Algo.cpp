/*
What is a Minimum Spanning Tree?
Given a connected and undirected graph, a spanning tree of that graph is a
subgraph that is a tree and connects all the vertices together. A single
graph can have many different spanning trees. A minimum spanning tree (MST)
or minimum weight spanning tree for a weighted, connected and undirected graph
is a spanning tree with weight less than or equal to the weight of every other
spanning tree. The weight of a spanning tree is the sum of weights given to
each edge of the spanning tree.

How many edges does a minimum spanning tree has?
An MST has (V – 1) edges where V is the number of vertices in the given graph.

Below are the steps for finding Minimum Spanning Tree using Kruskal's Algo:

1. Sort all the edges in non-decreasing order of their weight.
2. Pick the smallest edge. Check if it forms a cycle with the spanning tree
   formed so far. If cycle is not formed, include this edge. Else, discard it.
3. Repeat step 2 until there are (V-1) edges in the spanning tree.
*/

#include <bits/stdc++.h>
using namespace std;

class Edge {
    public:
        int src, dest, weight;
};

bool compare (Edge e1, Edge e2) {
    return e1.weight < e2.weight;
}

// This is kindof similar to root() method in disjoint set union algo,
// but it's implemented recursively.
int getParent (int v, int* parent) {
    if (parent[v] == v)
        return v;
    else
        return getParent(parent[v], parent);
}

// Main algorithm
Edge* kruskal (Edge* edges, int n, int E) {
    sort (edges, edges + E, compare);
    Edge* output = new Edge[n-1];
    int* parent = new int[n];
    for (int i = 0; i < n; i++)
        parent[i] = i;

    int count = 0;
    int i = 0;
    while (count < n-1) {
        Edge currentEdge = edges[i];
        int srcParent = getParent (currentEdge.src, parent);
        int destParent = getParent (currentEdge.dest, parent);

        if (srcParent != destParent) {
            output[count] = currentEdge;
            count++;
            parent[srcParent] = destParent;
        }
        i++;
    }
    delete[] parent;
    return output;
}

/* ------------------ MAIN DRIVER CODE ------------------ */
int main() {
    int n, E;
    cin >> n >> E;

    Edge* edges = new Edge[E];
    for (int i = 0; i < E; i++)
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;

    cout << "Edges in MST: " << endl;
    Edge* output = kruskal (edges, n, E);
    for (int i = 0; i < n-1; i++) {
        cout << output[i].src << " " << output[i].dest << " " << output[i].weight << endl;
    }
    return 0;
}