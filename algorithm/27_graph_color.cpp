//
// Created by AutumnSigni on 2023/10/25.
//

// 图的上色问题
/**
*  给定一个无向图，要求给图的每个顶点分配一种颜色，
 * 使得相邻的顶点具有不同的颜色。问题的目标是找到一种颜色分配方案，使得使用的颜色数目最小。
 * 解空间：排列树
 * 约束条件：相邻顶点不能有相同的颜色
 * 没有上界函数，意味着要遍历所有可能结果，故属于np问题，时间复杂度是非多项式的
*/

#include <iostream>

using namespace std;
int n = 5;
int **a;//二维数组
int *best; //最优解结构
int *x;// 当前解结构 x1 x2 x3 分别表示对应下标顶点所着的颜色
int sum=0;//符号题意的着色方案

bool ok(int k) {
    for (int j = 1; j <= n; ++j) {
        //当前结点的边相连的边 且 当前顶点选的颜色与相连边种颜色相同
        if (a[k][j] && x[j] == x[k]) {
            return false;
        }
    }
    return true;
}

void graphColor(int i){
    if (i>n){
        for (int j = 1; j <=n; ++j) {
            best[j] =x[j];
        }
        sum++;
    } else{
        for (int color = 1; color <=n; ++color) {
            x[i] = color;
            if (ok(i)){
                graphColor(i+1);
            }
            //此处不用重置x[color]的值，因为选择下一个颜色时会重新覆盖所选的颜色
        }
    }
}
int main() {
    // 初始化
    a = new int *[n + 1];//下标从1开始
    best = new int[n+1];
    x = new int[n+1];
    for (int i = 0; i < n + 1; ++i) {
        a[i] = new int[n + 1];
    }
    for (int i = 0; i < n + 1; ++i) {
        for (int j = 0; j < n + 1; ++j) {
            a[i][j] = 0; //无边 默认 0 是 false 1 true
        }
    }
    for (int i = 0; i <= n; ++i) {
        best[i] = 0;
        x[i] =0;
    }
    a[1][2] =1;
    a[1][4] =1;
    a[1][5] =1;
    a[2][1] =1;
    a[2][5] =1;
    a[3][2] =1;
    a[3][5] =1;
    a[4][1] =1;
    a[4][5] =1;
    a[5][4] =1;
    a[5][1] =1;
    a[5][2] =1;

    // test
    graphColor(1);
    cout << "sum:" << sum << endl;
    cout<<"sequence: ";
    for (int i = 1; i <= n; ++i) {
        cout << best[i] << ' ';
    }
    // 释放动态分配的内存
    for (int i = 0; i < n + 1; ++i) {
        delete[] a[i];
    }
    delete[] a;
    delete[] best;
    delete[] x;

    return 0;
}