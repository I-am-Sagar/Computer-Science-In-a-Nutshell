/*  PROBLEM:
    Given a queue of integers of even length, rearrange the
    elements by interleaving the first half of the queue with
    the second half of the queue. Only stack data structure
    is allowed to be used as auxiliary space.

    Input : 11 12 13 14 15 16 17 18 19 20
    Output : 11 16 12 17 13 18 14 19 15 20

    ALGORITHM:
    1. Push the first half elements of queue to stack.
    2. Enqueue back the stack elements.
    3. Dequeue the first half elements of the queue and enqueue them back.
    4. Again push the first half elements into the stack.
    5. Interleave the elements of queue and stack.

    Time and Space complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

// Main Logic
void interleave (queue<int> &q) {
    stack <int> s;
    int halfsize = q.size()/2;

    // Push first half elements onto stack
    for (int i = 0; i < halfsize; i++){
        s.push(q.front());
        q.pop();
    }

    // Enqueue back the stack elements
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    // Dequeue the first half elements of stack
    // and enqueue them back
    for (int i = 0; i < halfsize; i++) {
        q.push(q.front());
        q.pop();
    }

    // Again push the first half elements into the stack
    for (int i = 0; i < halfsize; i++) {
        s.push(q.front());
        q.pop();
    }

    // Interleave the elements of queue and stack
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
    }
}

/* ----------------- MAIN DRIVER CODE ----------------- */
int main() {
    queue <int> q;
    for (int i = 11; i <= 20; i++)
        q.push(i);
    interleave(q);

    // Printing the interleaved queue
    int length = q.size();
    for (int i = 0; i < length; i++) {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}