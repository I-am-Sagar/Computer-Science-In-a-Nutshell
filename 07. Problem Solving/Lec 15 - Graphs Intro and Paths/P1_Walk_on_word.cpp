/*  PROBLEM:

    There is a N x M matrix containing uppercase English alphabets only.
    Your task is to tell if there is a path in the matrix which makes
    the word 'LEETCODE'. There is a path from any cell to all its
    neighbouring cells. A neighbour may share an edge or a corner.

    Input:
    First line contains two spaced integers M and N.
    Next N lines will contain N rows of the matrix.

    Output:
    Print 1 if there is a path or else print 0.

    Constraints:
    1 <= N, M <= 100
*/

#include <bits/stdc++.h>
using namespace std;
#define MAX 101

// Main Logic of code
int cc[] = {-1, 1, 1, -1, 0, 0, -1, 1};
int rr[] = {-1, 1, -1, 1, -1, 1, 0, 0};
int solveUtil (char graph[][MAX], int n, int m, int r, int c, bool** visited, char arr[], int node) {
    for (int i = 0; i < 8; i++) {
        int a, b;
        a = r + rr[i];
        b = c + cc[i];

        if (a < 0 || b < 0 || a >= n || b >= m)
            continue;
        if (visited[a][b])
            continue;

        if (graph[a][b] == arr[0]) {
            visited[a][b] = true;
            int ans = solveUtil (graph, n, m, a, b, visited, arr+1, node+1);
            if (ans == 1)
                return 1;
            visited[a][b] = false;
        }
    }
    if (node == 8)
        return 1;
    else
        return 0;
}

int solve(char graph[][MAX],int n, int m) {

    bool** visited = new bool*[n];
    for (int i = 0; i < n; i++) {
        visited[i] = new bool[m];
        for (int j = 0; j < m; j++)
            visited[i][j] = false;
    }

    char arr[] = {'L', 'E', 'E', 'T', 'C', 'O', 'D', 'E'};
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (graph[i][j] == 'L') {
                visited[i][j] = true;
                int ans = solveUtil (graph, n, m, i, j, visited, arr+1, 1);
                if (ans == 1)
                    return ans;
            }
        }
    return 0;
}

/* -------------- MAIN DRIVER CODE ------------- */
int main() {
    int N, M, i;
    char Graph[MAX][MAX];
    cin >> N >> M;
    for(i = 0; i < N; i++)
        cin >> Graph[i];

    cout << solve (Graph,N,M) << endl;
    return 0;
}