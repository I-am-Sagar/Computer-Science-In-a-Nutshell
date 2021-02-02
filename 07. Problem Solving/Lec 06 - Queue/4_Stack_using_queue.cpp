/*  A stack can be implemented using two queues - 'q1' and 'q2'.
    1. push(x):
        a) Enqueue x to q2
        b) One by one dequeue everything from q1 and enqueue
            to q2
        c) Swap the names q1 and q2
    2. pop():
        a) Dequeue an item from q1 and return it

    Ofcourse time complexity of push and pop operations is no more
    O(1). The question is just to test whether one can use the
    existing data structure as another in a tricky way.
*/

#include<bits/stdc++.h>
using namespace std;

class Stack {
    queue<int> q1, q2;
    int curr_size;

public:
    Stack() {
        curr_size = 0;
    }

    void push(int x) {
        curr_size++;
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        queue<int> q = q1;
        q1 = q2;
        q2 = q;
    }

    void pop(){
        if (q1.empty())
            return ;
        q1.pop();
        curr_size--;
    }

    int top() {
        if (q1.empty())
            return -1;
        return q1.front();
    }

    int size() {
        return curr_size;
    }
};

/* --------------------- MAIN DRIVER CODE --------------- */
int main() {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);

    cout << "Current size: " << s.size() << endl;
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();

    cout << "Current size: " << s.size() << endl;
    return 0;
}