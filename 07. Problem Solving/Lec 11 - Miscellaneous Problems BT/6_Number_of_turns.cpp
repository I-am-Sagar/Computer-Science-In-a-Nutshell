/*
Given a binary tree and two nodes. The task is to count the number of turns 
needs to reach from one node to another node of the Binary tree.

Input:   Below is the BT and two nodes are 5 & 6 
                   1
                /     \
               2        3
             /   \    /   \
            4     5   6     7
           /         / \
          8         9   10
Output: Number of Turns needed to reach from 5 to 6:  3
        
Input: For above tree if two nodes are 1 & 4
Output: Straight line : 0 turns

APPROACH:

1. Find the LCA of given two node
2. Given node present either on the left side or right side or equal to LCA.
According to above condition over program falls under two Case.

    Case 1:  
    If none of the nodes is equal to LCA, we get these nodes either on
    the left side or right side. We call two functions for each node.
    a)  if (CountTurn(LCA->right, first, false, &Count) || 
            CountTurn(LCA->left, first, true, &Count)) ; 
    b)  Same for second node.
    Here Count is used to store number of turns need to reached the target node.    

    Case 2:  
    If one of the nodes is equal to LCA_Node. Then we count only number of turns 
    needed to reached the second node.
    If LCA == (Either first or second)
    if (countTurn(LCA->right, second/first, false, &Count) || 
        countTurn(LCA->left, second/first, true, &Count)) ;
    
Working of CountTurn Function: 

We pass turn true if we move left subtree and false if we move right subTree.

CountTurn(LCA, Target_node, count, Turn):
    // if found the data value in tree 
    if (root->data == data)
        return true;

    case 1: 
    If Turn is true that means we are 
        in left_subtree  
    If we going left_subtree then there 
        is no need to increment count 
    else
        Increment count and set turn as false  

    case 2:
    if Turn is false that means we are in
        right_subtree    
    if we going right_subtree then there is
        no need to increment count else
    increment count and set turn as true.

    // if data is not found.
    return false;
*/

#include <bits/stdc++.h> 
using namespace std; 

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

struct Node* findLCA(struct Node* root, int n1, int n2) { 
	if (root == NULL) 
		return NULL; 
 
	if (root->data == n1 || root->data == n2) 
		return root; 
    
	Node* left_lca = findLCA(root->left, n1, n2); 
	Node* right_lca = findLCA(root->right, n1, n2); 

	if (left_lca && right_lca) 
		return root; 

	return (left_lca != NULL) ? left_lca : right_lca; 
} 


bool CountTurn(Node* root, int data, bool turn, int* count) { 
	if (root == NULL) 
		return false; 

	// if found the data value in tree 
	if (root->data == data) 
		return true; 

	// Case 1: 
	if (turn == true) { 
		if (CountTurn(root->left, data, turn, count)) 
			return true; 
		if (CountTurn(root->right, data, !turn, count)) { 
			*count += 1; 
			return true; 
		} 
	} // Case 2: 
	else { 
		if (CountTurn(root->right, data, turn, count)) 
			return true; 
		if (CountTurn(root->left, data, !turn, count)) { 
			*count += 1; 
			return true; 
		} 
	} 
	return false; 
} 

// Function to find nodes common to given two nodes 
int NumberOFTurn(struct Node* root, int first, int second) { 
	struct Node* LCA = findLCA(root, first, second); 
	if (LCA == NULL) 
		return -1; 

	int Count = 0; 
	// case 1: 
	if (LCA->data != first && LCA->data != second) { 
		// count number of turns needs to reached the second node from LCA 
		if (CountTurn(LCA->right, second, false, &Count) || \
            CountTurn(LCA->left, second, true, &Count)) ; 
		
		// count number of turns needs to reached the first node from LCA 
		if (CountTurn(LCA->left, first, true, &Count) || 
            CountTurn(LCA->right, first, false, &Count)) ; 
		return Count + 1; 
	} 
	// case 2: 
	if (LCA->data == first) { 
		// count number of turns needs to reached the second node from LCA 
		CountTurn(LCA->right, second, false, &Count); 
		CountTurn(LCA->left, second, true, &Count); 
		return Count; 
	} else { 
		// count number of turns needs to reached the first node from LCA1 
		CountTurn(LCA->right, first, false, &Count); 
		CountTurn(LCA->left, first, true, &Count); 
		return Count; 
	} 
} 

/* ---------------- MAIN DRIVER CODE --------------- */
int main() { 
	Node* root = new Node(1); 
	root->left = new Node(2); 
	root->right = new Node(3); 
	root->left->left = new Node(4); 
	root->left->right = new Node(5); 
	root->right->left = new Node(6); 
	root->right->right = new Node(7); 
	root->left->left->left = new Node(8); 
	root->right->left->left = new Node(9); 
	root->right->left->right = new Node(10); 

	int turn = 0; 
	if ((turn = NumberOFTurn(root, 5, 10))) 
		cout << turn << endl; 
	else
		cout << "Not Possible" << endl; 

	return 0; 
} 
