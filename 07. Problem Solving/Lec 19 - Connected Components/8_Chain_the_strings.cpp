/*
Given an array of strings, find if the given strings can be chained to form a 
circle. A string X can be put before another string Y in circle if the last 
character of X is same as first character of Y.

Examples:

Input: arr[] = {"geek", "king"}
Output: Yes, the given strings can be chained.
Note that the last character of first string is same as first character of 
second string and vice versa is also true.

Input: arr[] = {"for", "geek", "rig", "kaf"}
Output: Yes, the given strings can be chained.
The strings can be chained as "for", "rig", "geek" and "kaf"

Input: arr[] = {"aab", "bac", "aaa", "cda"}
Output: Yes, the given strings can be chained.
The strings can be chained as "aaa", "aab", "bac" and "cda"

Input: arr[] = {"aaa", "bbb", "baa", "aab"};
Output: Yes, the given strings can be chained.
The strings can be chained as "aaa", "aab", "bbb" and "baa"

Input: arr[] = {"aaa"};
Output: Yes

Input: arr[] = {"aaa", "bbb"};
Output: No

Input  : arr[] = ["abc", "efg", "cde", "ghi", "ija"]
Output : Yes
These strings can be reordered as, "abc", "cde", "efg", "ghi", "ija"

Input : arr[] = ["ijk", "kji", "abc", "cba"]
Output : No

The idea is to create a directed graph of all characters and then find if their 
is an eulerian circuit in the graph or not.
*/

#include <bits/stdc++.h>
using namespace std; 

#define CHARS 26 

class Graph { 
    int V;
    list<int> *adj;
    int *in; 

public: 

    Graph(int V) {
        this->V = V; 
        adj = new list<int>[V]; 
        in = new int[V]; 
        for (int i = 0; i < V; i++) 
        in[i] = 0; 
    }; 
    ~Graph() { delete [] adj; delete [] in; } 

    // function to add an edge to graph 
    void addEdge(int v, int w) { adj[v].push_back(w); (in[w])++; } 

    // Method to check if this graph is Eulerian or not 
    bool isEulerianCycle(); 

    // Method to check if all non-zero degree vertices are connected 
    bool isSC(); 

    // Function to do DFS starting from v. Used in isConnected(); 
    void DFSUtil(int v, bool visited[]); 

    Graph getTranspose(); 
}; 


// This function returns true if the directed graph has an eulerian cycle.
bool Graph::isEulerianCycle() { 
    // Check if all non-zero degree vertices are connected 
    if (isSC() == false) 
        return false; 

    // Check if in degree and out degree of every vertex is same 
    for (int i = 0; i < V; i++) 
        if (adj[i].size() != in[i]) 
            return false; 

    return true; 
} 

// A recursive function to do DFS starting from v 
void Graph::DFSUtil(int v, bool visited[]) { 
    // Mark the current node as visited and print it 
    visited[v] = true; 

    // Recur for all the vertices adjacent to this vertex 
    list<int>::iterator i; 
    for (i = adj[v].begin(); i != adj[v].end(); ++i) 
        if (!visited[*i]) 
            DFSUtil(*i, visited); 
} 

// Function that returns reverse (or transpose) of this graph.
// This function is needed in isSC().
Graph Graph::getTranspose() { 
    Graph g(V); 
    for (int v = 0; v < V; v++) { 
        // Recur for all the vertices adjacent to this vertex 
        list<int>::iterator i; 
        for(i = adj[v].begin(); i != adj[v].end(); ++i) { 
            g.adj[*i].push_back(v); 
            (g.in[v])++; 
        } 
    } 
    return g; 
} 

// This function returns true if all non-zero degree vertices of 
// graph are strongly connected. 
bool Graph::isSC() { 
    // Mark all the vertices as not visited (For first DFS) 
    bool visited[V]; 
    for (int i = 0; i < V; i++) 
        visited[i] = false; 

    // Find the first vertex with non-zero degree 
    int n; 
    for (n = 0; n < V; n++) 
        if (adj[n].size() > 0) 
            break; 

    // Do DFS traversal starting from first non zero degree vertex. 
    DFSUtil(n, visited); 

    // If DFS traversal doesn't visit all vertices, then return false. 
    for (int i = 0; i < V; i++) 
        if (adj[i].size() > 0 && visited[i] == false) 
            return false; 

    // Create a reversed graph 
    Graph gr = getTranspose(); 

    // Mark all the vertices as not visited (For second DFS) 
    for (int i = 0; i < V; i++) 
        visited[i] = false; 

    // Do DFS for reversed graph starting from first vertex. 
    // Staring Vertex must be same starting point of first DFS 
    gr.DFSUtil(n, visited); 

    // If all vertices are not visited in second DFS, then return false 
    for (int i = 0; i < V; i++) 
        if (adj[i].size() > 0 && visited[i] == false) 
            return false; 

    return true; 
} 

// This function takes an of strings and returns true if the given array of 
// strings can be chained to form cycle.
bool canBeChained(string arr[], int n) { 
    // Create a graph with 'aplha' edges 
    Graph g(CHARS); 

    // Create an edge from first character to last character 
    // of every string 
    for (int i = 0; i < n; i++) { 
        string s = arr[i]; 
        g.addEdge(s[0]-'a', s[s.length()-1]-'a'); 
    } 

    // The given array of strings can be chained if there 
    // is an eulerian cycle in the created graph 
    return g.isEulerianCycle(); 
} 

/* ---------------- MAIN DRIVER CODE ----------------- */
int main() { 
    string arr1[] = {"for", "geek", "rig", "kaf"}; 
    int n1 = sizeof(arr1)/sizeof(arr1[0]); 
    canBeChained(arr1, n1)? cout << "Can be chained.\n" : cout << "Can't be chained.\n"; 

    string arr2[] = {"aab", "abb"}; 
    int n2 = sizeof(arr2)/sizeof(arr2[0]); 
    canBeChained(arr2, n2)? cout << "Can be chained.\n" : cout << "Can't be chained.\n"; 

    return 0; 
} 
