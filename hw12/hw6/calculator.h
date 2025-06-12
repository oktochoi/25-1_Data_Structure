#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string>
#include <stack>

class Calculator {
public:
    double evaluate(std::string& expr); //main function

private:
    int precedence(char op); //determine the precedence of options
    double apply_op(double a, double b, char op);//calculate a & b
    void computeTop(std::stack<double>& values, std::stack<char>& ops); //get value of top and pop, calculate and push
};

#endif
