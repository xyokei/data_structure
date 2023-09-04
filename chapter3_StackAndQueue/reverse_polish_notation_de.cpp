//
// Created by AutumnSigni on 2023/8/30.
//

// 中缀转后缀表达式
#include <iostream>
#include "stack_util.h"
#include "queue_util.h"
#include <string>
#include <map>

using namespace std;

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
 *     给定char[] 直接索引
 *
 * 写完感觉纯粹给自己找不痛快的，我写的结构体用起来真麻烦啊，不用了，用标准库写
 *
 * @param str
 */

void change(const string &str) {
    map<char, int> op; //当然也可以用结构体达到同样效果
    op['+'] = op['-'] = 1;
    op['*'] = op['/'] = 2;

    SqStack stack;  //c++ stl 有自己的stack
    initStack(stack);

    SqCircleQueue queue;
    initQueue(queue);

    for (char i: str) { //for (int i = 0; i < str.length(); ++i) {
        if (i >= 'a' && i <= 'g') {
            enQueue(queue, i);
        } else if (i == 40) {  //ASCII码表 40 = (   41=)，也可以用字符
            push(stack, i);
        } else if (i == 41) {
            char opx = 0;
            pop(stack, opx);
            while (opx != '(' && !isEmpty(stack)) {
                enQueue(queue, opx);
                pop(stack, opx);
            }
        } else {
            char opx = 0;
            while (!isEmpty(stack)) {
                getTop(stack, opx);
                if (op[i] <= op[opx] && op[opx] != '(') {
                    enQueue(queue, opx);
                    pop(stack, opx);
                } else {
                    break;
                }
            }
            push(stack, i);
        }
    }
    while (!isEmpty(stack)) {
        char opx = 0;
        pop(stack, opx);
        enQueue(queue, opx);
    }
    printQueue(queue);
}

int main() {
    string str = "a+b*(c-d)-e/f";
    change(str);
    // while (getline(cin,str),str !="0"){
    //     for(string::iterator it = str.end();it!=str.begin();it--){
    //         if (*it == ' ') str.erase(it); //遍历去空格
    //     }
    //     if (!str.empty()){
    //         change(str);
    //     }
    // }
}


