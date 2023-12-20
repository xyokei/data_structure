//
// Created by AutumnSigni on 2023/11/24.
//

#include <iostream>
#include <stack>
#include <algorithm>

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int getOperatorPriority(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;  // 对于其他字符，如括号，返回0
}

std::string infixToPrefix(const std::string& infix) {
    std::stack<char> operators;
    std::string prefix;

    for (int i = infix.length() - 1; i >= 0; --i) {
        char currentChar = infix[i];

        if (isOperator(currentChar)) {
            while (!operators.empty() && getOperatorPriority(operators.top()) >= getOperatorPriority(currentChar)) {
                prefix += operators.top();
                operators.pop();
            }
            operators.push(currentChar);
        } else if (currentChar == ')') {
            operators.push(currentChar);
        } else if (currentChar == '(') {
            while (operators.top() != ')') {
                prefix += operators.top();
                operators.pop();
            }
            operators.pop();  // 弹出 '('
        } else {
            prefix += currentChar;
        }
    }

    while (!operators.empty()) {
        prefix += operators.top();
        operators.pop();
    }

    // 前缀表达式是反转的，需要翻转过来
    std::reverse(prefix.begin(), prefix.end());

    return prefix;
}

int main() {
    std::string infixExpression = "2 + 3 * 4";
    std::string prefixExpression = infixToPrefix(infixExpression);

    std::cout << "Infix Expression: " << infixExpression << std::endl;
    std::cout << "Prefix Expression: " << prefixExpression << std::endl;

    return 0;
}
