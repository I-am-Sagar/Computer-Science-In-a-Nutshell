// Tutorial: https://www.hackerearth.com/practice/algorithms/graphs/flood-fill-algorithm/tutorial/

/*  Flood fill algorithm can be simply modeled as graph traversal problem,
    representing the given area as a matrix and considering every cell of
    that matrix as a vertex that is connected to points above it, below it,
    to right of it, and to left of it and in case of 8-connections, to the
    points at both diagonals also.

    In general, any cell (x, y) is connected to (x-1, y-1), (x-1, y), (x-1, y+1),
    (x, y-1), (x, y+1), (x+1, y-1), (x+1, y), (x+1, y+1). Of course, boundary
    conditions are to be kept in mind.

    This area now can be modelled as a graph. For (x,y) cell, all possible 8
    neighbours are its adjacent cells. So DFS or BFS can be used to traverse
    the graph. The pseudocode for DFS is :

    function DFS(x, y, visited, n, m):
        if (x ≥ n OR y ≥ m)
            return
        if(x < 0 OR y < 0)
            return
        if(visisted[x][y] == True)
            return
        visited[x][y] = True
        DFS(x-1, y-1, visited, n, m)
        DFS(x-1, y, visited, n, m)
        DFS(x-1, y+1, visited, n, m)
        DFS(x, y-1, visited, n, m)
        DFS(x, y+1, visited, n, m)
        DFS(x+1, y-1, visited, n, m)
        DFS(x+1, y, visited, n, m)
        DFS(x+1, y+1, visited, n, m)

    The above code visits each and every cell of matrix of size n x m.
    Time Complexity: O(n*m)

    One important use of Flood Fill Algorithm is to solve a matrix maze.
    Lets implement the algorithm below by solving the following question:

    PROBLEM:
    A maze is represented by a matrix of size N x M, where rows are
    numbered from 1 to N and columns are numbered from 1 to M.
    Each cell of a matrix can be either 0 or 1. If a cell is 0, that
    cell cannot be visited and if it is 1, it can be visited. Allowed
    moves are U(up), D(down), L(left), R(right). Find a path from cell
    (1, 1) to (N, M) given that the source and destination cells always
    have value 1. If there is no path, print -1.
*/

#include<bits/stdc++.h>
using namespace std;

// Main Logic of Code
bool solveMazeUtil(int** maze, bool** visited, int n, int m, int currX, int currY, stack<char> &route) {
    if (currX == n-1 && currY == m-1)
        return true;
    if (currX < 0 || currX >= n || currY < 0 || currY >= m) {
        if (!route.empty())
            route.pop();
        return false;
    }
    if (visited[currX][currY] || (maze[currX][currY] == 0)) {
        if (!route.empty())
            route.pop();
        return false;
    }
    visited[currX][currY] = true;

    if (solveMazeUtil(maze, visited, n, m, currX+1, currY, route)) {
        route.push('D');
        return true;
    }
    if (solveMazeUtil(maze, visited, n, m, currX-1, currY, route)) {
        route.push('U');
        return true;
    }
    if (solveMazeUtil(maze, visited, n, m, currX, currY+1, route)) {
        route.push('R');
        return true;
    }
    if (solveMazeUtil(maze, visited, n, m, currX, currY-1, route)) {
        route.push('L');
        return true;
    }
    return false;
}

string solveMaze (int** maze, int n, int m) {
    stack<char> route;
    bool** visited = new bool*[n];
    for (int i = 0; i < n; i++)
        visited[i] = new bool[m]();
    solveMazeUtil (maze, visited, n, m, 0, 0, route);

    string ans = "";
    while (!route.empty()) {
        ans += route.top();
        route.pop();
    }
    return ans;
}

/* -------------- MAIN DRIVER CODE ------------------ */
int main() {
    int N, M;
    cin >> N >> M;

    int** maze = new int*[N];
    for (int i = 0; i < N; i++)
        maze[i] = new int[M];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> maze[i][j];

    string path = solveMaze (maze, N, M);

    if (path.empty())
        cout << -1 << endl;
    else
        cout << path << endl;

    return 0;
}