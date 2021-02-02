/*
Given a two dimensional grid, each cell of which contains integer cost which
represents a cost to traverse through that cell, we need to find a path from
top left cell to bottom right cell by which total cost incurred is minimum.

It is not possible to solve this problem using dynamic programming because
here current state depends not only on right and bottom cells but also on
left and upper cells. We solve this problem using dijkstra's algorithm.
Each cell of grid represents a vertex and neighbor cells gridacent st.
We do not make an explicit graph from these cells instead we will use matrix
as it is in our dijkstra's algorithm.
*/

#include <bits/stdc++.h>
using namespace std;

// Class for information of each cell
class cell {
public:
    int x, y, distance;
    // newer syntax for constructor
    cell (int x, int y, int distance): x(x), y(y), distance(distance) {}
};

// Utility method for comparing two cells (operator '<' overloaded)
bool operator < (const cell &a, const cell &b) {
    if (a.distance == b.distance) {
        if (a.x != b.x)
            return (a.x < b.x);
        else
            return (a.y < b.y);
    }
    return (a.distance < b.distance);
}

// Utility method to check whether the point is inside grid or not
bool isInsideGrid(int i, int j, int row, int col) {
    return (i >= 0 && i < col && j >= 0 && j < row);
}

// Main Logic
int dijkstra(vector<vector<int>> grid, int row, int col) {
    int dis[row][col];

    // initializing distance array by INT_MAX
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            dis[i][j] = INT_MAX;

    // direction arrays for simplification of getting neighbour
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};

    set<cell> st;

    // insert (0, 0) cell with 0 distance
    st.insert(cell(0, 0, 0));

    // initialize distance of (0, 0) with its grid value
    dis[0][0] = grid[0][0];

    while (!st.empty()) {
        cell k = *(st.begin());
        st.erase(st.begin());

        for (int i = 0; i < 4; i++) {
            int x = k.x + dx[i];
            int y = k.y + dy[i];

            // if not inside boundary, ignore them
            if (!isInsideGrid(x, y, row, col))
                continue;

            // If distance from current cell is smaller, then update distance
            // of neighbour cell
            if (dis[x][y] > dis[k.x][k.y] + grid[x][y]) {
                // If cell is already there in set, then remove its previous entry
                if (dis[x][y] != INT_MAX)
                    st.erase(st.find(cell(x, y, dis[x][y])));
                // update the distance and insert new updated cell in set
                dis[x][y] = dis[k.x][k.y] + grid[x][y];
                st.insert(cell(x, y, dis[x][y]));
            }
        }
    }
    return dis[row - 1][col - 1];
}

/* ------------------ MAIN DRIVER CODE ------------------- */
int main() {
    int row = 5, col = 5;

    vector<vector<int>> grid {
        {31, 100, 65, 12, 18},
        {10, 13, 47, 157, 6},
        {100, 113, 174, 11, 33},
        {88, 124, 41, 20, 140},
        {99, 32, 111, 41, 20},
    };

    cout << dijkstra(grid, row, col) << endl;

    return 0;
}