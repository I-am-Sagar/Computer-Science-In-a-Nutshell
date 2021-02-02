// This is done by - Shunting Yard Algorithm given by E. Dijkstra
// Video Link: https://www.youtube.com/watch?v=Wz85Hiwi5MY

#include <bits/stdc++.h>
using namespace std;

// Utility Functions

// Function to find precedence of operators.
int precedence(char op){
    if(op == '+'||op == '-')
    return 1;
    if(op == '*'||op == '/')
    return 2;
    return 0;
}

// Function to perform arithmetic operations.
int applyOperation(int a, int b, char op){
    switch(op){
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
}

// Main Logic
int evaluate (string expression) {
    stack<int> values;
    stack<char> operators;

    for (int i = 0; i < expression.length(); i++) {
        // If token is a whitespace, skip it
        if (expression[i] == ' ')   continue;
        else if (expression[i] == '(')
            operators.push(expression[i]);
        else if (isdigit(expression[i])) {
            int val = 0;
            // There may be more than 1 digit in number
            while (i < expression.length() && isdigit(expression[i]))
                val = val*10 + (expression[i++] - '0');
            values.push(val);
        }
        // If closing brace is encountered, then solve entire brace
        else if (expression[i] == ')') {
            while (!operators.empty() && operators.top() != '('){
                int val2 = values.top();
                values.pop();

                int val1 = values.top();
                values.pop();

                char op = operators.top();
                operators.pop();

                values.push(applyOperation(val1, val2, op));
            }
            operators.pop();
        }
        // Else current token is an operator
        else {
            // While top of operators has same or greater
            // precedence to current token (viz. an operator),
            // apply operator on top of operators to top
            // two elements in values stack
            while (!operators.empty() && precedence(operators.top()) >= precedence(expression[i])) {
                int val2 = values.top();
                values.pop();
                int val1 = values.top();
                values.pop();
                char op = operators.top();
                operators.pop();
                values.push(applyOperation(val1, val2, op));
            }
            // Now push operator to 'operators'
            operators.push(expression[i]);
        }
    }
    // Entire expression has been parsed at this point,
    // apply remaining operations to remaining values.
    while(!operators.empty()){
        int val2 = values.top();
        values.pop();

        int val1 = values.top();
        values.pop();

        char op = operators.top();
        operators.pop();

        values.push(applyOperation(val1, val2, op));
    }
    return values.top();
}

/* ----------- MAIN DRIVER CODE -------------- */
int main() {
    cout << evaluate("10 + 2 * 6") << "\n";
    cout << evaluate("100 * 2 + 12") << "\n";
    cout << evaluate("100 * ( 2 + 12 )") << "\n";
    cout << evaluate("100 * ( 2 + 12 ) / 14");
    return 0;
}