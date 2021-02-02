/*  PROBLEM:
    Given a DAG, print all topological sorts of the graph.

    SOLUTION:
    We can go through all possible ordering via backtracking , 
    the algorithm steps are as follows :

    1. Initialize all vertices as unvisited.
    2. Now choose vertex which is unvisited and has zero indegree 
       and decrease indegree of all those vertices by 1 (corresponding 
       to removing edges) now add this vertex to result and call the 
       recursive function again and backtrack.
    3. After returning from function reset values of visited, result 
       and indegree for enumeration of other possibilities.
*/

#include<bits/stdc++.h>
using namespace std;

// Main Logic of code
void allTopoSortUtil (vector<int>* adj, int n, int indegree[], bool visited[], vector<int> &res) {
    // flag to indicate whether all topo sorts have been found or not
    bool flag = false;

    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0 && !visited[i]) {
            // Reduce the indegree of adjacent vertices
            for (auto j = adj[i].begin(); j != adj[i].end(); j++)
                indegree[*j]--;
            
            // including in result
            res.push_back(i);
            visited[i] = true;
            allTopoSortUtil(adj, n, indegree, visited,res);

            // Resetting visited, res and indegree for backtracking
            visited[i] = false;
            res.erase(res.end()-1);
            for (auto j = adj[i].begin(); j != adj[i].end(); j++)
                indegree[*j]++;
            
            flag = true;
        }
    }
    if (!flag) {
        for (int i = 0; i < res.size(); i++)
            cout << res[i]  << " ";
        cout << endl;
    }
}

void allTopoSort (vector<int>* adj, int n) {
    bool* visited = new bool[n]();
    vector<int> res;

    int* indegree = new int[n]();
    for (int i = 0; i < n; i++)
        for (auto itr = adj[i].begin(); itr != adj[i].end(); itr++)
            indegree[*itr]++;

    allTopoSortUtil(adj, n, indegree, visited, res);
}

/* --------------- MAIN DRIVER CODE ----------------- */
int main() {
    int n, e;
    cin >> n >> e;

    vector<int>* graph = new vector<int>[n];
    int a, b;
    for (int i = 0; i < e; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
    }

    allTopoSort(graph, n);
    
    return 0;
}