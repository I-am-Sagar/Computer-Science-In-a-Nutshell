/* Write a function detectAndRemoveLoop() that checks whether a given Linked List
   contains loop and if loop is present then removes the loop and returns true.

Method 1: Based on 'Tortoise and Hare Technique'

                                                    (Meeting point)
                                          --- (k nodes) --- * ---------
                                        /                               \
    * --------- (m nodes) ----------- *                                  |
 (start)           (beginning of loop)  \                               /
                                          ------ (n nodes in loop) ----
    Explanation:
        Let m = number of nodes before the loop has begun,
            k = number of nodes from beginning point where fast and slow will meet
            n = total length of the loop

        Now,  Distance travelled by fast = 2*Distance travelled by slow
        Hence,  m + n*x + k = 2*(m + n*y + k)   where
            x = number of cycles completed by fast pointer before first meet
            y = number of cycles completed by slow pointer before first meet

        Solving, m + k = (x - 2y)*n

        This shows, (m + k) is multiple of n. So once they meet, if the slow
        starts from head and fast starts from k with SAME PACE now, they will
        meet at the beginning of loop. This is because, 'slow' has covered m steps
        and has reached at the beginning of loop, 'fast' has also covered m steps
        and has already started k steps in advance (covering m+k steps in total).
        Since m+k is multiple of n, 'fast' has to be at the start of loop.

        Now once we are at start of loop, we get the pointer of the last node and
        its next as NULL.

Method 2: Use Hashing
    We can hash the addresses of the linked list nodes in an unordered set and just
    check if the element already exists in the map. If it exists, we have reached a
    node which already exists by a cycle, hence we need to make the last node’s next
    pointer NULL.
 */

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* newNode (int data) {
    Node* temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void printList(Node *head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Main Logic Part
void detectAndRemoveLoop (Node* head) {
    // If the list is empty or has one node, it has no loop
    if (head == NULL || head->next == NULL)
        return;

    Node* slow = head;
    Node* fast = head;

    slow = slow->next;
    fast = fast->next->next;

    while (fast && fast->next) {
        if (slow==fast)
            break;
        slow = slow->next;
        fast = fast->next->next;
    }

    if (slow == fast) { // If loop exists
        slow = head;
        while (slow->next != fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        // Now slow and fast are pointing towards the beginning of loop.
        // This means fast must be the ending node of the loop.
        fast->next = NULL;
    }
}

/* -------------- MAIN DRIVER CODE ---------------- */
int main() {
    Node *head = newNode(50);
    head->next = newNode(20);
    head->next->next = newNode(15);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(10);

    // Create a loop for testing
    head->next->next->next->next->next = head->next->next;

    detectAndRemoveLoop(head);

    printf("Linked List after removing loop \n");
    printList(head);
    return 0;
}

/* Code for Hashing solution:
    void hashAndRemove(Node *head) {
        unordered_set<Node*> s;
        Node* last = NULL;          	//pointer to last node

        while(head!=NULL) {
            if(s.find(head) == s.end()) {   //if node not present in the map, insert it in the map
                s.insert(head);
                last = head;
                head = head->next;
            }
            else {      //if present, it is a cycle, make the last node's next pointer NULL
                last->next = NULL;
                break;
            }
        }
    }
*/