#include<bits/stdc++.h>
using namespace std;

// Main Logic
int evaluatePostfix (string expr) {
    stack<int> s;

    // Scan all characters one by one
    for (int i = 0; i < expr.length(); i++) {
        // If the scanned character is digit, push it to stack
        // NOTE: Here we assume all numbers to be less than 10
        if (isdigit(expr[i]))
            s.push(expr[i]-'0');
        // Scanned character is operator
        else {
            int val1 = s.top();
            s.pop();
            int val2 = s.top();
            s.pop();
            switch (expr[i])  {
                case '+': s.push(val2 + val1); break;
                case '-': s.push(val2 - val1); break;
                case '*': s.push(val2 * val1); break;
                case '/': s.push(val2/val1); break;
            }
        }
    }
    return s.top();
}

/* ------------ MAIN DRIVER CODE ------------ */
int main() {
    string expression = "231*+9-";
    cout << "Postfix Evaluation: " << evaluatePostfix(expression) << endl;
    return 0;
}