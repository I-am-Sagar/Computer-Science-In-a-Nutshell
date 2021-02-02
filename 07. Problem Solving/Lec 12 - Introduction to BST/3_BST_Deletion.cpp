/*  When we delete a node, three possibilities arise:

    1. Node to be deleted is leaf:
       In that case simply remove it from the tree.

              50                            50
            /    \         delete(20)      /   \
          30      70       --------->    30     70
         /  \    /  \                     \    /  \
       20   40  60   80                   40  60   80

    2. Node to be deleted has only one child:
       Copy the child to the node and delete the child.

              50                            50
            /    \         delete(30)      /  \
          30      70       --------->    40    70
            \    /  \                         /  \
            40  60   80                      60   80

    3. Node to be deleted has two children:
       Find inorder successor of the node. Copy contents
       of the inorder successor to the node and delete the
       inorder successor. Note that inorder predecessor
       can also be used.

             50                            60
           /    \         delete(50)      /   \
          40     70       --------->    40    70
                /  \                            \
               60   80                           80
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

// Auxiliary Functions
Node* insert (Node* root, int key) {
    if (root == NULL) {
        Node* temp = new Node(key);
        return temp;
    }
    if (key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);

    return root;
}

void inorder (Node* root) {
    if (root == NULL)	return;
    inorder (root->left);
    cout << root->data << " ";
    inorder (root->right);
}

// Utility function that finds minimum value in BST
Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

// Main Logic
Node* deleteNode (Node* root, int key) {
    if (root == NULL)	return root;

    if (root->data > key)
        root->left = deleteNode(root->left, key);
    else if (root->data < key)
        root->right = deleteNode(root->right, key);
    else {
        // node with only one child or no child
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Node with two children
        // Get inorder successor
        Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

/* ------------------- MAIN DRIVER CODE ----------------- */
int main() {
    Node *root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Inorder traversal of the given tree: \n");
    inorder(root);

    printf("\nDelete 20.\n");
    root = deleteNode(root, 20);
    printf("Inorder traversal of the modified tree: \n");
    inorder(root);

    printf("\nDelete 30.\n");
    root = deleteNode(root, 30);
    printf("Inorder traversal of the modified tree: \n");
    inorder(root);

    printf("\nDelete 50\n");
    root = deleteNode(root, 50);
    printf("Inorder traversal of the modified tree: \n");
    inorder(root);

    return 0;
}

/*	ADDITIONAL POINT:

    In the above recursive code, we recursively call delete() for successor.
    We can avoid recursive call by keeping track of parent node of successor
    so that we can simply remove the successor by making child of parent as
    NULL. We know that successor would always be a leaf node.

    Node* deleteNode(Node* root, int k) {
        if (root == NULL)	return root;

        // Recursive calls for ancestors of node to be deleted
        if (root->key > k) {
            root->left = deleteNode(root->left, k);
            return root;
        }
        else if (root->key < k) {
            root->right = deleteNode(root->right, k);
            return root;
        }

        // We reach here when root is the node to be deleted.
        // If one of the children is empty
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // If both children exist
        else {

            Node* succParent = root->right;

            // Find successor
            Node *succ = root->right;
            while (succ->left != NULL) {
                succParent = succ;
                succ = succ->left;
            }

            // Delete successor.  Since successor is always left child
            // of its parent we can safely make successor's right
            // right child as left of its parent.
            succParent->left = succ->right;

            // Copy Successor Data to root
            root->key = succ->key;

            // Delete Successor and return root
            delete succ;
            return root;
        }
    }
*/