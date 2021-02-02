#include <bits/stdc++.h>
using namespace std;

class Edge{
    public:
        int src, dest, weight;
        Edge(int src, int dest, int weight) {
            this->src = src;
            this->dest = dest;
            this->weight = weight;
        }
};

// Wrapper class for Graph
class Graph {
    int V, E;
    vector<Edge> edges;

public:
    Graph(int V, int E) {
        this->V = V;
        this->E = E;
    }

    void addEdge(int u, int v, int w) {
        edges.push_back(Edge(u, v, w));
    }

    void BellmanFord(int src); // Implemented below
};

// Main Logic
void Graph::BellmanFord(int src) {
    int* distance = new int[V];
    for (int i = 0; i < V; i++)
        distance[i] = INT_MAX;
    distance[src] = 0;

    for (int i = 1; i < V-1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int weight = edges[j].weight;

            if (distance[u] != INT_MAX && distance[u] + weight < distance[v])
                distance[v] = distance[u] + weight;
        }
    }

    // Following step checks for the negative weight cycle
    for (int i = 0; i < E; i++) {
        int u = edges[i].src;
        int v = edges[i].dest;
        int weight = edges[i].weight;
        if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
            printf("Graph contains negative weight cycle.\n");
            return;
        }
    }

    cout << "Vertex    Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout << i << "\t\t" << distance[i] << endl;

    return;
}

/* ------------------ MAIN DRIVER CODE ------------------- */
int main() {
    int V = 5, E = 8;
    Graph g(V, E);

    g.addEdge(0, 1, -1);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 2);
    g.addEdge(1, 4, 2);
    g.addEdge(3, 2, 5);
    g.addEdge(3, 1, 1);
    g.addEdge(4, 3, -3);

    g.BellmanFord(0);
    return 0;
}