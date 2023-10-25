//
// Created by AutumnSigni on 2023/10/16.
//

// 大整数乘法
/**
* 给定 两个高精度的数 A B 计算他们的乘积
 * 两种方法
 * 一、暴力解法
 *  假定A的长度大于B的长度 结果存储在C[]数组中
 *  遍历 B的每个数字 b[i]  第i位  个十百千万这样...
 *     遍历A的每个数字 a[j]
 *         c[i+j] += a[i]*a[j] -> 当前位产生的数字与当前位数字相加
 *         c[i+j+1] +=c[i+j]/10  ->当前位产生的进位加到下一位上
 *         c[i+j] = c[i+j] %10 ->当前位个位是当前位的实际数
 * 分治思想
 * 1.大整数分解
 * 方法：下面写法不如直接贴公式，看导图吧
 *      A = a * 10^(n/2) +b
 *      B = c * 10^(n/2) +d
 *      A * B = ac * 10^{2*(n/2)} + (ad+bc) * 10^(n/2) +bd 就是乘法分配
 *      此时效率并未提高，
 *      主要计算 4 个 数 ac ad bc bd，注意到ad+bc = (a+b)(c+d)-ac-bd 加法比乘法快 4个乘法变成3个乘法和2个加法
 * 算法实现不太好弄啊，后面有时间再看吧
*/
#include <iostream>
#include <cstring>

using namespace std;

struct bigint {
    int d[1000];
    int len;

    bigint() { //构造函数
        memset(d, 0, sizeof(d));
        len = 0;
    }
};

void bigMulti(bigint a, bigint b, bigint &c) {
    for (int i = 0; i < a.len; ++i) {
        int j = 0;
        for (; j < b.len; ++j) {
            c.d[i + j] += a.d[i] * b.d[j];   // 当前位产生的数字与当前位数字相加
            c.d[i + j + 1] += c.d[i + j] / 10;  // 当前位产生的进位加到下一位上
            c.d[i + j] = c.d[i + j] % 10;   // 当前位个位是当前位的实际数
        }
        c.len = i + j + 1;
    }
}

int main() {
    // 测试非分治法
    string str_a, str_b;
    cout << "大整数a:";
    cin >> str_a;
    cout << "大整数b:";
    cin >> str_b;
    bigint a, b;
    a.len = str_a.length();
    b.len = str_b.length();
    for (int i = 0; i < a.len; ++i) {
        a.d[i] = str_a[a.len - i - 1] - '0'; //倒着赋值
    }
    for (int i = 0; i < b.len; ++i) {
        b.d[i] = str_b[b.len - i - 1] - '0'; //倒着赋值
    }
    bigint c;
    bigMulti(a, b, c);
    for (int i = 0; i < c.len; ++i) {
        cout << c.d[c.len - i - 1];
    }

}