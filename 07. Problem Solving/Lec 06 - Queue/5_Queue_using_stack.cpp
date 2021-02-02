/*  This is done by using two stacks.
    Following implementation makes sure that oldest entered element
    is always at the top of stack 1, so that deQueue operation just
    pops from stack1. To put the element at top of stack1, stack2 is
    used.

    enQueue(q, x):
    a) While stack1 is not empty, push everything from stack1 to stack2.
    b) Push x to stack1 (assuming size of stacks is unlimited).
    c) Push everything back to stack1.
    Here time complexity will be O(n)

    deQueue(q):
    a) If stack1 is empty then error
    b) Pop an item from stack1 and return it
    Here time complexity will be O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Queue {
    stack <int> s1, s2;

public:
    void enqueue (int x);
    void dequeue ();
    int front();
};

void Queue :: enqueue(int x) {
    while (!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
    }
    s1.push(x);
    while (!s2.empty()) {
        s1.push(s2.top());
        s2.pop();
    }
}

void Queue::dequeue() {
    if (s1.empty()) {
        cout << "Queue is empty.\n";
        return;
    }
    s1.pop();
}

int Queue::front() {
    return s1.top();
}

/* -------------- MAIN DRIVER CODE ----------- */
int main() {
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout << q.front() << endl;
    q.dequeue();
    q.dequeue();
    cout << q.front() << endl;

    return 0;
}