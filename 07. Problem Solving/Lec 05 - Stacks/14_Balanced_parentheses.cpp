// Video Link: https://www.youtube.com/watch?v=QZOLb0xHB_Q

/*  ALGORITHM:
    1. Declare a character stack S.
    2. Now traverse the expression string exp.
        a) If the current character is a starting bracket
            ( ‘(‘ or ‘{‘ or ‘[‘ ) then push it to stack.
        b) If the current character is a closing bracket
            (‘)’ or ‘}’ or ‘]’) then pop from stack and
            if the popped character is the matching starting bracket
            then fine else parenthesis are not balanced.
    3. After complete traversal, if there is some starting bracket
        left in stack then “not balanced”.
*/

#include <bits/stdc++.h>
using namespace std;

// Main Logic
bool areParenthesesBalanced (string expr) {
    stack<char> s;
    char x;

    // Traversing the expression
    for (int i = 0; i < expr.length(); i++) {
        if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{') {
            s.push(expr[i]);
            continue;
        }

        // If current character is not opening bracket,
        // then it must be closing. So stack cannot
        // be empty at this point.
        if (s.empty())
            return false;

        switch(expr[i]) {
            case ')':
                x = s.top();
                s.pop();
                if (x=='{' || x=='[')
                    return false;
                break;

            case ']':
                x = s.top();
                s.pop();
                if (x=='(' || x=='{')
                    return false;
                break;

            case '}':
                x = s.top();
                s.pop();
                if (x=='(' || x=='[')
                    return false;
                break;
        }
    }
    // Finally check if stack is empty
    return s.empty();
}

/* ------------------ MAIN DRIVER CODE -------------------- */
int main() {
    string expression = "{([])}()[()]";

    if (areParenthesesBalanced(expression))
        cout << "Balanced.\n";
    else
        cout << "Not Balanced.\n";

    return 0;
}


/* ADDITIONAL POINT:
    Suppose we are being asked a similar question like above -
    Find the maximum depth of nested and balanced parentheses
    in a given expression (consider here only circular brackets).

    Maximum depth is the maximum number of opening parentheses
    at any point of the string which are not yet closed by
    their matching closing parentheses.

    SOLUTION:
    A simple solution is to use a stack that keeps track of
    current open parentheses.

    1) Create a stack.
    2) Traverse the string, do following for every character
        a) If current character is ‘(’ push it to the stack .
        b) If character is ‘)’, pop an element.
        c) Maintain maximum count during the traversal.

    This can also be done without using stack.

    1) Take two variables max and current_max, initialize both of them as 0.
    2) Traverse the string, do following for every character
        a) If current character is ‘(’, increment current_max and
            update max value if required.
        b) If character is ‘)’. Check if current_max is positive or
            not (this condition ensure that parenthesis are balanced).
            If positive that means we previously had a ‘(’ character
            so decrement current_max without worry.

            If not positive then the parenthesis are not balanced.
            Thus return -1.
    3) If current_max is not 0, then return -1 to ensure that the
        parenthesis are balanced. Else return max.

    Here is the code for non-stack implementation:

int maxDepth(string S)
{
    int current_max = 0;
    int max = 0;
    int n = S.length();

    for (int i = 0; i< n; i++) {
        if (S[i] == '(') {
        current_max++;
            if (current_max> max)
                max = current_max;
        }
        else if (S[i] == ')')
        {
            if (current_max>0)
                current_max--;
            else
                return -1;
        }
    }

    if (current_max != 0)
        return -1;
    return max;
}
*/
