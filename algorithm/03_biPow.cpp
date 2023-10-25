//
// Created by AutumnSigni on 2023/10/14.
//

// 快速幂
//给定实数a ,n 分治法求a^n
#include <iostream>

using namespace std;

// 常规写法
/**
 *
 * @param a 给定实数
 * @param n 幂次
 * @return
 */
double biPow(double a, int n) {
    if (n == 0) return 1;
    // n为奇数,转换为n-1
    if (n % 2 == 1) { // n & 1 位与操作
        return a * biPow(a, n - 1);
    } else {
        // n为偶数
        double x = biPow(a, n / 2);
        return x * x;
    }
}

// 迭代写法
double biPow_1(double a, int n) {
    double ans = 1.0;
    while (n > 0) {
        if (n & 1) { //二进制最后一位是1 奇数
            ans = ans * a;
        }
        //n 是偶数
        a = a * a;
        n >>= 1; // 相当于/2操作
    }
    return ans;
}

int main() {
    double a = 2;
    int n = 4;
    double rs = biPow(a, n);
    cout << rs<<endl;
    rs = biPow_1(a,n);
    cout << rs<<endl;
}
