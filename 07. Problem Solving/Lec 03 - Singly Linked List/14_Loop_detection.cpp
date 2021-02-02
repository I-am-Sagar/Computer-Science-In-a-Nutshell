/* Given a linked list, we need to check if it has a loop or not.
    Eg. following list has loop:
    1 -> 2 -> 3
         |    |
         5 <- 4

    We will solve this problem by using "Flyod's Cycle Finding Algorithm."
    This is the fastest method of loop detection and uses two pointer method.

    Maintain two pointers 'slow' and 'fast'. Make 'slow' pointer jump by 1 node
    and 'fast' pointer jump by 2 nodes. If these pointers meet at same node at
    any instance, there is a loop. Else list doesn't have the loop.
*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void push(Node** head_ref, int new_data) {
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

bool detectLoop (Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
}

/* -------------- MAIN DRIVER CODE ---------------- */
int main() {
    Node* head = NULL;
    // List is 10-15-4-20-Null;
    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 10);

    // Creating a loop. Pointer of 20 (viz. NULL) now points to 15.
    head->next->next->next->next = head->next;
    if (detectLoop(head))
        cout << "Loop Found\n";
    else
        cout << "Loop Not Found\n";

    return 0;
}

/*
You can use HASHING. It is also O(n) like Flyod's Cycle Finding Algo.
But the hidden constant is bigger as compared to Flyod's algo.
This means, if T(n) = c1*n + c2 for Hashing and T(n) = c3*n + c4 for Flyod's,
then    c1 > c3.    So Flyod's algo will be slightly faster than Hashing.

Method: Use Hashing
    Traverse the list one by one and keep putting the node addresses in a Hash Table.
    At any point, if NULL is reached then return false and if next of current node points
    to any of the previously stored nodes in Hash then return true.

bool detectLoop (Node* h) {
    unordered_set <Node*> s;    //unordered_set is faster than set and here order of nodes won't matter
    while (h != NULL) {
        if (s.find(h) != s.end())
            return true;
        s.insert(h);
        h=h->next;
    }
    return false;
}
*/