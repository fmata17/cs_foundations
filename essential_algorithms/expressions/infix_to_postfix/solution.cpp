#include <iostream>
#include <stack>
#include <string>
#include <queue>

int getPrecedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

std::string infixToPostfix(const std::string& infix) {
    std::stack<char> operators;
    std::queue<char> output;
    
    for (char token : infix) {
        if (isalnum(token)) {
            output.push(token);
        } else if (token == '(') { 
            operators.push(token);
        } else if (token == ')') {
            while (!operators.empty() && operators.top() != '(') { // Pop until '('
                output.push(operators.top());
                operators.pop();
            }
            operators.pop(); // Pop the '('
        } else {
            while (!operators.empty() && getPrecedence(operators.top()) >= getPrecedence(token)) { // Pop higher or equal precedence operators
                output.push(operators.top());
                operators.pop();
            }
            operators.push(token);
        }
    }
    
    while (!operators.empty()) { // Pop remaining operators
        output.push(operators.top());
        operators.pop();
    }
    
    std::string postfix;
    while (!output.empty()) {
        postfix += output.front();
        postfix += " ";
        output.pop();
    }
    
    return postfix;
}

int main() {
    std::string infix;
    std::cout << "Enter an infix expression: ";
    std::cin >> infix;
    
    std::string postfix = infixToPostfix(infix);
    std::cout << "Postfix expression: " << postfix << std::endl;
    
    return 0;
}