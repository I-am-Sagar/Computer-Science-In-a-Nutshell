/*  PROBLEM:
    Given a binary tree, print it vertically.

    For example, for the given binary tree:
          1
        /   \
       2      3
      / \    / \
     4   5  6   7
               / \
              8   9

    OUTPUT:
        4
        2
        1 5 6
        3 8
        7
        9

    APPROACH:
     We need to check the Horizontal Distances from root for all nodes.
     If two nodes have the same Horizontal Distance (HD), then they are
     on same vertical line. The idea of HD is simple. HD for root is 0,
     a right edge (edge connecting to right subtree) is considered as +1
     horizontal distance and a left edge is considered as -1 horizontal distance.

     For example, in the above tree, HD for Node 4 is at -2, HD for Node 2 is -1,
     HD for 5 and 6 is 0 and HD for node 7 is +2.

     We can do preorder traversal of the given Binary Tree. While traversing the tree,
     we can recursively calculate HDs. We initially pass the horizontal distance as 0
     for root. For left subtree, we pass the Horizontal Distance as Horizontal distance
     of root minus 1. For right subtree, we pass the Horizontal Distance as Horizontal
     Distance of root plus 1. For every HD value, we maintain a list of nodes in a hash
     map. Whenever we see a node in traversal, we go to the hash map entry and add the
     node to the hash map using HD as a key in map. (Look at the code of preorder
     vertical traversal in ADDITIONAL POINT section).

     However there is a problem with preorder usage in vertical traversal: Nodes in the
     vertical line may not be printed in same order as they appear. For example,
     preorder traversal prints 12 before 9 in below tree.

             1
          /     \
         2       3
        /  \    /  \
       4    5  6     7
                \   /  \
                 8  10   9
                     \
                      11
                       \
                        12

     If we use level order traversal, we can make sure that if a node like 12
     comes below in same vertical line, it is printed after a node like 9 which
     comes above in vertical line.

     Time Complexity of hashing based solution can be considered as O(n) under the
     assumption that we have good hashing function that allows insertion and retrieval
     operations in O(1) time. In the given C++ implementation, map of STL is used.
     map in STL is typically implemented using a Self-Balancing Binary Search Tree
     where all operations take O(Logn) time.

     Therefore time complexity of above implementation is O(nLogn).
*/

#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* left, *right;
        Node (int data) {
            this->data = data;
            this->left = this->right = NULL;
        }
};

// Main Logic of Vertical Traversal
void verticalOrder(Node* root) {
    if (root == NULL)   return;

    map<int, vector<int>> m;
    int hd = 0;
    queue<pair<Node*, int>> q;
    q.push(make_pair(root, hd));
    while (!q.empty()) {
        pair <Node*, int> temp = q.front();
        q.pop();
        hd = temp.second;
        Node* node = temp.first;

        // Insert this node's data in vector of hashmap
        m[hd].push_back(node->data);

        if (node->left) q.push(make_pair(node->left, hd-1));
        if (node->right) q.push(make_pair(node->right, hd+1));
    }

    // Traverse the map and print nodes at every hd
    map< int,vector<int> > :: iterator it;
    for (it=m.begin(); it!=m.end(); it++) {
        for (int i=0; i<it->second.size(); ++i)
            cout << it->second[i] << " ";
        cout << endl;
    }
}

/* ----------------- MAIN DRIVER CODE ----------------- */
int main() {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->right = new Node(8);
    root->right->right->right = new Node(9);
    cout << "Vertical order traversal:\n";
    verticalOrder(root);
    return 0;
}

/*  ADDITIONAL POINT:

    Code of preorder traversal usage for Vertical Traversal:

    // Utility function to store vertical order in map 'm'
    // 'hd' is horizontal distance of current node from root
    void getVerticalOrder (Node* root, int hd, map<int, vector<int>> &m) {
        if (root == NULL)   return;
        m[hd].push_back(root->data);
        getVerticalOrder (root->left, hd-1, m);
        getVerticalOrder (root->right, hd+1, m);
    }

    // Main logic to print vertical order
    void verticalOrder (Node* root) {
        map <int, vector<int>> m;
        int hd = 0;
        getVerticalOrder(root, hd, m);

        // Traverse the map and print nodes at every horizontal distance
        map< int,vector<int> > :: iterator itr;
        for (itr=m.begin(); itr!=m.end(); itr++) {
            for (int i=0; i<itr->second.size(); ++i)
                cout << itr->second[i] << " ";
            cout << endl;
        }
    }
*/