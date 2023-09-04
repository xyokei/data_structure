//
// Created by AutumnSigni on 2023/8/31.
//

//中缀转后缀 并进行计算
#include <iostream>
#include <stack>
#include <queue>
#include <map>
#include <string>

using namespace std;

stack<int> num;
stack<char> op_stack;
map<char, int> op_level;
queue<char> postfix;
string postfix_str;


/**
 * 思路 :
 * 总共3类符号 数字 运算符 界限符
 *
 * 遇到数字 直接加入表达式
 * 遇到运算符 op  将此运算符与栈顶元素比较优先级，
 *     若 优先级高于栈顶元素   压栈
 *     若 优先级低于或等于栈顶元素 依次弹出栈顶元素所有优先级>=当前运算符等级的 直接加入表达式中 后，将当前运算符压栈
 *         若遇到栈空 或（ 则停止
 *     就是，依次弹出栈中高于或等于当前运算符的 op
 *
 * 遇到界限符 （{ 直接入栈 ，遇到 ）} 依次弹出栈内运算符 直接加入表达式 直到弹出（
 *
 * 处理完所有字符，将栈中元素直接加入到后缀表达式中
 *
 * 参数设定：
 *     用队列（或数组）保存后缀表达式
 *     给定str c++默认字符数组用i 索引
 * @param str
 */
void infixToPostfix(const string &str) {
    for (char c: str) {
        if (isalnum(c)) {//遇到数字 直接加入表达式
            postfix.push(c);
            postfix_str += c;
        } else if (c == '(') {// 遇到界限符 （{ 直接入栈
            op_stack.push(c);
        } else if (c == ')') {// 遇到 ）} 依次弹出栈内运算符 直接加入表达式 直到弹出（
            while (!op_stack.empty() && op_stack.top() != '(') {
                postfix_str += op_stack.top();
                postfix.push(op_stack.top());
                op_stack.pop();
            }
            op_stack.pop(); // pop (
        } else {// 遇到运算符 op  将此运算符与栈顶元素比较优先级
            while (!op_stack.empty() && op_level[c] <= op_level[op_stack.top()]) {
                postfix_str += op_stack.top();
                postfix.push(op_stack.top());
                op_stack.pop();
            }
            op_stack.push(c);  //总是容易忘记这一句
        }
    }
    while (!op_stack.empty()) {
        postfix_str += op_stack.top();
        postfix.push(op_stack.top());
        op_stack.pop();
    }
}

double cal() {
    int temp1, temp2;
    while (!postfix.empty()) {
        if (isalnum(postfix.front())) {
            num.push(postfix.front() - '0'); //如果不减的话 保存的是ASCII里该数字对应的 ASCII码
            postfix.pop();
        } else {
            temp1 = num.top();  //右操作数
            num.pop();
            temp2 = num.top();  //左操作数
            num.pop();
            switch (postfix.front()) {
                case '+':
                    num.push(temp2 + temp1);
                    break;
                case '-':
                    num.push(temp2 - temp1);
                    break;
                case '*':
                    num.push(temp2 * temp1);
                    break;
                case '/':
                    num.push(temp2 / temp1);
                    break;
            }
            postfix.pop();//总是容易忘记这一句
        }
    }
    return num.top();
}

void printPostfix() {
    cout << "后缀表达式:";
    for (char c: postfix_str) {
        cout << c << ' ';
    }
    cout << endl;
}
void clear(){
    while (!postfix.empty()){
        postfix.pop();
    }
    postfix_str="";
}

int main() {
    op_level['+'] = op_level['-'] = 1;
    op_level['*'] = op_level['/'] = 2;
    string str;
    while (getline(cin, str), str != "0") {
        for (string::iterator it = str.end(); it != str.begin(); it--) {
            if (*it == ' ') str.erase(it); //遍历去空格
        }
        if (!str.empty()) {
            clear();
            infixToPostfix(str); //中转后
            printPostfix();
            cout << "计算结果：" << cal() << endl; //计算
        }
    }
}