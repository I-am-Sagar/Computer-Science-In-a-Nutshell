/*
    Approach 2: Using BFS
    Here is the algorithm to do so:

    1. Create a queue of vectors which will store path(s).
    2. Initialise the queue with first path starting from 'src'.
    3. Now run a loop till queue is not empty
        - Get the frontmost path from queue
        - Check if the lastnode of this path is destination
            a) If true then print the path
        - Run a loop for all the vertices connected to the current vertex
          i.e. lastnode extracted from path
        - If the vertex is not visited in current path
            a) create a new path from earlier path and append this vertex
            b) insert this new path to queue

*/

#include <bits/stdc++.h>
using namespace std;

// Utility function to print the vector (path)
void printPath (vector<int>& path) {
    int size = path.size();
    for (int i = 0; i < size; i++)
        cout << path[i] << " ";
    cout << endl;
}

// Utility function to check if current vertex is already present in path
bool isNotVisited(int x, vector<int>& path) {
    int size = path.size();
    for (int i = 0; i < size; i++)
        if (path[i] == x)
            return false;
    return true;
}

// Main Logic
void findPaths (vector<vector<int>> graph, int n, int src, int dest) {
    // Create a queue which stores paths
    queue<vector<int>> q;

    // Vector to store current path
    vector<int> path;
    path.push_back(src);
    q.push(path);

    while (!q.empty()) {
        path = q.front();
        q.pop();
        int last = path[path.size()-1];

        // If the last vertex is the desired destination
        if (last == dest)
            printPath(path);

        // Traverse to all the nodes connected to
        // current vertex and push new path to queue
        for (int i = 0; i < graph[last].size(); i++) {
            if (isNotVisited(graph[last][i], path)) {
                vector<int> newpath(path);
                newpath.push_back(graph[last][i]);
                q.push(newpath);
            }
        }
    }
}

/* --------------------- MAIN DRIVER CODE ------------------ */
int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> graph(V);
    int a, b;
    for (int i = 0; i < E; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        //graph[b].push_back(a);
    }

    int src, dest;
    cin >> src >> dest;

    findPaths(graph, V, src, dest);
    return 0;
}