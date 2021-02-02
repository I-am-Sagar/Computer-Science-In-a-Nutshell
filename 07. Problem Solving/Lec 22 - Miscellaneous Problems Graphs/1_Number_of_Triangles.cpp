/*
Given an Undirected simple graph, We need to find how many triangles it can have.

Let A[][] be adjacency matrix representation of graph. If we calculate A3,
then the number of triangle in Undirected Graph is equal to trace(A3) / 6.
Where trace(A) is the sum of the elements on the main diagonal of matrix A.

How does this work?
If we compute A^n for an adjacency matrix representation of graph, then a value
A^n[i][j] represents number of distinct walks between vertex i to j in graph.

In A^3, we get all distinct paths of length 3 between every pair of vertices.

A triangle is a cyclic path of length three, i.e. begins and ends at same vertex.
So A^3[i][i] represents a triangle beginning and ending with vertex i.
Since a triangle has three vertices and it is counted for every vertex,
we need to divide result by 3. Furthermore, since the graph is undirected,
every triangle twice as i-p-q-j and i-q-p-j, so we divide by 2 also.
Therefore, number of triangles is trace(A3) / 6.

The time complexity of above algorithm is O(V3) where V is number of vertices.
*/

#include <bits/stdc++.h>
using namespace std;

// Number of vertices in the graph
#define V 4

void multiply(int A[][V], int B[][V], int C[][V]) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            C[i][j] = 0;
            for (int k = 0; k < V; k++)
                C[i][j] += A[i][k]*B[k][j];
        }
    }
}

int getTrace(int graph[][V]) {
    int trace = 0;
    for (int i = 0; i < V; i++)
        trace += graph[i][i];
    return trace;
}

int triangleInGraph(int graph[][V]) {
    // To Store graph^2
    int aux2[V][V];

    // To Store graph^3
    int aux3[V][V];

    // Initialising aux matrices with 0
    for (int i = 0; i < V; ++i)
        for (int j = 0; j < V; ++j)
            aux2[i][j] = aux3[i][j] = 0;

    // aux2 is graph^2 now printMatrix(aux2);
    multiply(graph, graph, aux2);

    // after this multiplication aux3 is graph^3 printMatrix(aux3);
    multiply(graph, aux2, aux3);

    int trace = getTrace(aux3);
    return trace / 6;
}

/* ------------------ MAIN DRIVER CODE ------------------- */
int main() {
    int graph[V][V] = {{0, 1, 1, 0},
                       {1, 0, 1, 1},
                       {1, 1, 0, 1},
                       {0, 1, 1, 0}};

    printf("Total number of Triangles in Graph : %d.\n", triangleInGraph(graph));
    return 0;
}
