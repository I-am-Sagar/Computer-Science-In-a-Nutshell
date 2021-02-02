/*  PROBLEM:
    There are two singly linked lists in a system. By some programming error,
    the end node of one of the linked list got linked to the second list,
    forming an inverted Y shaped list. Write a program to get the point
    where two linked list merge.

    Approach 1 - Using Two Loops
    Use 2 nested for loops. The outer loop will be for each node of the 1st list
    and inner loop will be for 2nd list. In the inner loop, check if any of nodes
    of the 2nd list is same as the current node of the first linked list.
    Time complexity: O(M * N) where M and N are the numbers of nodes in two lists.
    Space complexity: O(1)

    Approach 2 - Use difference of node counts
    1. Get the count of nodes in the first list. Let it be c1.
    2. Get the count of nodes in the second list. Let it be c2.
    3. Get difference d = abs(c1-c2)
    4. Traverse d nodes in the bigger list.
    5. Then we can traverse both the lists in parallel till we come across a common node.
       (Note that getting a common node is done by comparing the address of the nodes.)
    Time complexity: O(M+N) and Space Complexity: O(1)

    We have implemented approach 2 in the following code.
*/

#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
        Node(int data) {
            this->data = data;
            this->next = NULL;
        }
};

// Auxiliary Functions
void push (Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

// Utility functions for our main logic
int getCount (Node* head) {
    Node* current = head;
    int count = 0;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

int getIntersectionNode (Node* head1, Node* head2) {
    // Count the number of nodes in both the linked list
    int c1 = getCount(head1);
    int c2 = getCount(head2);
    int d = c1>c2 ? (c1-c2) : (c2-c1);

    Node* current1 = head1;
    Node* current2 = head2;

    int count = 0;
    if (c1 > c2) {
        while (count < d){
            current1 = current1->next;
            count++;
        }
    } else {
        while (count < d) {
            current2 = current2->next;
            count++;
        }
    }

    while (current1!=NULL && current2 != NULL) {
        if (current1 == current2)
            return current1->data;
        current1 = current1->next;
        current2 = current2->next;
    }

    return -1;
}

/* ------------------- MAIN DRIVER CODE ----------------- */

// Driver Code
int main() {
    /*  Create two linked lists
        1st 10->15->30
        2nd 3->6->9->15->30

        15 is the intersection point  */
    Node* newNode;

    // Addition of new nodes
    Node* head1 = new Node(10);
    Node* head2 = new Node(3);

    head2->next = new Node(6);
    head2->next->next = new Node(9);

    newNode = new Node(15);
    head1->next = newNode;
    head2->next->next->next = newNode;

    newNode = new Node(30);
    head1->next->next = newNode;
    head2->next->next->next->next = newNode;

    head1->next->next->next = NULL;
    head2->next->next->next->next->next = NULL;

    cout << "The node of intersection is "
         << getIntersectionNode (head1, head2) << ".\n";
    return 0;
}