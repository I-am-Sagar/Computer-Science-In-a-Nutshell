// Video Link: https://www.youtube.com/watch?v=0bpDvc2VjPU

/*
    PROBLEM: Design a Data Structure SpecialStack that supports all the
    stack operations like push(), pop(), isEmpty(), isFull() and an
    additional operation getMin() which should return minimum element
    from the SpecialStack. All these operations of SpecialStack must be O(1).
    To implement SpecialStack, you should only use standard Stack data structure
    and no other data structure like arrays, list, .. etc.

    SOLUTION:
    Use two stacks: one to store actual stack elements and other as an auxiliary
    stack to store minimum values. The idea is to do push() and pop() operations
    in such a way that the top of auxiliary stack is always the minimum.

    Let us see how push() and pop() operations work.

    Push(int x)
    1) Push x to the first stack (the stack with actual elements)
    2) Compare x with the top element of the second stack (the auxiliary stack).
        Let the top element be y.
        a) If x is smaller than y then push x to the auxiliary stack.
        b) If x is greater than y then push y to the auxiliary stack.

    int Pop()
    1) pop the top element from the auxiliary stack.
    2) pop the top element from the actual stack and return it.

    The step 1 is necessary to make sure that the auxiliary stack is also updated
    for future operations.

    int getMin()
    1) Return the top element of auxiliary stack.
*/

#include <bits/stdc++.h>
using namespace std;

// This is simple stack with basic functionalities
class Stack {
    private:
        static const int max = 100;
        int arr[max];
        int top;
    public:
        Stack() { top = -1; }
        bool isEmpty();
        bool isFull();
        int pop();
        void push(int x);
};

bool Stack::isEmpty() {
    return  (top == -1);
}

bool Stack::isFull() {
    return (top == max-1);
}

int Stack::pop() {
    if(isEmpty()) {
        cout<<"Stack Underflow.\n";
        abort();
    }
    int x = arr[top];
    top--;
    return x;
}

void Stack::push(int x) {
    if(isFull()) {
        cout<<"Stack Overflow.\n";
        abort();
    }
    top++;
    arr[top] = x;
}

// Our Special Stack class
class SpecialStack: public Stack // Inherits all properties of stack
{
    Stack min;
public:
    int pop();
    void push(int x);
    int getMin();
};

// SpecialStack's push() method makes sure that the min stack
// is also updated with appropriate minimum values
void SpecialStack::push(int x) {
    if(isEmpty()==true) {
        Stack::push(x);
        min.push(x);
    }
    else {
        Stack::push(x);
        int y = min.pop();
        min.push(y);

        if( x < y )
            min.push(x);
        else
            min.push(y);
    }
}

// SpecialStack's pop() method removes top element from min stack also.
int SpecialStack::pop() {
    int x = Stack::pop();
    min.pop();
    return x;
}

// SpecialStack's method to find minimum element
int SpecialStack::getMin() {
    int x = min.pop();
    min.push(x);
    return x;
}

/* ----------------------- MAIN DRIVER CODE -------------------- */
int main() {
    SpecialStack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.getMin() <<endl;
    s.push(5);
    cout << s.getMin() << endl;
    return 0;
}