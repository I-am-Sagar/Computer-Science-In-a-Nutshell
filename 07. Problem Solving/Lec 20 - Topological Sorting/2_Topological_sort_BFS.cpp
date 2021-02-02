/*  We can also find Topological Sort using BFS and the
    algorithm is known as Kahn's algorithm.

    Step-1: Compute in-degree (number of incoming edges) 
    for each of the vertex present in the DAG and initialize 
    the count of visited nodes as 0.

    Step-2: Pick all the vertices with in-degree as 0 and 
    add them into a queue (Enqueue operation).

    Step-3: Remove a vertex from the queue (Dequeue operation) 
    and then -
        1. Increment count of visited nodes by 1.
        2. Decrease in-degree by 1 for all its neighboring nodes.
        3. If in-degree of a neighboring nodes is reduced to zero, 
        then add it to the queue.
    
    Step 4: Repeat Step 3 until the queue is empty.

    Step 5: If count of visited nodes is not equal to the number 
    of nodes in the graph then the topological sort is not possible 
    for the given graph.

    How to find indegree of each node?
    
        Traverse the list for every node and then increment the 
        in-degree of all the nodes connected to it by 1.
        Time Complexity: O(V+E)

    Overall time complexity: O(V+E)
*/

#include<bits/stdc++.h>
using namespace std;

// Main Logic of Code: Adj List implementation
void topologicalSort (vector<int>* adj, int n) {
    // Find indegree of each node in adj list
    int in_degree[n] = {0};
    for (int i = 0; i < n; i++)
        for (auto itr = adj[i].begin(); itr != adj[i].end(); itr++)
            in_degree[*itr]++;

    // Create a queue and enqueue all vertices with indegree 0
    queue<int> q;
    for (int i = 0; i < n; i++)
        if (in_degree[i] == 0)
            q.push(i);

    int count = 0;
    vector<int> topo_sort;

    // One by one dequeue vertices and enqueue adjacents if 
    // indegree of adjacent becomes zero
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topo_sort.push_back(u);

        for (auto itr = adj[u].begin(); itr != adj[u].end(); itr++)
            if (--in_degree[*itr] == 0)
                q.push(*itr);
        count++;
    }

    // Print the topological sort
    if (count != n) {
        cout << "There exists a cycle.\n";
    } else {
        for (int i = 0; i < topo_sort.size(); i++)
            cout << topo_sort[i] << " ";
        cout << endl;
    }
}

/* ------------- MAIN DRIVER CODE -------------- */
int main() {
    int n, e;
    cin >> n >> e;

    vector<int>* graph = new vector<int>[n];
    int a, b;
    for (int i = 0; i < e; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
    }

    topologicalSort (graph, n);

    return 0;
}