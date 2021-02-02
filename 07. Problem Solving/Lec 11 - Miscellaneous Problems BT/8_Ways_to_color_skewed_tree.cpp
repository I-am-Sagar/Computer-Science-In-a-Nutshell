/*
Given a skewed tree (Every node has at most one child) with N nodes and K colors.
You have to assign a color from 1 to K to each node such that parent and child
has different colors. Find the maximum number of ways of coloring the nodes.

Input : N = 2, K = 2.
Output :
Let A1 and A2 be the two nodes.
Let A1 is parent of A2.
Colors are Red and Blue.
Case 1: A1 is colored Red and A2 is colored Blue.
Case 2: A1 is colored Blue and A2 is colored Red.
No. of ways : 2

Input : N = 3, K = 3.
Output :
A1, A2, A3 are the nodes.
A1 is parent of A2 and A2 is parent of A3.
Let colors be R, B, G.
A1 can choose any three colors and A2 can choose any other two colors
and A3 can choose any other two colors than its parents.
No. of ways: 12

APPROACH:
Note that only the root and children (children, grand children, grand grand
children ... and all) should have different colors. The root of the tree can
choose any of the K colors so K ways. Every other node can choose other K-1
colors other than its parent. So every node has K-1 choices.

Here, we select the tree as every node as only one child. We can choose any
of the K colors for the root of the tree so K ways. And we are left with K-1
colors for its child. So for every child we can assign a color other than its
parent. Thus, for each of the N-1 nodes we are left with K-1 colors. Thus the
answer is K*(K-1)^(N-1).

*/

#include <bits/stdc++.h>
using namespace std;

int fastPow(int N, int K) {
    if (K == 0)
        return 1;
    int temp = fastPow(N, K / 2);
    if (K % 2 == 0)
        return temp * temp;
    else
        return N * temp * temp;
}

int countWays(int N, int K) {
    return K * fastPow(K - 1, N - 1);
}

/* ---------------- MAIN DRIVER CODE --------------- */
int main() {
    int N = 3, K = 3;
    cout << countWays(N, K);
    return 0;
}
