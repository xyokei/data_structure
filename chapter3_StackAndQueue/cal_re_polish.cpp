//
// Created by AutumnSigni on 2023/8/30.
//

// 计算后缀表达
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

double cal(queue<char> q) {
    stack<int> num;
    stack<char> op;
    int temp1;
    int temp2;

    while (!q.empty()) {
        if (q.front() >= 0 && q.front() <= 20) {
            num.push(q.front());
            q.pop();
        } else {
            temp2 = num.top();
            num.pop();
            temp1 = num.top();
            num.pop();
            switch (q.front()) {
                case '+':
                    num.push(temp1 + temp2);
                    break;
                case '-':
                    num.push(temp1 - temp2);
                    break;
                case '*':
                    num.push(temp1 * temp2);
                    break;
                case '/':
                    num.push(temp1 / temp2);
                    break;
            }
            q.pop();
        }
    }
    return num.top();
}
int main(){
    queue<char> q;
    q.push(15);
    q.push(7);
    q.push(1);
    q.push(1);
    q.push('+');
    q.push('-');
    q.push('/');
    q.push(3);
    q.push('*');
    q.push(2);
    q.push(1);
    q.push(1);
    q.push('+');
    q.push('+');
    q.push('-');

    cout<<cal(q);
}