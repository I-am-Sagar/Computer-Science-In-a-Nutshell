/*
Tarjan Algorithm is based on following facts:

1. DFS search produces a DFS tree/forest
2. Strongly Connected Components form subtrees of the DFS tree.
3. If we can find the head of such subtrees, we can print/store all the nodes in
   that subtree (including head) and that will be one SCC.
4. There is no back edge from one SCC to another (There can be cross edges, but
   cross edges will not be used while processing the graph).

To find head of a SCC, we calculate disc and low array (as done for articulation
point, bridge, biconnected component). As discussed in the previous posts,
low[u] indicates earliest visited vertex (the vertex with minimum discovery time)
that can be reached from subtree rooted with u. A node u is head if -
    disc[u] = low[u].
*/
#include <bits/stdc++.h>
using namespace std;

#define NILL -1

class Graph {
    int V;
    list<int> *adj;

    void SCCUtil(int u, int disc[], int low[], stack<int> *st, bool stackMember[]);
public:
    Graph(int V) {
        this->V = V;
        adj = new list<int>[V];
    }

    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }

    void SCC();
};

// A recursive function that finds and prints SCCs using DFS traversal

// u --> The vertex to be visited next
// disc[] --> Stores discovery times of visited vertices
// low[] -- > earliest visited vertex (the vertex with minimum discovery time)
//            that can be reached from subtree rooted with current vertex
// *st -- > To store all the connected ancestors (could be part of SCC)
// stackMember[] --> bit/index array for faster check whether a node is in stack
void Graph::SCCUtil(int u, int disc[], int low[], stack<int> *st, bool stackMember[]) {
    // A static variable is used for simplicity, we can avoid use of static
    // variable by passing a pointer.
    static int time = 0;

    // Initialize discovery time and low value
    disc[u] = low[u] = ++time;
    st->push(u);
    stackMember[u] = true;

    // Go through all vertices adjacent to this
    list<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); ++i) {
        int v = *i; // v is current adjacent of 'u'

        // If v is not visited yet, then recur for it
        if (disc[v] == -1) {
            SCCUtil(v, disc, low, st, stackMember);

            // Check if the subtree rooted with 'v' has a connection to one of
            // the ancestors of 'u' for Case 1.
            low[u] = min(low[u], low[v]);
        }

        // Update low value of 'u' only of 'v' is still in stack (i.e. it's a
        // back edge, not cross edge) for Case 2.
        else if (stackMember[v] == true)
            low[u] = min(low[u], disc[v]);
    }
    // head node found, pop the stack and print an SCC
    int w = 0; // To store stack extracted vertices
    if (low[u] == disc[u]) {
        while (st->top() != u) {
            w = (int) st->top();
            cout << w << " ";
            stackMember[w] = false;
            st->pop();
        }
        w = (int) st->top();
        cout << w << "\n";
        stackMember[w] = false;
        st->pop();
    }
}

// The function to do DFS traversal. It uses SCCUtil()
void Graph::SCC() {
    int *disc = new int[V];
    int *low = new int[V];
    bool *stackMember = new bool[V];
    stack<int> *st = new stack<int>();

    // Initialize disc and low, and stackMember arrays
    for (int i = 0; i < V; i++) {
        disc[i] = NILL;
        low[i] = NILL;
        stackMember[i] = false;
    }
    // Call the recursive helper function to find strongly
    // connected components in DFS tree with vertex 'i'
    for (int i = 0; i < V; i++)
        if (disc[i] == NILL)
            SCCUtil(i, disc, low, st, stackMember);
}

/* ---------------- MAIN DRIVER CODE ---------------- */
int main() {
    cout << "\nSCCs in first graph: \n";
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.SCC();

    cout << "\nSCCs in second graph: \n";
    Graph g2(4);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);
    g2.SCC();

    cout << "\nSCCs in third graph: \n";
    Graph g3(7);
    g3.addEdge(0, 1);
    g3.addEdge(1, 2);
    g3.addEdge(2, 0);
    g3.addEdge(1, 3);
    g3.addEdge(1, 4);
    g3.addEdge(1, 6);
    g3.addEdge(3, 5);
    g3.addEdge(4, 5);
    g3.SCC();

    cout << "\nSCCs in fourth graph: \n";
    Graph g4(11);
    g4.addEdge(0,1);g4.addEdge(0,3);
    g4.addEdge(1,2);g4.addEdge(1,4);
    g4.addEdge(2,0);g4.addEdge(2,6);
    g4.addEdge(3,2);
    g4.addEdge(4,5);g4.addEdge(4,6);
    g4.addEdge(5,6);g4.addEdge(5,7);g4.addEdge(5,8);g4.addEdge(5,9);
    g4.addEdge(6,4);
    g4.addEdge(7,9);
    g4.addEdge(8,9);
    g4.addEdge(9,8);
    g4.SCC();

    cout << "\nSCCs in fifth graph: \n";
    Graph g5(5);
    g5.addEdge(0,1);
    g5.addEdge(1,2);
    g5.addEdge(2,3);
    g5.addEdge(2,4);
    g5.addEdge(3,0);
    g5.addEdge(4,2);
    g5.SCC();

    return 0;
}