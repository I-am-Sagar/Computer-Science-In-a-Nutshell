/*  PROBLEM:

    You have a board of size N x M. Each cell in the board has a
    colored dot. There are only 26 colors denoted by A, B, ..., Z.
    Now you need to find a cycle that contains dots of same color.
    Formally, we call a sequence of dots d1, d2, ..., dk a cycle
    if and only if it meets the following condition:

    1. All the k dots are different and k is atleast 4.
    2. All dots belong to same color.
    3. For all i, 1 <= i <= k-1, di and di+1 are adjacent.
       Cells x and y are adjacent if they share an edge.

    Input:
    Line 1 : Two integers N and M
    Next N lines : a string consisting of M characters

    Output:
    Return 1 if there is a cycle else return 0

    Constraints:
    2 <= N, M <= 50
*/

#include<bits/stdc++.h>
using namespace std;
#define MAX 51

// Main Logic of code
bool visited[MAX][MAX];
int cycleFound = 0;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void dfs (char board[][MAX], int n, int m, int x, int y, int fromX, int fromY, char colorNeeded) {
    if (x < 0 || x >= n || y < 0 || y >= m) return;
    if (board[x][y] != colorNeeded) return;
    if (visited[x][y]) {
        cycleFound = 1;
        return;
    }
    visited[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nextX = x + dx[i];
        int nextY = y + dy[i];
        if (nextX == fromX && nextY == fromY)
            continue;
        dfs(board, n, m, nextX, nextY, x, y, colorNeeded);
    }
}

int connectDots(char board[][MAX], int n, int m) {
    int i, j;
    memset(visited, false, sizeof(visited));

    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            if (!visited[i][j])
                dfs(board, n, m, i, j, 0, 0, board[i][j]);
    return cycleFound;
}

/* ----------- MAIN DRIVER CODE ------------ */
int main() {
    int N,M,i;
    char board[MAX][MAX];
    cin >> N >> M;
    for(i = 0; i < N; i++)
        cin >> board[i];

    cout << connectDots(board,N,M) << endl;
    return 0;
}