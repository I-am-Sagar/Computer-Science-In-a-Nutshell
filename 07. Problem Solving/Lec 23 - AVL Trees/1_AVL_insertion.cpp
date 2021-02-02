// Video Link: https://www.youtube.com/watch?v=FNeL18KsWPc

/*  Let the newly inserted node be w.
    
    1) Perform standard BST insert for w.
    2) Starting from w, travel up and find the first unbalanced 
       node. Let z be the first unbalanced node, y be the child 
       of z that comes on the path from w to z and x be the 
       grandchild of z that comes on the path from w to z.
    3) Re-balance the tree by performing appropriate rotations 
       on the subtree rooted with z. There can be 4 possible cases 
       that needs to be handled as x, y and z can be arranged in 4 ways. 
       Following are the possible 4 arrangements:
        a) y is left child of z and x is left child of y (Left Left Case)
        b) y is left child of z and x is right child of y (Left Right Case)
        c) y is right child of z and x is right child of y (Right Right Case)
        d) y is right child of z and x is left child of y (Right Left Case)

    Following are the operations to be performed in above mentioned 4 cases. 
    In all of the cases, we only need to re-balance the subtree rooted with 
    z and the complete tree becomes balanced as the height of subtree 
    (After appropriate rotations) rooted with z becomes same as it was before 
    insertion. 
    T1, T2, T3 and T4 are subtrees.

    a) Left Left Case
         z                                      y 
        / \                                   /   \
       y   T4      Right Rotate (z)          x      z
      / \          - - - - - - - - ->      /  \    /  \ 
     x   T3                               T1  T2  T3  T4
    / \
  T1   T2

    b) Left Right Case

     z                               z                           x
    / \                            /   \                        /  \ 
   y   T4  Left Rotate (y)        x    T4  Right Rotate(z)    y      z
  / \      - - - - - - - - ->    /  \      - - - - - - - ->  / \    / \
T1   x                          y    T3                    T1  T2 T3  T4
    / \                        / \
  T2   T3                    T1   T2

    c) Right Right Case

  z                                y
 /  \                            /   \ 
T1   y     Left Rotate(z)       z      x
    /  \   - - - - - - - ->    / \    / \
   T2   x                     T1  T2 T3  T4
       / \
     T3  T4

    d) Right Left Case

   z                            z                            x
  / \                          / \                          /  \ 
T1   y   Right Rotate (y)    T1   x      Left Rotate(z)   z      y
    / \  - - - - - - - - ->     /  \   - - - - - - - ->  / \    / \
   x   T4                      T2   y                  T1  T2  T3  T4
  / \                              /  \
T2   T3                           T3   T4

*/

#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;
    int height;
    Node (int x) {
        this->data = x;
        this->height = 1;
        this->left = this->right = NULL;
    }
};

// Auxiliary function to return height of tree
int height (Node* N) {  
    if (N==NULL)
        return 0;
    return N->height;
}

void preOrder(Node *root) {  
    if(root != NULL) {  
        cout << root->data << " ";  
        preOrder(root->left);  
        preOrder(root->right);  
    }  
}  

// Utility function
Node* rightRotate (Node* y) {
    Node* x =  y->left;
    Node* T2 = x->right;
    // Perform rotation
    x->right = y;
    y->left = T2;
    // Update heights
    y->height = max (height(y->left), height(y->right)) + 1;
    x->height = max (height(x->left), height(x->right)) + 1;
    // return new root
    return x;
}

Node* leftRotate (Node* x) {
    Node* y =  x->right;
    Node* T2 = y->left;
    // Perform rotation
    y->left = x;
    x->right = T2;
    // Update heights
    x->height = max (height(x->left), height(x->right)) + 1;
    y->height = max (height(y->left), height(y->right)) + 1;
    // return new root
    return y;
}

// Function to get balanceFactor of node N
int getBalance (Node* N) {
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

// Main Logic of Insertion
Node* insert (Node* node, int key) {
    // 1. Perform the normal BST insertion
    if (node == NULL) {
        Node* temp = new Node(key);
        return temp;
    }

    if (key < node->data)
        node->left = insert (node->left, key);
    else if (key > node->data)
        node->right = insert (node->right, key);
    else // Equal keys are not allowed in BST
        return node;
    
    // 2. Update height of this ancestor node
    node->height = 1 + max (height(node->left), height(node->right));

    // 3. Get the balance factor of this ancestor node 
    // to check whether this node became unbalanced
    int balance = getBalance(node);

    // If this node becomes unbalanced, then there are 4 cases  

    // Left Left case
    if (balance > 1 && key < node->left->data)  
        return rightRotate(node);  
  
    // Right Right Case  
    if (balance < -1 && key > node->right->data)  
        return leftRotate(node);  
  
    // Left Right Case  
    if (balance > 1 && key > node->left->data) {  
        node->left = leftRotate(node->left);  
        return rightRotate(node);  
    }  
  
    // Right Left Case  
    if (balance < -1 && key < node->right->data) {  
        node->right = rightRotate(node->right);  
        return leftRotate(node);  
    }  
  
    // return the (unchanged) node pointer
    return node;  
}

/* ------------ MAIN DRIVER CODE --------------- */
int main()  
{  
    Node *root = NULL;  
    root = insert(root, 10);  
    root = insert(root, 20);  
    root = insert(root, 30);  
    root = insert(root, 40);  
    root = insert(root, 50);  
    root = insert(root, 25);  

    cout << "Preorder traversal of the constructed AVL tree is: \n";  
    preOrder(root); 
    cout << endl;
      
    return 0;  
}  