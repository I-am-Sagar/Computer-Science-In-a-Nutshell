/*  ALGORITHM:
    1. While there are input symbols left, read the next symbol from the input.
    2. If the symbol is an operand push it onto the stack.
    3. Else the symbol is an operator. Pop the top 2 values from the stack.
        Put the operator, within the values as arguments and form a string.
        Push the resulted string back to stack.
    4. If there is only one value in the stack that value
        in the stack is the desired infix string.
*/

#include <bits/stdc++.h>
using namespace std;

// Utility function
bool isOperand(char x) {
    return (x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z');
}

// Main Logic
string getInfix(string exp) {
    stack<string> s;

    for (int i=0; exp[i]!='\0'; i++) {
        if (isOperand(exp[i])) {
            string op(1, exp[i]);
            s.push(op);
        }
        else {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            s.push("(" + op2 + exp[i] + op1 + ")");
        }
    }
    return s.top();
}

/* ---------------- MAIN DRIVER CODE -------------- */
int main() {
    string exp = "abcd^e-fgh*+^*+i-";
    cout << getInfix(exp);
    return 0;
}

/*  ADDITIONAL POINT:
    Like in previous code, if we are asked to convert -
    Prefix expression to Infix expression, we will reverse
    the Prefix string and convert it into Postfix string.
    Then using above logic, we will convert Postfix to Infix.
*/
