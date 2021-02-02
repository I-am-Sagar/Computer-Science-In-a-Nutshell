/*  PROBLEM:
    Given an undirected and connected graph and a number n,
    count total number of cycles of length n in the graph.

    SOLUTION:
    Using DFS we find every possible path of length (n-1) for
    a particular source (or starting point). Then we check if
    this path ends with the vertex it started with, if yes
    then we count this as the cycle of length n. Notice that we
    looked for path of length (n-1) because the nth edge will
    be the closing edge of cycle.

    Every possible path of length (n-1) can be searched using only
    V – (n – 1) vertices (where V is the total number of vertices).

    For example, consider the following graph:
    V = 5 and E = 6
    Edges are: 0 - 1, 1 - 2, 2 - 3, 3 - 4, 3 - 0 and 4 - 1.

    Total cycles of length 4 = 3. The cycles are:

        0 -> 1 -> 2 -> 3 -> 0
        0 -> 1 -> 4 -> 3 -> 0
        1 -> 2 -> 3 -> 4 -> 1

    For above example, all the cycles of length 4 can be searched using
    only 5-(4-1) = 2 vertices. The reason behind this is quite simple,
    because we search for all possible path of length (n-1) = 3 using
    these 2 vertices which include the remaining 3 vertices. So, these
    2 vertices cover the cycles of remaining 3 vertices as well, and
    using only 3 vertices we can’t form a cycle of length 4 anyways.

    One more thing to notice is that, every vertex finds 2 duplicate
    cycles for every cycle that it forms. For above example 0th vertex
    finds two duplicate cycle namely 0 -> 3 -> 2 -> 1 -> 0 and
    0 -> 1 -> 2 -> 3 -> 0. Hence the total count must be divided by 2
    because every cycle is counted twice.
*/

#include<bits/stdc++.h>
using namespace std;

// Main Logic of Code
void dfs (vector<int>* adj, bool* visited, int n, int length, int vert, int start, int &count) {
    visited[vert] = true;

    // If a path of length 'length' is found
    if (length == 0){
        visited[vert] = false;  // Mark it false so that it becomes usable again

        // Check if vertex 'vert' can end with vertex 'start'
        bool contains_start = false;
        for (int i = 0; i < adj[vert].size(); i++)
            if (adj[vert][i] == start)
                contains_start = true;

        if (contains_start) {
            count++;
            return;
        }
        else
            return;
    }

    // If the path of length 'length' is not found,
    // search for every other possible path of length 'length-1'
    for (int i = 0; i < adj[vert].size(); i++)
        if (!visited[adj[vert][i]])
            dfs(adj, visited, n, length-1, adj[vert][i], start, count);

    // mark vert as unvisited to make it usable again
    visited[vert] = false;
}

int countCycles(vector<int>* adj, int n, int length) {
    bool* visited = new bool[n]();
    int count = 0;
    for (int i = 0; i < n-(length-1); i++) {
            dfs(adj, visited, n, length-1, i, i, count);
            visited[i] = true;
    }
    return count/2;
}

/* --------------- MAIN DRIVER CODE ------------------ */
int main() {
    int n, e;
    cin >> n >> e;

    vector<int>* graph = new vector<int>[n];
    int a, b;
    for (int i = 0; i < e; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    //printGraph (graph, n);

    int length = 4;
    int count = countCycles (graph, n, length);
    cout << "Cycles of length " << length << " = " << count << endl;

    return 0;
}