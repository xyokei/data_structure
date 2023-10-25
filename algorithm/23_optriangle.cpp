//
// Created by AutumnSigni on 2023/10/24.
//

// 符号三角形问题

/**
 * 符号总共 + - 第二行由第一行生成两加边加，加减变减 减减变加
 * 给定n个符号 有多少个不同的符号组合 生成符号三角形中 + -个数相同
 * n个符号 总共生成 n(n+1)/2 分一半 + 号是n(n+1)/4 个符号
 * 解空间 第1行就是解
 *   可行性约束函数 当前符号三角形包含的+ -个数都不超过 n(n+1)/2
 */

#include <iostream>

using namespace std;

//设定 0 是 +， 1 是 -
int n = 7; // 第一行符号的个数
int half = n * (n + 1) / 4;  // 所有符号的一半
int count = 0; // 负号个数
int **p;// 所有符号的数组 存储结构和数字塔一样 下标从1开始
int sum = 0; // 满足正负号个数相同的解的个数

//本题从第一行扩展到第n行每次t的选择都是在第一行上增加一个符号
// 即t = 2,即第一行有2个符号 能生成第二行的符号
//   t = 3，即第一行有3个符号 此时其他两行符号有第一行生成
//   若t=3时当前选择的 '-' 已不满足约束条件，返回t=2然后再进行 t=3 '+'号的生成，以此类推
// 主要就是计算符号方面的处理，用异或较为简洁
void opTriangle(int t) {
    if (count > half || (t * (t - 1)) / 2 - count > half)return;
    if (t > n) { sum++; }
    else {
        for (int i = 0; i < 2; ++i) {
            p[1][t] = i; //设定 - 和 + 此时前t 个位置已经设定好符号了
            count += i;
            //第一行从1到t 往下能生成的符号数
            for (int j = 2; j <= t; ++j) {
                // 0 ^ 1 = 0  异或就可以看成+-运算
                // 副对角线的符号计算
                p[j][t - j + 1] = p[j - 1][t - j + 1] ^ p[j - 1][t - j + 2];
                count += p[j][t - j + 1]; //累计符号
            }
            opTriangle(t + 1);
            for (int j = 2; j <= t; ++j) {
                count -= p[j][t - j + 1]; //回溯上次选择
            }
            count -= i;
        }
    }
}

int main() {
    //初始化二维数组
    p = new int*[n+1];
    for (int i = 0; i <=n; ++i) {
        p[i]=new int[n+1];
    }
    opTriangle(1);
    cout << "sum : " << sum << endl;
    // 释放动态分配的内存
    for (int i = 0; i <= n; ++i) {
        delete[] p[i];
    }
    delete[] p;
    return 0;
}