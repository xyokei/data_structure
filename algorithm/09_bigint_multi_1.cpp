//
// Created by AutumnSigni on 2023/10/23.
//

//  分治法解
#include <iostream>
#include <string>

using namespace std;

// 函数：字符串相加
// 大整数加法
string add(const string &a, const string &b) {
    string result;
    int carry = 0; //进位
    int i = a.size() - 1;//长度
    int j = b.size() - 1;

    // 从字符串的最后一位开始相加，直到两个字符串都加完且进位为0
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) {
            sum += a[i] - '0';
            i--;
        }
        if (j >= 0) {
            sum += b[j] - '0';
            j--;
        }
        // 计算进位和当前位的数字
        carry = sum / 10;
        sum %= 10;
        // 将当前位的数字插入到结果字符串的最前面
        result.insert(result.begin(), sum + '0');
    }

    return result;
}

// 大整数减法
string subtract(const string &a, const string &b) {
    string result;
    int borrow = 0;//借位
    int i = a.size() - 1;
    int j = b.size() - 1;

    while (i >= 0 || j >= 0) {
        int x = (i >= 0) ? (a[i] - '0') : 0;
        int y = (j >= 0) ? (b[j] - '0') : 0;

        int diff = x - y - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        result.insert(result.begin(), diff + '0');
        i--;
        j--;
    }
    // 删除最前面的0
    while (result.size() > 1 && result[0] == '0') {
        result.erase(result.begin());
    }
    return result;
}

void modify(string &x, string &y) {
    int fill;
    // 不足为补0处理
    if (x.size() > y.size()) {
        fill = x.size() - y.size();
        for (int i = 0; i < fill; ++i) {
            y.insert(y.begin(), '0');
        }
    } else {
        fill = y.size() - x.size();
        for (int i = 0; i < fill; ++i) {
            x.insert(x.begin(), '0');
        }
    }
}

// 函数：Karatsuba乘法
string multiply(string &x, string &y) {
    // 计算输入字符串的长度
    int n = max(x.size(), y.size());
    modify(x, y);// 不足为补0处理
    // 如果字符串长度为1，直接返回它们的乘积
    if (n == 1) {
        return to_string((x[0] - '0') * (y[0] - '0'));
    }
    // 将输入字符串分成两半
    int mid = n / 2;
    string x1 = x.substr(0, x.size() - mid);//前半部分 a
    string x0 = x.substr(x.size() - mid); //后半部分 b
    string y1 = y.substr(0, y.size() - mid); //前半部分 c
    string y0 = y.substr(y.size() - mid); //后半部分 d

    // 递归计算三次乘法 X * Y  = ac +{(a+b)(c+d) - ac - bd} +bd
    string z2 = multiply(x1, y1); // ac 最高位
    string z0 = multiply(x0, y0); // bd 最低位
    string z11 = add(x0, x1); // a+b
    string z12 = add(y0, y1); // c+d
    string z1 = multiply(z11, z12); //(a+b)(c+d) 中间位
    z1 = subtract(subtract(z1, z0), z2); // z1 -z0 -z2
    // 三次乘法的前两位需要处理
    string result = z2;
    for (int i = 0; i < 2 * mid; ++i) { //最高位 补 2 * mid 个 0
        z2.push_back('0');
    }
    for (int i = 0; i < mid; ++i) { // 中间位 补mid个 0
        z1.push_back('0');
    }
    // 三次乘法的结果相加
    result = add(z2, z1);  //字符串相加
    result = add(result, z0);
    return result;
}

int main() {
    // 测分治法
    // 输入两个大整数字符串
    string x, y;
    cout << "Enter first number: ";
    cin >> x;
    cout << "Enter second number: ";
    cin >> y;

    // 调用Karatsuba算法计算乘积
    string result = multiply(x, y);
    // 删除首位0
    while (result.size() > 1 && result[0] == '0') {
        result.erase(result.begin());
    }
    cout << "Multiplication result: " << result << endl;

    return 0;
}