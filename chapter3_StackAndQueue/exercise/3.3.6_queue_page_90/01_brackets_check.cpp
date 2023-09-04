//
// Created by AutumnSigni on 2023/8/31.
//

// 括号 匹配
#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool brackets_check(const string &str) {
    stack<char> bracket;
    for (char c: str) {
        if (c == '(' || c == '{' || c == '[') {
            bracket.push(c);
        } else {
            switch (c) {
                case ')':
                    if (bracket.top() == '(') {
                        bracket.pop();
                    } else {
                        return false;
                    }
                    break;
                case '}':
                    if (bracket.top() == '{') {
                        bracket.pop();
                    } else {
                        return false;
                    }
                    break;
                case ']':
                    if (bracket.top() == ']') {
                        bracket.pop();
                    } else {
                        return false;
                    }
                    break;
                default:
                    break;
            }
        }
    }
    if (bracket.empty()) return true;
    return false;
}

int main() {
    string str;
    while (getline(cin, str), str != "0") {
        for (string::iterator it = str.end(); it != str.begin(); it--) {
            if (*it == ' ') str.erase(it); //遍历去空格
        }
        if (!str.empty()) {
            if (brackets_check(str)){
                cout<<"true"<<endl;
            } else{
                cout<<"false"<<endl;
            }
        }
    }
}
