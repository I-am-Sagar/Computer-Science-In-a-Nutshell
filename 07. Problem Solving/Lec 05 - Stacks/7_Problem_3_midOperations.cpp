/* PROBLEM:
    How to implement a stack which will support following operations in O(1) time complexity?
        1) push() which adds an element to the top of stack.
        2) pop() which removes an element from top of stack.
        3) findMiddle() which will return middle element of the stack.
        4) deleteMiddle() which will delete the middle element.

    SOLUTION:
    The important question is, whether to use linked list or array implementation of stack?
    We need to find and delete middle element. Deleting an element from middle is not O(1)
    for array. Also, we may need to move the middle pointer up when we push an element and
    move down when we pop(). In singly linked list, moving middle pointer in both directions
    is not possible.

    The idea is to use Doubly Linked List (DLL). We can delete middle element in O(1) time
    by maintaining mid pointer. We can move mid pointer in both directions using previous
    and next pointers.
*/

#include <bits/stdc++.h>
using namespace std;

class DLLNode {
    public:
        DLLNode *prev;
        int data;
        DLLNode *next;
        DLLNode(int new_data) {
            data = new_data;
            prev = next = NULL;
        }
};

// Stack is implemented using DLL. It maintains pointer to head
// and middle nodes and count of nodes.
class myStack {
    public:
        DLLNode *head;
        DLLNode *mid;
        int count;

        myStack() {
            head = NULL;
            mid = NULL;
            count = 0;
        }

        void push (int item);
        int pop ();
        int findMiddle ();
        void deleteMiddle ();
};

void myStack :: push(int item) {
    // Allocate DLL node to be pushed in stack
    DLLNode* new_node = new DLLNode(item);
    // Since we are adding node in the beginning
    // previous will always be NULL. We just need
    // to link the old list to this new node
    new_node->next = head;
    count++;

    // We need to change the middle pointer only
    // when - a) Linked List becomes empty
    // b) Number of linked list is odd
    if (count == 1) {
        mid = new_node;
    }
    else {
        head->prev = new_node;
        // Update if count is even
        if (count%2 == 0)
            mid = mid->prev;
    }

    head = new_node;
}

int myStack :: pop() {
    if (count == 0) {
        cout << "Stack Underflow.\n";
        return -1;
    }
    DLLNode* start = head;
    int item = head->data;
    head = head->next;

    // If linked list is not yet empty,
    // update prev of new head as NULL
    if (head != NULL)
        head->prev = NULL;
    count--;

    // Update the mid pointer when we have
    // odd number of items in the stack
    if (count%2 == 1)
        mid = mid->next;

    delete start;
    return item;
}

int myStack :: findMiddle() {
    if (count == 0) {
        cout << "Stack Underflow.\n";
        return -1;
    }
    return mid->data;
}

void myStack :: deleteMiddle() {
    // We have pointer to the middle element. We know how
    // to delete a node in LL with just a pointer of that node.
    // Copy the data of next node and delete the next node.
    DLLNode* temp = mid->next;
    mid->data = temp->data;
    mid->next = temp->next;
    temp = temp->next;
    temp->prev = mid;
    delete temp;
}

/* --------------------- MAIN DRIVER CODE -------------------- */
int main() {
    myStack s;
    for (int i = 1; i < 5; i++)
        s.push(2*i);

    cout << s.findMiddle() << endl;
    s.pop();
    s.pop();
    cout << s.findMiddle() << endl;

    for (int i = 5; i < 8; i++)
        s.push(2*i+1);

    cout << s.findMiddle() << endl;
    s.deleteMiddle();
    cout << s.findMiddle() << endl;

    return 0;
}