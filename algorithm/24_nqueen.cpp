//
// Created by AutumnSigni on 2023/10/24.
//

// n皇后问题
/**
* 棋盘 n*n，摆放n个皇后 使得任意2个皇后不在同行不在同列 不在同意斜线上
 * 由不在同行->即子集问题{x1,x2...xn} 的全排列问题 这个排列已经保证不同行了
 * 不同列 -> x! = xj 约束条件
 * 不在同一正反对角线 -> 约束条件 剪掉左分支 |i-j| ≠ |xi-xj| 这个要记啊，自己有时候想不到
 * 问有多少种不同摆放方法
*/

#include <iostream>

using namespace std;
int n = 4;
int *x; //x[i] 表示第i行 皇后所在列的位置
int sum = 0;

bool place(int t){
    for (int i = 1; i < t; ++i) {
        // i = t时，即同列判断
        // i ≠ t时，即斜线判断
        if (abs(i-t) == abs(x[i]-x[t])){
            return false;
        }
    }
    return true;
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void nQueen(int t) {
    if (t > n) {
        sum++;
    } else {
        for (int i = t; i <= n; ++i) {
            swap(x[t],x[i]);
            if (place(t)){ //剪枝
                nQueen(t+1);
            }
            swap(x[t],x[i]);
        }
    }
}

int main() {
    //初始化二维数组
    x = new int[n+1];
    nQueen(1);
    cout << "sum : " << sum << endl;
    // 释放动态分配的内存
    delete[] x;
    return 0;
}