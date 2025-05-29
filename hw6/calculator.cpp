#include "calculator.h"
#include <stack>
#include <string>
#include <cctype>
#include <sstream>
#include <iomanip>

using namespace std;

int precedence(char op) { //to Operator Priority Function
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

double apply_op(double a, double b, char op) {
    switch (op) { //use op to return result
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}

double Calculator::evaluate(const string& expr) { //main Equation Evaluation Function  //왜 &가 붙었나
    stack<double> values; //save number
    stack<char> ops; //save operators (+,- etc)

    for (size_t i = 0; i < expr.length(); i++) {
        if (isspace(expr[i])) continue; //ignore space

        if (isdigit(expr[i]) || expr[i] == '.') { //if digits
            //Make consecutive numbers and . into strings and accidentally convert them into stod() → push into stack
            string number;
            while (i < expr.length() && (isdigit(expr[i]) || expr[i] == '.')) {
                number += expr[i++];
            }
            values.push(stod(number));
            i--;
        } else if (expr[i] == '(') { //just push
            ops.push(expr[i]);
        } else if (expr[i] == ')') { //pull top number and op and calculate
            while (!ops.empty() && ops.top() != '(') {
                double b = values.top(); values.pop();
                double a = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(apply_op(a, b, op));
            }
            if (!ops.empty()) ops.pop(); // Remove '('
        } else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/') { //if operators
            // compare operators and if top > new calculate First
            while (!ops.empty() && precedence(ops.top()) >= precedence(expr[i])) {
                double b = values.top(); values.pop();
                double a = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(apply_op(a, b, op));
            }
            ops.push(expr[i]);
        }
    }
    // if there are any remaining operators, you have to calculate them all.
    while (!ops.empty()) {
        double b = values.top(); values.pop();
        double a = values.top(); values.pop();
        char op = ops.top(); ops.pop();
        values.push(apply_op(a, b, op));
    }

    return values.top();
}
