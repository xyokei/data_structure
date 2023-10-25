//
// Created by AutumnSigni on 2023/10/24.
//
// 最大团问题

/**
 * 问题：设无向图 V，其子图 U,U中任意两个顶点都有边，则 V称为团
 * 找出最大团，即找出符和条件的 U，且U的顶点数最多
 * 两个顶点不构成团 要舍去
 * 解空间：子集树
 * 约束条件：当前选定顶点i 与已选定U中任一个顶点都有边 ->没边就直接剪掉这个选的分支，即左分支
 * 上界函数：当前剩余未处理的点数 与 当前解集的顶点数之和比 之前最优解大，说明右子树存在可能解，否则剪枝
 *
*/
#include <iostream>

using namespace std;
int n = 5;
int **a;//二维数组
int *best; //最优解结构
int *x;//当前解结构 x[j]=1 表示顶点j选，0不选
int cn=0;//当前解
int bestN=0;//最优解

void maxGroup(int i) {
    if (i > n) {
        if (cn > bestN && cn > 2) {//顶点数大于2才被当做团
            for (int j = 1; j <= n; ++j) {
                best[j] = x[j];
            }
            bestN = cn;
        }
    } else {
        bool ok = true;
        // 处理当前第i个结点，判断在之前选择的i顶点是否与当前顶点相连
        // 至于j < i ，因为当前顶点是按递增顺序处理的，处理i结点时，后续n-i个结点都没处理
        // 所以不需要判断
        for (int j = 1; j < i; ++j) {
            if (x[j] == 1 && !a[j][i]) {
                ok = false;
                break;
            }
        }
        // 若当前结点与之前选的顶点都相连
        if (ok) {
            x[i] = 1; //选
            cn++;
            maxGroup(i + 1);
            cn--;//回溯
        }
        if (cn + n - i > bestN) { //上界剪枝,感觉也减不掉多少
            x[i] = 0;
            maxGroup(i + 1);
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
    maxGroup(1);
    cout << "max v count:" << bestN << endl;
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