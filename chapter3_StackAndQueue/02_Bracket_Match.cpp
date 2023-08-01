//
// Created by AutumnSigni on 2023/7/13.
//

// 括号匹配

#include <iostream>
#include <ctime>

//分析: 给定一组 括号串,判断是否匹配成功
// 设定一个栈
// 1. 遍历 字符串
// 2.          若该串 是( { [ 进栈
// 3.1         若该串 是) { ] 取栈顶元素 若成对 则栈顶元素 出栈,继续执行
// 3.2                                  若不成对, 则进栈 继续
// 4. 遍历结束 若栈空 return true, or return false
bool bracketMatch(SqStack &sqStack){

};