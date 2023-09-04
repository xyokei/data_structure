//
// Created by AutumnSigni on 2023/8/31.
//


//中缀转前缀 并进行计算

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
 * 首先将中缀表达式进行反转，
 * 然后使用类似后缀转中缀的思路，通过栈来处理操作符和括号。
 * 最后，再次对得到的前缀表达式进行反转，得到最终的前缀表达式
 *
 * 好像没有考这个的，先不写了，后续有时间补上
 */
