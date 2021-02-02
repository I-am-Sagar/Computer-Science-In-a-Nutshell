/*
Given a matrix that is filled with 'O', 'G', and 'W' where 'O' represents open
space, 'G' represents guards and 'W' represents walls in a Bank. Replace all of
the O's in the matrix with their shortest distance from a guard, without being
able to go through any walls. Also, replace the guards with 0 and walls with -1
in output matrix.

O ==> Open Space
G ==> Guard
W ==> Wall

Input:
  O  O  O  O  G
  O  W  W  O  O
  O  O  O  W  O
  G  W  W  W  O
  O  O  O  O  G

Output:
  3  3  2  1  0
  2 -1 -1  2  1
  1  2  3 -1  2
  0 -1 -1 -1  1
  1  2  2  1  0

The idea is to do BFS. We first enqueue all cells containing the guards and
loop till queue is not empty. For each iteration of the loop, we dequeue the
front cell from the queue and for each of its four adjacent cells, if cell is
an open area and its distance from guard is not calculated yet, we update its
distance and enqueue it. Finally after BFS procedure is over, we print the
distance matrix.
*/

#include <bits/stdc++.h> 
using namespace std; 
#define N 5 

struct cell { 
    // i, j and distance stores x and y-coordinates of a matrix cell and 
    // its distance from guard respectively
    int i, j, distance; 
}; 

// These arrays are used to get row and column numbers of 4 neighbors of a given cell
int row[] = { -1, 0, 1, 0}; 
int col[] = { 0, 1, 0, -1 }; 

// return true if row number and column number is in range 
bool isValid(int i, int j, int m, int n) { 
    if ((i < 0 || i > m - 1) || (j < 0 || j > n - 1)) 
        return false; 
    return true; 
} 

// return true if current cell is an open area and its distance from guard 
// is not calculated yet
bool isSafe(int i, int j, char matrix[][N], int** output) { 
    if (matrix[i][j] != 'O' || output[i][j] != -1) 
        return false; 
    return true; 
} 

// Function to replace all of the O's in the matrix with their shortest 
// distance from a guard
void findDistance(char matrix[][N], int m, int n) { 
    int** output = new int*[m];
    for (int i = 0; i < m; i++)
        output[i] = new int[n];

    queue<cell> q; 

    // finding Guards location and adding into queue 
    for (int i = 0; i < m; i++) { 
        for (int j = 0; j < n; j++) { 
            // initialize each cell as -1 
            output[i][j] = -1; 
            if (matrix[i][j] == 'G') { 
                cell pos = {i, j, 0}; 
                q.push(pos); 
                // guard has 0 distance 
                output[i][j] = 0; 
            } 
        } 
    } 

    // do till queue is empty 
    while (!q.empty()) { 
        // get the front cell in the queue and update its adjacent cells 
        cell curr = q.front(); 
        int x = curr.i, y = curr.j, dist = curr.distance; 

        for (int i = 0; i < 4; i++) { 
            // if adjacent cell is valid, has path and not visited yet, en-queue it. 
            if (isSafe(x + row[i], y + col[i], matrix, output) && \
            isValid(x + row[i], y + col[i], m, n)) { 
                output[x + row[i]][y + col[i]] = dist + 1; 

                cell pos = {x + row[i], y + col[i], dist + 1}; 
                q.push(pos); 
            } 
        } 
        // dequeue the front cell as its distance is found 
        q.pop(); 
    } 

    // print output matrix 
    for (int i = 0; i < m; i++) { 
        for (int j = 0; j < n; j++) 
            cout << std::setw(3) << output[i][j]; 
        cout << endl; 
    } 
} 

/* ------------------ MAIN DRIVER CODE ------------------- */
int main() { 
    int m = 5, n = 5;

    char matrix[][N] = { 
        {'O', 'O', 'O', 'O', 'G'}, 
        {'O', 'W', 'W', 'O', 'O'}, 
        {'O', 'O', 'O', 'W', 'O'}, 
        {'G', 'W', 'W', 'W', 'O'}, 
        {'O', 'O', 'O', 'O', 'G'} 
    }; 

    findDistance(matrix, m, n); 

    return 0; 
} 