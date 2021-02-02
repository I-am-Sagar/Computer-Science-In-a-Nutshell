// Video Link 1: https://www.youtube.com/watch?v=jos1Flt21is
// Video Link 2: https://www.youtube.com/watch?v=MeRb_1bddWg
// Video Link 3: https://www.youtube.com/watch?v=vq-nUF0G4fI

/*  ALGORITHM:
    1. Scan the infix expression from left to right.
    2. If the scanned character is an operand, output it.
    3. Else,
        a) If the precedence of the scanned operator is greater
            than the precedence of the operator in the stack
            (or the stack is empty or the stack contains a ‘(‘ ),
            push it.
        b) Else, Pop all the operators from the stack which are
            greater than or equal to in precedence than that of
            the scanned operator. After doing that Push the
            scanned operator to the stack.
            (If you encounter parenthesis while popping then stop
            there and push the scanned operator in the stack.)
    4. If the scanned character is an ‘(‘, push it to the stack.
    5. If the scanned character is an ‘)’, pop the stack and and output
        it until a ‘(‘ is encountered, and discard both the parenthesis.
    6. Repeat    2-6 until infix expression is scanned.
    7. Print the output
    8. Pop and output from the stack until it is not empty.
*/

#include<bits/stdc++.h>
using namespace std;

// Utility function that returns the precedence value of operators
int precedence (char c) {
    if(c == '^')
        return 3;
    else if(c == '*' || c == '/')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else
        return -1;
}

// Main Logic
void infixToPostfix(string s) {
    stack<char> st;
    st.push('N');
    int l = s.length();
    string ns;
    for(int i = 0; i < l; i++) {
        // If the scanned character is an operand, add it to output string.
        if((s[i] >= 'a' && s[i] <= 'z')||(s[i] >= 'A' && s[i] <= 'Z'))
            ns+=s[i];
        // If the scanned character is an ‘(‘, push it to the stack.
        else if(s[i] == '(')
            st.push('(');
        // If the scanned character is an ‘)’, pop and to output string
        // from the stack until an ‘(‘ is encountered.
        else if(s[i] == ')') {
            while(st.top() != 'N' && st.top() != '(') {
                char c = st.top();
                st.pop();
                ns += c;
            }
            if(st.top() == '(') {
                char c = st.top();
                st.pop();
            }
        }
        //If an operator is scanned
        else {
            while(st.top() != 'N' && precedence(s[i]) <= precedence(st.top())) {
                char c = st.top();
                st.pop();
                ns += c;
            }
            st.push(s[i]);
        }

    }
    //Pop all the remaining elements from the stack
    while(st.top() != 'N') {
        char c = st.top();
        st.pop();
        ns += c;
    }

    cout << ns << endl;
}

/* ------------------ MAIN DRIVER CODE --------------- */
int main() {
    string exp = "a+b*(c^d-e)^(f+g*h)-i";
    infixToPostfix(exp);
    return 0;
}

/*  ADDITIONAL POINT:
    In above code, we have converted Infix to Postfix.
    Now, to convert Infix to Prefix, do the following:

    1. Reverse the infix expression i.e A+B*C will become C*B+A.
       Note while reversing each ‘(‘ will become ‘)’ and each ‘)’ becomes ‘(‘.
    2. Obtain the postfix expression of the modified expression i.e CB*A+.
    3. Reverse the postfix expression. Hence in our example prefix is +A*BC.
*/