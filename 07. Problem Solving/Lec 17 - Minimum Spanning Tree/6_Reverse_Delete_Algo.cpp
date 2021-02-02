/*
Reverse Delete algorithm is closely related to Kruskal's algorithm.
In Kruskal's algorithm what we do is : Sort edges by increasing order of their
weights. After sorting, we one by one pick edges in increasing order.
We include current picked edge if by including this in spanning tree not
form any cycle until there are V-1 edges in spanning tree.

In Reverse Delete algorithm, we sort all edges in decreasing order of their
weights. After sorting, we one by one pick edges in decreasing order.
We include current picked edge if excluding current edge causes disconnection
in current graph. The main idea is delete edge if its deletion does not lead
to disconnection of graph.

The Algorithm:

1) Sort all edges of graph in non-increasing order of edge weights.

2) Initialize MST as original graph and remove extra edges using step 3.

3) Pick highest weight edge from remaining edges and check if deleting the
   edge disconnects the graph or not.
       If disconnects, then we don't delete the edge.
       Else we delete the edge and continue.
*/

#include <bits/stdc++.h>
using namespace std;

class Edge {
    public:
        int src, dest, weight;
        Edge(int src, int dest, int weight) {
            this->src = src;
            this->dest = dest;
            this->weight = weight;
        }
};

bool compare(Edge e1, Edge e2) {
    return e1.weight < e2.weight;
}

// Wrapper class for Graph
class Graph {
    int V;
    // Used list instead of vector, because we will need remove() method of list
    list<int>* adjList;      // Will be used for checking connectivity
    vector<Edge> edges;      // Will be used for sorting edges

public:
    Graph(int V) {
        this->V = V;
        adjList = new list<int>[V];
    }

    void addEdge(int u, int v, int w) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
        edges.push_back(Edge(u, v, w));
    }

    void DFS (int v, bool* visited) {
        visited[v] = true;
        list<int> :: iterator i;
        for (i = adjList[v].begin(); i != adjList[v].end(); i++)
            if(!visited[*i])
                DFS(*i, visited);
    }

    bool isConnected() {
        bool* visited = new bool[V]();
        DFS(0, visited);
        for (int i = 1; i < V; i++)
            if (visited[i] == false)
                return false;
        return true;
    }

    void reverseDelete();       // Implemented below
};

// Main Logic of Code
void Graph::reverseDelete() {
    sort(edges.begin(), edges.end(), compare);

    // Traverse in descending order
    for (int i = edges.size() - 1; i >= 0; i--) {
        int u = edges[i].src;
        int v = edges[i].dest;
        int w = edges[i].weight;

        adjList[u].remove(v);
        adjList[v].remove(u);

        if (isConnected() == false) {
            adjList[u].push_back(v);
            adjList[v].push_back(u);

            // This edge is a part of MST
            printf("Edge (u = %d, v = %d, w = %d)\n", u, v, w);
        }
    }
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

    g.reverseDelete();
    return 0;
}