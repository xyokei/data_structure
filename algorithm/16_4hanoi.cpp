//
// Created by AutumnSigni on 2023/10/22.
//
// 四柱汉诺塔问题

/**
 * 问题：n个盘子，从A 移动到 B 用C D 两个柱子辅助 ，求移动次数最少
 * 移动步骤：
 * a. 将A柱前 n-k借助 B C 移动到 D -> n-k盘子四柱汉诺塔问题
 * b. 将A柱剩余 k 借助 C 移动到 B -> k盘子 三柱汉诺塔问题 移动次数2^k - 1
 * c. 将D柱前 n-k借助 A C 移动到 B -> n-k盘子四柱汉诺塔问题
 * 递归定义如下
 * 1. n = 0 时移动次数 0
 * 2. n = 1 时移动次数 1
 * 3. n > 1 f(n) = min(2f(n-k) +2^k -1) 在 k 在0~n的范围
*/

#include <iostream>
#include <cmath>
using namespace std;
int hanoi(int n){
    if (n == 0){
        return 0;
    }
    if (n==1){
        return 1;
    }
    int f[n];
    f[0] = 0;
    f[1] = 1;
    int temp;
    for (int i = 2; i <= n; ++i) {
        f[i] = 2 * f[i - 1] +1; //k = 1时 f(i)的值
        for (int k = i; k <= n; ++k) {  // i<=k<=n
            temp = 2 * f[k - i] + pow(2, i) - 1;
            if (temp < f[i]) {
                f[i] = temp;
            }
        }
        // 上面的循环和下面的是一样的，区别在于上面是从小递归到大，而下面需要考虑数组的初始值问题？
        // for (int k = i; k < n; ++k) {
        //     temp = 2 * f[n - k] + pow(2, k) - 1;
        //     if (temp < f[i]) {
        //         f[i] = temp;
        //     }
        // }
    }
    return f[n];
}

int main(){
    int count = hanoi(5);
    cout<<count;
    return 0;
}