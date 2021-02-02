/*  PROBLEM:
    If given a binary tree, you are asked number of
    minimum swaps to convert this BT into a BST.
    BT is given in the form of array i.e. if index i
    is the parent, index 2*i + 1 is the left child
    and index 2*i + 2 is the right child.

    SOLUTION:
    We know the inorder traversal of BST gives a sorted
    array. So we need to find inorder traversal of given
    tree and store the result into an array. The question
    now reduces to - minimum number of swaps required to
    sort this array.

    Time Complexity: O(n*logn)
*/

#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node *left, *right;
    Node(int data) {
        this->data = data;
        this->left = this->right = NULL;
    }
};

// Auxiliary function for inorder traversal
void inorder(int a[], std::vector<int> &v, int n, int index) {
    // if index is greater or equal to vector size
    if(index >= n)  return;

    inorder(a, v, n, 2 * index + 1);
    v.push_back(a[index]);
    inorder(a, v, n, 2 * index + 2);
}

// Main Logic
int minSwaps (vector <int> &v) {
    vector<pair<int, int>> t(v.size());
    int ans = 0;

    for (int i = 0; i < v.size(); i++)
        t[i].first = v[i], t[i].second = i;

    sort(t.begin(), t.end());

    for (int i = 0; i < t.size(); i++) {
        if (i==t[i].second)
            continue;
        else {
            swap(t[i].first, t[t[i].second].first);
            swap(t[i].second, t[t[i].second].second);
        }

        if (i != t[i].second)
            --i;
        ans++;
    }
    return ans;
}

/* ----------------- MAIN DRIVER CODE ---------------- */
int main() {
    int a[] = { 5, 6, 7, 8, 9, 10, 11 };
    int n = sizeof(a) / sizeof(a[0]);
    std::vector<int> v;
    inorder(a, v, n, 0);
    cout << minSwaps(v) << endl;
}