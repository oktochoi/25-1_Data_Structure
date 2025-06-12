#include <iostream>
#include <string>
#include <iomanip>
#include "calculator.h"
using namespace std;

int main() {
    string expression;
    cout << "Enter expression: ";
    getline(cin, expression);

    Calculator calc;
    double result = calc.evaluate(expression);
    cout << fixed << setprecision(2);
    cout << "Result: " << result << endl;

    return 0;
}
