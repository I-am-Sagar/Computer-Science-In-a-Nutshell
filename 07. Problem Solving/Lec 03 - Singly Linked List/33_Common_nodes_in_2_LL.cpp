/*  PROBLEM: Given two linked list, the task is to find the number of common nodes
    in both singly linked list.

    Naive Approach:
    Compare every node of list A with every node of list B. If the node is a match
    then increment the count and return count after all the nodes get compared.

    Efficient Approach:
    Insert all the nodes of linked list A in the unordered_set and then check for
    each node of linked list B in unordered_set. If found increment the count and
    return the count at the end.
*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node (int x) {
        data = x;
        next = NULL;
    }
};

void push(Node** head_ref, int new_data) {
    struct Node* new_node = new Node(new_data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Main Logic
int countCommonNodes (Node* head1, Node* head2) {
    Node* current1 = head1;
    Node* current2 = head2;
    int count = 0;

    unordered_set<int> s;
    while(current1 != NULL) {
        s.insert(current1->data);
        current1 = current1->next;
    }

    while(current2 != NULL){
        if(s.find(current2->data) != s.end())
            count++;
        current2 = current2->next;
    }
    return count;
}

/* ------------------------ MAIN DRIVER CODE --------------------- */
int main() {
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;

    // List A = 3 -> 4 -> 12 -> 10 -> 17
    push(&head1, 17);
    push(&head1, 10);
    push(&head1, 12);
    push(&head1, 4);
    push(&head1, 3);

    // List B = 10 -> 4 -> 8 -> 57 -> 34 -> 12
    push(&head2, 12);
    push(&head2, 34);
    push(&head2, 57);
    push(&head2, 8);
    push(&head2, 4);
    push(&head2, 10);

    int count = countCommonNodes(head1, head2);

    cout << "Number of common node in both list is = " << count << endl;

    return 0;
}