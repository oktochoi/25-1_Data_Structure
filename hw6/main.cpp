#include <iostream>
#include <string>
#include "calculator.h"
#include <iomanip>
using namespace std;

//Implement a calculator which can calculate 4 operators (+, -, *, /) for real numbers with parenthesis
//Infix 

//main code

int main() {
    string expression;
    cout << "Enter expression: ";
    getline(cin, expression);  

    try {
        Calculator calc;                         
        double result = calc.evaluate(expression);  // Equation Evaluation Function
        cout << fixed << setprecision(2);        
        cout << "Result: " << result << endl;
    } catch (...) {
        cout << "Invalid expression!" << endl;   // error
    }

    return 0;
}
