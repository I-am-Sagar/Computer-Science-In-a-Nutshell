/*  Consider a situation where we have a set of intervals and
    we need following operations to be implemented efficiently:
    1) Add an interval
    2) Remove an interval
    3) Given an interval x, find if x overlaps with any of
       the existing intervals.

    The idea is to use - "Interval Trees".
    Every node of Interval Tree stores following information.
    a) i: An interval which is represented as a pair [low, high]
    b) max: Maximum high value in subtree rooted with this node.

    The low value of an interval is used as key to maintain
    order in BST.

    Below we implement Interval Trees to solve Conflicting
    appointments (intervals) problem.
*/

#include <bits/stdc++.h>
using namespace std;

struct Interval {
    int low, high;
};

class Node {
    public:
    Interval *i;
    int max;
    Node *left, *right;
    Node (Interval x) {
        this->i = new Interval (x);
        this->max = i->high;
        this->left = this->right = NULL;
    }
};

// Utility function
Node* insert (Node* root, Interval i) {
    if (root == NULL) {
        Node* temp = new Node(i);
        return temp;
    }
    int l = root->i->low;
    if (i.low < l)
        root->left = insert(root->left, i);
    else
        root->right = insert(root->right, i);

    if (root->max < i.high)
        root->max = i.high;

    return root;
}

// Utility function to check if two intervals overlap
bool doOverlap (Interval i1, Interval i2) {
    if (i1.low < i2.high && i2.low < i1.high)
        return true;
    return false;
}

// Function that searches overlapping interval for Interval 'i'
Interval* overlapSearch (Node* root, Interval i) {
    if (root == NULL)   return NULL;

    if (doOverlap(*(root->i), i))
        return root->i;

    if (root->left != NULL && root->left->max >= i.low)
        return overlapSearch(root->left, i);

    return overlapSearch(root->right, i);
}

// Function that prints all conflicting appointments
// in a given array of appointments
void printConflicting (Interval appt[], int n) {
    Node* root = NULL;
    root = insert (root, appt[0]);
    for (int i = 1; i < n; i++) {
        Interval* res = overlapSearch(root, appt[i]);
        if (res != NULL)
            cout <<  "[" << appt[i].low << "," << appt[i].high
                 << "] Conflicts with [" << res->low << ","
                 << res->high << "]\n";
        root = insert(root, appt[i]);
    }
}

/* ---------------- MAIN DRIVER CODE ----------------- */
int main() {
    Interval appt[] = { {1, 5}, {3, 7}, {2, 6}, {10, 15}, {5, 6}, {4, 100}};
    int n = sizeof(appt)/sizeof(appt[0]);
    cout << "Following are conflicting intervals:\n";
    printConflicting(appt, n);
    return 0;
}