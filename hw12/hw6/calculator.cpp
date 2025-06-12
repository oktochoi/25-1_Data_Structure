#include "calculator.h"
#include <stack>
#include <string>
#include <sstream>
#include <cctype>
#include <iostream>
using namespace std;

int Calculator::precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

double Calculator::apply_op(double a, double b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') return a / b;
    cout << " Unknown operator " << endl;
    return 0;
}

void Calculator::computeTop(stack<double>& values, stack<char>& ops) {
    double b = values.top(); values.pop();
    double a = values.top(); values.pop();
    char op = ops.top(); ops.pop();

    values.push(apply_op(a, b, op));
}


//main function
double Calculator::evaluate(string& expr) {
    stack<double> values;
    stack<char> ops;

    for (size_t i = 0; i < expr.length(); ++i) {
        if (isspace(expr[i])) continue;

        //ifdigit
        if (isdigit(expr[i]) || expr[i] == '.') {
            string numStr;
            while (i < expr.length() && (isdigit(expr[i]) || expr[i] == '.')) {
                numStr += expr[i++];
            }
            values.push(stod(numStr));
            i--;
        }
        //if options
        else if (expr[i] == '(') {
            ops.push(expr[i]);
        }
        else if (expr[i] == ')') {
            while (!ops.empty() && ops.top() != '(') {
                if (values.size() < 2) return 0;
                computeTop(values,ops);
            }
            if (!ops.empty()) ops.pop(); // remove (
        }
        else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/') {
            while (!ops.empty() && precedence(ops.top()) >= precedence(expr[i])) {
                if (values.size() < 2) return 0; //when no values to calculate
                computeTop(values,ops);
            }
            ops.push(expr[i]);
        }
    }

    while (!ops.empty()) {
        if (values.size() < 2) return 0;
        computeTop(values,ops);
    }

    if (values.size() != 1) {
        cout << "Number is left" << endl;
        return 0;
    }

    return values.top();
}
