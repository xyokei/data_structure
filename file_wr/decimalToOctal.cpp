//
// Created by AutumnSigni on 2023/12/10.
//
#include <iostream>
#include <stack>

using namespace std;

// 所有的10进制转其他进制方法
// 整数部分 除基取余 小数部分 乘基取整
// 2 8 16 转10
// 手算 全转成二进制后 从后完全，8进制就是3个2进制数化10进制，16进制就是4个2进制数化10进制，高位不足补0
// 非10进制转换 将其他进制转二进制 也是除基取余法，然后用二进制转成对应的进制
// 十进制转八进制函数
string decimalToOctal(int decimalNum) {
    stack<int> octalStack;

    // 当十进制数大于0时，继续转换
    while (decimalNum > 0) {
        // 将余数压入栈中
        int remainder = decimalNum % 8;
        octalStack.push(remainder);
        // 更新十进制数为其除以8的整数部分
        decimalNum /= 8;
    }

    // 弹出栈中的元素构建八进制数
    string octalNum = "";
    while (!octalStack.empty()) {
        octalNum += to_string(octalStack.top());
        octalStack.pop();
    }

    return octalNum.empty() ? "0" : octalNum;
}

int main() {
    // 示例
    int decimalNumber = 42;
    string octalNumber = decimalToOctal(decimalNumber);
    cout << decimalNumber << " 的八进制表示为：" << octalNumber << endl;

    return 0;
}
