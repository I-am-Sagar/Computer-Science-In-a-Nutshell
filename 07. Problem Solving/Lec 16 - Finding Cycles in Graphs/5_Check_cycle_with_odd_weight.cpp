/*
Given a weighted and undirected graph, we need to find if a cycle exist in this
graph such that the sum of weights of all the edges in that cycle comes out to
be odd.

Examples:

Input : Number of vertices, n = 4,
        Number of edges, m = 4
        Weighted Edges =
        1 2 2
        2 3 1
        4 3 1
        4 1 2
Output : No! There is no odd weight cycle in the given graph

Input : Number of vertices, n = 5,
        Number of edges, m = 3
        Weighted Edges =
        1 2 1
        3 2 1
        3 1 1
Output : Yes! There is an odd weight cycle in the given graph

APPROACH:

The solution is based on the fact that - "If a graph has no odd length cycle
then it must be Bipartite, i.e., it can be colored with two colors."

The idea is to convert given problem to a simpler problem where we have to just
check if there is cycle of odd length or not. To convert, we do following

- Convert all even weight edges into two edges of unit weight.
- Convert all odd weight edges to a single edge of unit weight.

For example, graph in Example 1) can be visualized as:

            1  -- pse1 -- 2
            |             |
           pse2           |
            |             |
            4 ----------- 3

Here, edges [1 — 2] have be broken in two parts such that [1-pseudo1-2] a
pseudo node has been introduced. We are doing this so that each of our even
weighted edge is taken into consideration twice while the edge with odd weight
is counted only once. Doing this would help us further when we color our cycle.

We assign all the edges with weight 1 and then by using 2 color method traverse
the whole graph. Now we start coloring our modified graph using two colors only.
In a cycle with even number of nodes, when we color it using two colors only,
none of the two adjacent edges have the same color. While if we try coloring a
cycle having odd number of edges, surely a situation arises where two adjacent
edges have the same color. This is our pick! Thus, if we are able to color the
modified graph completely using 2 colors only in a way no two adjacent edges get
the same color assigned to them then there must be either no cycle in the graph
or a cycle with even number of nodes. If any conflict arises while coloring a
cycle with 2 colors only, then we have an odd cycle in our graph.

*/

#include <bits/stdc++.h>
using namespace std;

// This function returns true if the current subpart of the forest is
// two colorable, else false.
bool twoColorUtil(vector<int>G[], int src, int N, int colorArr[]) {
    // Assign first color to source
    colorArr[src] = 1;

    // Create a queue (FIFO) of vertex numbers and enqueue source vertex
    // for BFS traversal
    queue <int> q;
    q.push(src);

    // Run while there are vertices in queue (Similar to BFS)
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        // Find all non-colored adjacent vertices
        for (int v = 0; v < G[u].size(); ++v){
            // An edge from u to v exists and destination v is not colored
            if (colorArr[G[u][v]] == -1) {
                // Assign alternate color to this adjacent v of u
                colorArr[G[u][v]] = 1 - colorArr[u];
                q.push(G[u][v]);
            }
            // An edge from u to v exists and destination v is colored with
            // same color as u
            else if (colorArr[G[u][v]] == colorArr[u])
                return false;
        }
    }
    return true;
}

// This function returns true if graph G[V][V] is two colorable, else false
bool twoColor(vector<int>G[], int N) {
    // Create a color array to store colors assigned to all veritces.
    // Vertex number is used as index in this array. The value '-1' of
    // colorArr[i] is used to indicate that no color is assigned to vertex 'i'.
    // The value 1 is used to indicate first color is assigned and value 0
    // indicates second color is assigned.
    int colorArr[N];
    for (int i = 1; i <= N; ++i)
        colorArr[i] = -1;

    // As we are dealing with graph, the input might come as a forest, thus
    // start coloring from a node and if true is returned we'll know that
    // we successfully colored the subpart of our forest and we start coloring
    // again from a new uncolored node. This way we cover the entire forest.
    for (int i = 1; i <= N; i++)
        if (colorArr[i] == -1)
        if (twoColorUtil(G, i, N, colorArr) == false)
            return false;

        return true;
}

// Returns false if an odd cycle is present else true
// int info[][] is the information about our graph
// int n is the number of nodes
// int m is the number of informations given to us
bool isOddSum(int info[][3], int n, int m) {
    // Declaring adjacency list of a graph
    // Here at max, we can encounter all the edges with
    // even weight thus there will be 1 pseudo node for each edge
    vector<int> G[2*n];

    int pseudo = n+1;
    int pseudo_count = 0;
    for (int i=0; i<m; i++) {
        // For odd weight edges, we directly add it
        // in our graph
        if (info[i][2]%2 == 1) {
            int u = info[i][0];
            int v = info[i][1];
            G[u].push_back(v);
            G[v].push_back(u);
        }
        // For even weight edges, we break it
        else {
            int u = info[i][0];
            int v = info[i][1];
            // Entering a pseudo node between u---v
            G[u].push_back(pseudo);
            G[pseudo].push_back(u);
            G[v].push_back(pseudo);
            G[pseudo].push_back(v);
            // Keeping a record of number of pseudo nodes inserted
            pseudo_count++;
            // Making a new pseudo node for next time
            pseudo++;
        }
    }
    // We pass number graph G[][] and total number of node =
    // actual number of nodes + number of pseudo nodes added.
    return twoColor(G,n+pseudo_count);
}

/* ------------------ MAIN DRIVER CODE ----------------- */
int main() {
    // 'n' correspond to number of nodes in our graph while
    // 'm' correspond to the number of information about this graph.
    int n = 4, m = 3;
    int info[4][3] = {{1, 2, 12},
                      {2, 3, 1},
                      {4, 3, 1},
                      {4, 1, 20}};

    // This function break the even weighted edges in two parts.
    // Makes the adjacency representation of the graph and sends it for two coloring.
    if (isOddSum(info, n, m) == true)
        cout << "No\n";
    else
        cout << "Yes\n";

    return 0;
}
