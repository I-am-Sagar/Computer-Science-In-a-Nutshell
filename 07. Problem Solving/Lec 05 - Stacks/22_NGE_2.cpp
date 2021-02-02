/* In the previous question's output, you can see that the elements
   printed in output are not in same order as that of input.

    So solve the previous question - but the next greater elements
    should be printed in same order as input array.

    SOLUTION:
    Here we traverse array from rightmost element.

    1. In this approach we have started iterating from the last
        element(nth) to the first(1st) element. The benefit is that
        when we arrive at a certain index his next greater element
        will be already in stack and we can directly get this element
        while at the same index.

    2. After reaching a certain index we will pop the stack till we
        get the greater element on top from the current element and
        that element will be the answer for current element.

    3. If stack gets empty while doing the pop operation then the
        answer would be -1. Then we will store the answer in an array
        for the current index.
*/
#include <bits/stdc++.h>
using namespace std;

void printNGE(int arr[], int n) {
    stack<int> s;
    int result[n];

    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && s.top() < arr[i])
            s.pop();
        if (s.empty())
            result[i] = -1;
        else
            result[i] = s.top();

        s.push(arr[i]);
    }

    cout << "Original Array: \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    cout << "NGE: \n";
    for (int i = 0; i < n; i++)
        cout << result[i] << " ";
    cout << endl;
}

/* -------------------- MAIN DRIVER CODE ---------------- */
int main() {
    int arr[] = {11, 13, 21, 3, 8, 7, 9, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    printNGE(arr, n);
    return 0;
}
