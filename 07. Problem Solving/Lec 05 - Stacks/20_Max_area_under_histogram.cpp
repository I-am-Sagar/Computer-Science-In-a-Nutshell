/* PROBLEM:
    Find the largest rectangular area possible in a given histogram where
    the largest rectangle can be made of a number of contiguous bars.

    SOLUTION:
    1. Create an empty stack.
    2. Start from first bar, and do following for every bar
        ‘hist[i]’ where ‘i’ varies from 0 to n-1.
        a) If stack is empty or hist[i] is higher than the bar at top of stack,
            then push ‘i’ to stack.
        b) If this bar is smaller than the top of stack, then keep removing the
            top of stack while top of the stack is greater.
            Let the removed bar be hist[tp].
            Calculate area of rectangle with hist[tp] as smallest bar.
            For hist[tp], the ‘left index’ is previous (previous to tp) item in
            stack and ‘right index’ is ‘i’ (current index).
    3. If the stack is not empty, then one by one remove all bars from stack and
        do step 2.b for every removed bar.

    Since every bar is pushed and popped only once, the time complexity is O(n).
*/

#include <bits/stdc++.h>
using namespace std;

int getMaxArea (int hist[], int n) {
    // Stack holds indexes of hist[] array. The bars stored in
    // stack are always in increasing order of their heights
    stack<int> s;
    int max_area = 0;   // Initialize max area
    int top;            // To store top of the stack
    int area_with_top = 0;  // To store area with top bar as smallest bar

    int i = 0;
    while (i < n) {
        // If this bar is higher than the bar on top, push it in stack
        if (s.empty() || hist[s.top()] <= hist[i])
            s.push(i++);
        // If the bar is lower than top of stack, then calculate area
        // of rectangle with stack top as bar with minimum height
        else {
            top = s.top();
            s.pop();

            area_with_top = hist[top]*(s.empty() ? i : (i-s.top()-1));

            if (max_area < area_with_top)
                max_area = area_with_top;
        }
    }

    // Now pop the remaining bars from stack and calculate
    // area with every popped bar as the smallest bar
    while(!s.empty()) {
        top = s.top();
        s.pop();

        area_with_top = hist[top]*(s.empty() ? i : (i-s.top()-1));

        if (max_area < area_with_top)
            max_area = area_with_top;
    }
    return max_area;
}

/* ---------------------- MAIN DRIVER CODE ----------------------- */
int main() {
    int hist[] = {6, 2, 5, 4, 5, 1, 6};
    int n = sizeof(hist)/sizeof(hist[0]);
    cout << "Maximum area is " << getMaxArea(hist, n) << ".\n";
    return 0;
}