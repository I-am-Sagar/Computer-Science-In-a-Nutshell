#include <bits/stdc++.h>
using namespace std;

// map is used to map
bool getPath (int** adj, int n, int s, int d, bool* vis, int* parent) {
    queue<int> q;
    q.push(s);
    vis[s] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (u == d)
            return true;

        for (int i = 0; i < n; i++)
            if (adj[u][i] == 1 && !vis[i]) {
                q.push(i);
                parent[i] = u;
                vis[i] = true;
            }
    }
    return false;
}

/* -------------------- MAIN DRIVER CODE ----------------- */
int main() {
    int N, E;
    cin >> N >> E;

    int** adj = new int*[N];
    for (int i = 0; i < N; i++) {
        adj[i] = new int[N];
        for (int j = 0; j < N; j++)
            adj[i][j] = 0;
    }

    int a, b;
    while (E--) {
        cin >> a >> b;
        adj[a][b] = 1;
        adj[b][a] = 1;
    }

    int v1, v2;
    cin >> v1 >> v2;

    bool* visited = new bool[N]();
    int* parent = new int[N];
    for (int i = 0; i < N; i++)
        parent[i] = -1;

    if (getPath(adj, N, v1, v2, visited, parent)) {
        /* The parent array points from destination to source
           i.e. in reverse direction. So we will store reverse
           path in vector and print it in reverse way, to get
           proper s to d path.  */
        vector<int> path;
        int crawl = v2;
        path.push_back(crawl);
        while (parent[crawl] != -1) {
            path.push_back(parent[crawl]);
            crawl = parent[crawl];
        }

        for (int i = path.size()-1; i >= 0; i--)
            cout << path[i] << " ";
        cout << endl;
    }

    return 0;
}