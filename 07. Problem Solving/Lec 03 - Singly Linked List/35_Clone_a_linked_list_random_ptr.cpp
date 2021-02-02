// Video Link: https://www.youtube.com/watch?v=xbpUHSKoALg

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* random;
    Node (int x) {
        data = x;
        next = random = NULL;
    }
};

void print (Node* start) {
    Node* ptr = start;
    while (ptr) {
        cout << "Data: " << ptr->data << " Random: " << ptr->random->data << endl;
        ptr = ptr->next;
    }
}

// Implementing Hashing Solution
Node* cloneHashed (Node* head) {
    Node* original_current = head;
    Node* cloned_current = NULL;

    //Map contains node to node mapping of original and cloned linked list
    unordered_map <Node*, Node*> m;

    // First cloning the linked list using next pointer and filling Map
    while (original_current != NULL) {
        cloned_current = new Node (original_current->data);
        m[original_current] = cloned_current;
        original_current = original_current->next;
    }

    // We will traverse linked list again to adjust next and random references
    // of cloned link list
    original_current = head;
    while (original_current != NULL) {
        cloned_current = m[original_current];
        cloned_current->next = m[original_current->next];
        cloned_current->random = m[original_current->random];
        original_current = original_current->next;
    }
    return m[head];
}

// Implementing optimized solution without Hash Map
Node* cloneOptimium (Node* head) {
    Node* current = head;
    Node* temp;

    // Inserting additional node after every node of original list
    while (current) {
        temp = current->next;

        current->next = new Node(current->data);
        current->next->next = temp;
        current = temp;
    }

    // Adjust the random pointers of newly added nodes
    current = head;
    while (current) {
        if (current->next)
            current->next->random = current->random ? current->random->next : current->random;

        // move to next newly added node by skipping original node
        current = current->next ? current->next->next : current->next;
    }

    // Now we need to separate the original and cloned list
    Node* original = head;
    Node* copy = head->next;
    temp = copy;

    while (original && copy) {
        original->next = original->next ? original->next->next : original->next;
        copy->next = copy->next ? copy->next->next : copy->next;
        original = original->next;
        copy = copy->next;
    }
    return temp;
}

/* ----------------------- MAIN DRIVER CODE -------------------- */
int main() {
    Node* start = new Node(1);
    start->next = new Node(2);
    start->next->next = new Node(3);
    start->next->next->next = new Node(4);
    start->next->next->next->next = new Node(5);

    // 1's random pointer points to 3
    start->random = start->next->next;
    // 2 points to 1
    start->next->random = start;
    // 3 and 4 points to 5
    start->next->next->random = start->next->next->next->next;
    start->next->next->next->random = start->next->next->next->next;
    //5 points to 2
    start->next->next->next->next->random = start->next;

    cout << "Original List:\n";
    print(start);

    cout << "Cloned List 1:\n";
    Node* clone = cloneHashed (start);
    print (clone);

    cout << "Cloned List 2:\n";
    Node* clone2 = cloneOptimium (start);
    print (clone);

    return 0;
}