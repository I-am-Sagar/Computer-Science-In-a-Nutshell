// Video Link: https://www.youtube.com/watch?v=DxW7VAsdX0o

/*  Problem Description:

    Create a data structure twoStacks that represent two stacks
    and both the stacks should use same array for storing elements.

    push1 (int x)   ->  pushes x to first stack
    push2 (int x)   ->  pushes x to second stack
    pop1()          ->  pops an element from stack 1
    pop2()          ->  pops an element from stack 2

    Method 1 :

    A simple way to implement two stacks is to divide the array in
    two halves and use arr[0] to arr[n/2] for stack1, and arr[(n/2) + 1]
    to arr[n-1] for stack2. The problem with this method is inefficient
    use of array space. For example, say the array size is 6 and we push
    3 elements to stack1 and do not push anything to second stack2.
    When we push 4th element to stack1, there will be overflow even if
    we have space for 3 more elements in array.

    Method 2:

    This method efficiently utilizes the available space. The idea is
    to start two stacks from two extreme corners of arr[].
    stack1 starts from the leftmost element, the first element in
    stack1 is pushed at index 0. The stack2 starts from the rightmost
    corner, the first element in stack2 is pushed at index (n-1).
    Both stacks grow (or shrink) in opposite direction.
    To check for overflow, all we need to check is for space between
    top elements of both stacks. This is implemented in following code.
 */

#include <iostream>
#include <stdlib.h>
using namespace std;

class twoStacks {
    private:
        int *arr;
        int size;
        int top1, top2;
    public:
        twoStacks(int n) {
            size = n;
            arr = new int[n];
            top1 = -1;
            top2 = size;
        }

        void push1 (int x);
        void push2 (int x);
        int pop1 ();
        int pop2 ();
};

void twoStacks :: push1 (int x) {
    // There is atleast one empty space for new element
    if (top1 < top2 - 1) {
        top1++;
        arr[top1] = x;
    }
    else {
        cout << "Stack Overflow\n";
        exit(1);
    }
}

void twoStacks :: push2 (int x) {
    // There is atleast one empty space for new element
    if (top1 < top2 - 1) {
        top2--;
        arr[top2] = x;
    }
    else {
        cout << "Stack Overflow\n";
        exit (1);
    }
}

int twoStacks :: pop1 () {
    if (top1 >= 0) {
        int x = arr[top1];
        top1--;
        return x;
    }
    else {
        cout << "Stack Underflow\n";
        exit (1);
    }
}

int twoStacks :: pop2 () {
    if (top2 < size) {
        int x = arr[top2];
        top2++;
        return x;
    }
    else {
        cout << "Stack Underflow\n";
        exit (1);
    }
}

/* -------------- Main Code -------------- */

int main() {
    twoStacks ts(5);
    ts.push1(5);
    ts.push2(10);
    ts.push2(15);
    ts.push1(11);
    ts.push2(7);
    cout << "Popped element from stack1 is " << ts.pop1();
    ts.push2(40);
    cout << "\nPopped element from stack2 is " << ts.pop2();
    return 0;
}