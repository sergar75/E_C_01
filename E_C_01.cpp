#include <iostream>
#include <Windows.h>
#include <ctype.h> 

using namespace std;




int evaluateExpression_in(const char* expression_in, int& pos) {
        
    char operator_in = '\0';
    int operand1_in = 0;
    int operand2_in = 0;
    int temp = 0;

    pos++;

    while (isdigit(expression_in[pos])) {
        operand1_in = operand1_in * 10 + (expression_in[pos] - '0');
        cout << operand1_in << endl;
        pos++;
    }
    
    if (expression_in[pos] == '+' || expression_in[pos] == '-'
        || expression_in[pos] == '*' || expression_in[pos] == '/') {
        operator_in = expression_in[pos];
        pos++;
    }
        
    while (isdigit(expression_in[pos])) {
        operand2_in = operand2_in * 10 + (expression_in[pos] - '0');
        cout << operand2_in << endl;
        pos++;
    }

    if (operator_in == '+') {
        temp = operand1_in + operand2_in;
    }
    else if (operator_in == '-') {
        temp = operand1_in - operand2_in;
    }
    else if (operator_in == '*') {
        temp = operand1_in * operand2_in;
    }
    else if (operator_in == '/') {
        if (operand2_in == 0) {
            throw std::runtime_error("Деление на ноль");
        }
        temp = operand1_in / operand2_in;
    }
    
    return temp;
}

int evaluateExpression(const char* expression, int& pos) {

    char operator_out = '\0';
    int operand1 = 0;
    int operand2 = 0;
    int result = 0;

    if (expression[pos] == '(') {

        operand1 = evaluateExpression_in(expression, pos);
        
        if (expression[pos] != ')') {
            throw std::runtime_error("Неправильное количество скобок");
        }
        pos++;
        
    }
    else if (isdigit(expression[pos])) {
        while (isdigit(expression[pos])) {
            operand1 = operand1 * 10 + (expression[pos] - '0');
            pos++;
        }
    }

    if (expression[pos] == '+' || expression[pos] == '-'
        || expression[pos] == '*' || expression[pos] == '/') {
        operator_out = expression[pos];
        pos++;
    }
    
    if (expression[pos] == '(') {

        operand2 = evaluateExpression_in(expression, pos);

        if (expression[pos] != ')') {
            throw std::runtime_error("Неправильное количество скобок");
        }
        pos++;

    }
    else if (isdigit(expression[pos])) {
        while (isdigit(expression[pos])) {
            operand2 = operand2 * 10 + (expression[pos] - '0');
            pos++;
        }
    }
    
    if (operator_out == '+') {
        result = operand1 + operand2;
    }
    else if (operator_out == '-') {
        result = operand1 - operand2;
    }
    else if (operator_out == '*') {
        result = operand1 * operand2;
    }
    else if (operator_out == '/') {
        if (operand2 == 0) {
            throw std::runtime_error("Деление на ноль");
        }
        result = operand1 / operand2;
    }
    return result;
}

int main() {
    SetConsoleOutputCP(1251);
    std::cout << "Введите арифметическое выражение: ";
    SetConsoleCP(1251);
    char* expression = new char[CHAR_MAX];
    cin >> expression;
    cout << expression << endl;

    int pos = 0;
    
    int result = evaluateExpression(expression, pos);
    
    cout << "Результат: " << result << endl;
    delete[] expression;
}