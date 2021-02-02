/*
Given a Weighted Directed Acyclic Graph (DAG) and a source vertex s in it, find 
the longest distances from s to all other vertices in the given graph.
*/

#include<bits/stdc++.h>
using namespace std;

struct Edge {
    int src, dest, weight;
};

class Graph {
public:
    // construct a vector of vectors to represent an adjacency list
    vector<vector<Edge>> adjList;

    Graph(vector<Edge> const &edges, int N) {
        // resize the vector to N elements of type vector<Edge>
        adjList.resize(N);

        // add edges to the directed graph
        for (Edge const &edge: edges) {
            adjList[edge.src].push_back(edge);
        }
    }
};

// Perform DFS on graph and set departure time of all vertices of the graph
void DFS(Graph const &graph, int v, vector<bool> &discovered, vector<int> &departure, int& time) {
    // mark current node as discovered
    discovered[v] = true;

    // set arrival time - not needed
    // time++;

    // do for every edge (v -> u)
    for (Edge e : graph.adjList[v]) {
        int u = e.dest;
        // u is not discovered
        if (!discovered[u]) {
            DFS(graph, u, discovered, departure, time);
        }
    }

    // ready to backtrack - set departure time of vertex v
    departure[time] = v;
    time++;
}

// The following function performs topological sort on a given DAG and then 
// finds out the longest distance of all vertices from given source by running 
// one pass of Bellman-Ford algorithm on edges of vertices in topological order.
void findLongestDistance(Graph const& graph, int source, int N) {
    // departure[] stores vertex number having its departure time 
    // equal to the index of it
    vector<int> departure(N, -1);

    // stores vertex is discovered or not
    vector<bool> discovered(N);
    int time = 0;

    // perform DFS on all undiscovered vertices
    for (int i = 0; i < N; i++) {
        if (!discovered[i]) {
            DFS(graph, i, discovered, departure, time);
        }
    }

    vector<int> cost(N, INT_MAX);
    cost[source] = 0;

    // Process the vertices in topological order i.e. in order
    // of their decreasing departure time in DFS
    for (int i = N - 1; i >= 0; i--) {
        // for each vertex in topological order, relax cost of its adjacent vertices
        int v = departure[i];
        for (Edge e : graph.adjList[v]) {
            // edge e from v to u having weight w
            int u = e.dest;
            int w = e.weight * -1;	// negative the weight of edge

            // if the distance to the destination u can be shortened by
            // taking the edge vu, then update cost to the new lower value
            if (cost[v] != INT_MAX && cost[v] + w < cost[u]) {
                cost[u] = cost[v] + w;
            }
        }
    }

    // Assigining proper signs to answer
    // for (int i = 0; i < N; i++) {
    // 	if (cost[i] != INT_MAX)
    // 		cost[i] = -cost[i];
    // }

    // print longest paths
    for (int i = 0; i < N; i++) {	
        if(cost[i] == INT_MAX)
            cout << "dist(" << source << ", " << i << ") = " << setw(2) << "INF";
        else
            cout << "dist(" << source << ", " << i << ") = " << setw(2) << -cost[i];
        cout << endl;
    }
}

/* --------------- MAIN DRIVER CODE ----------------- */
int main() {
    // vector of graph edges as per above diagram
    vector<Edge> edges = {
        {0, 1, 5}, {0, 2, 3}, {1, 3, 6}, {1, 2, 2}, {2, 4, 4}, {2, 5, 2},
        {2, 3, 7}, {3, 5, 1}, {3, 4, -1}, {4, 5, -2}
    };

    // Number of nodes in the graph
    int N = 6;

    Graph graph(edges, N);
    int source = 1;
    findLongestDistance(graph, source, N);

    return 0;
}
