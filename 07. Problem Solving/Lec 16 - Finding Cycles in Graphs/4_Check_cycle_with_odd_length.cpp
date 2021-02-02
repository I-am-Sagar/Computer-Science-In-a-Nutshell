/*  PROBLEM:
    Given a graph, the task is to find if it has a cycle
    of odd length or not.

    SOLUTION:
    The idea is based on an important fact that a graph
    does not contain a cycle of odd length if and only if
    it is Bipartite, i.e., it can be colored with two colors.

    It is obvious that if a graph has an odd length cycle
    then it cannot be Bipartite. In Bipartite graph there
    are two sets of vertices such that no vertex in a set
    is connected with any other vertex of the same set).
    For a cycle of odd length, two vertices must of the same
    set be connected which contradicts Bipartite definition.

    Below is code to check if a graph has odd cycle or not.
    The code basically checks whether graph is Bipartite.
*/
#include <bits/stdc++.h>
using namespace std;

// Function returns true if it contains odd length cycle
bool containsOdd (vector<int>* graph, int n) {
    int color[n] = {-1};
    // Assign first color to source, here 0 is source
    color[0] = 1;
    // Create a queue for BFS traversal
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        // Return true if there is a self loop
        for (int i = 0; i < graph[u].size(); i++)
            if (graph[u][i] == u)
                return true;
        // For all non colored adjacent vertices
        for (int i = 0; i < n; i++) {
            for (auto itr = graph[i].begin(); itr != graph[i].end(); itr++)
                if (color[*itr] == -1) {
                    color[*itr] = 1 - color[u];
                    q.push(*itr);
                }
                else if (color[*itr] == color[u]) {
                    return true;
                }
        }
    }
    return false;
}

/* ------------------ MAIN DRIVER CODE ----------------- */
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

    containsOdd (graph, n) ? (cout << "Yes.\n") : (cout  << "No.\n");
    return 0;
}