#include <bits/stdc++.h>
using namespace std;

// Get parent method (Iterative)
int getParent(int i, int* parent) {
    while(parent[i] != i) {
        parent[i] = parent[parent[i]];
        i = parent[i];
    }
    return i;
}

// Function to perform union operation
void union_func(int i, int j, int* parent) {
    int a = getParent(i, parent);
    int b = getParent(j, parent);
    parent[a] = b;
}

// Main Algo (This implementation prints the results as well)
void kruskal (vector<vector<int>> cost, int V) {
    int* parent = new int[V];
    for (int i = 0; i < V; i++)
        parent[i] = i;

    int count = 0;
    while(count < V-1) {
        int min = INT_MAX, a = -1, b = -1;
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (getParent(i, parent) != getParent(j, parent) && cost[i][j] < min) {
                    min = cost[i][j];
                    a = i; b = j;
                }
            }
        }
        union_func(a, b, parent);
        printf("Edge %d:(%d, %d) cost:%d \n", count++, a, b, min);
    }
    delete[] parent;
}

/* ------------------ MAIN DRIVER CODE ------------------ */
int main() {
    int V = 5;

    vector<vector<int>> cost = {
        { INT_MAX, 2, INT_MAX, 6, INT_MAX },
        { 2, INT_MAX, 3, 8, 5 },
        { INT_MAX, 3, INT_MAX, INT_MAX, 7 },
        { 6, 8, INT_MAX, INT_MAX, 9 },
        { INT_MAX, 5, 7, 9, INT_MAX },
    };

    kruskal(cost, V);

    return 0;
}

