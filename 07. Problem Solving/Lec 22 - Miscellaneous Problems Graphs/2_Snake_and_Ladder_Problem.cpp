/*
Given a snake and ladder board, find the minimum number of dice throws required
to reach the destination or last cell from source or 1st cell. Basically, the
player has total control over outcome of dice throw and wants to find out
minimum number of throws required to reach last cell.

If the player reaches a cell which is base of a ladder, the player has to climb
up that ladder and if reaches a cell is mouth of the snake, has to go down to
the tail of snake without a dice throw.

For example, consider the board shown, the minimum number of dice throws
required to reach cell 30 from cell 1 is 3. Following are the steps:

    a) First throw two on dice to reach cell number 3 and then ladder to reach 22
    b) Then throw 6 to reach 28.
    c) Finally through 2 to reach 30.

There can be other solutions as well like (2, 2, 6), (2, 4, 4), (2, 3, 5).. etc.

The idea is to consider the snake and ladder board as a directed graph with
number of vertices equal to the number of cells in the board. The problem
reduces to finding the shortest path in a graph. Every vertex of the graph
has an edge to next six vertices if next 6 vertices do not have a snake or
ladder. If any of the next six vertices has a snake or ladder, then the edge
from current vertex goes to the top of the ladder or tail of the snake.
Since all edges are of equal weight, we can efficiently find shortest path
using Breadth First Search of the graph.
*/

#include <bits/stdc++.h>
using namespace std;

// Number of vertices in the graph - 10 x 10 board
#define N 100

struct Edge {
    int src, dest;
};

class Graph {
public:
    vector<int> adjList[N + 1];

    Graph(vector<Edge> const &edges) {
        for (int i = 0; i < edges.size(); i++) {
            int src = edges[i].src;
            int dest = edges[i].dest;

            adjList[src].push_back(dest);   // Directed graph
        }
    }
};

// A queue node
struct Node {
    // stores number associated with graph node
    int ver;
    // minDist stores minimum distance of node from starting vertex
    int minDist;
};

// Perform BFS on graph g starting from given source vertex
int BFS(Graph const& g, int source) {
    queue<Node> q;
    vector<bool> discovered(N + 1);
    discovered[source] = true;
    Node node = { source, 0 };
    q.push(node);
    int answer = 0;

    while (!q.empty()) {
        node = q.front();
        q.pop();
        // Stop BFS for the last node
        if (node.ver == N) {
            answer = node.minDist;
            break;
        }

        // do for every adjacent node of current node
        for (int u: g.adjList[node.ver]) {
            if (!discovered[u]) {
                // mark it discovered & push it into queue
                discovered[u] = true;

                // assign minimum distance of current node
                // as minimum distance of parent node + 1
                Node n = { u, node.minDist + 1 };
                q.push(n);
            }
        }
    }
    return answer;
}

int findMinThrows(unordered_map<int, int> &ladder, unordered_map<int, int> &snake) {
    // find all edges involved and store them in a vector
    vector<Edge> edges;
    for (int i = 0; i < N; i++) {
        for (int j = 1; j <= 6 && i + j <= N; j++) {
            int src = i;

            // update destination if there is any ladder
            // or snake from current position.
            int dest = (ladder[i+j] || snake[i+j]) ? (ladder[i+j] + snake[i+j]) : (i+j);

            // add edge from src to dest
            Edge e = { src, dest };
            edges.push_back(e);
        }
    }
    Graph g(edges);
    return BFS(g, 0);
}

/* ------------------ MAIN DRIVER CODE ------------------- */
int main() {
    // snakes and ladders are represented using a map
    unordered_map<int, int> ladder, snake;

    // insert ladders into the map
    ladder[2] = 21;
    ladder[4] = 7;
    ladder[10] = 25;
    ladder[19] = 28;

    // insert snakes into the map
    snake[26] = 0;
    snake[20] = 8;
    snake[16] = 3;
    snake[18] = 6;

    cout << "Minimum Dice Throws = " << findMinThrows(ladder, snake) << ".\n";

    return 0;
}