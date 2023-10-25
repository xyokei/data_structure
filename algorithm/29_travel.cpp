//
// Created by AutumnSigni on 2023/10/25.
//
// 旅行售货员问题
/**
* n个城市，找出从一城市出发走偏n个城市的最短回路问题
 * 虽然看起来和单源最短路径类似，但是多了一个回路问题，算法就不好做了，属于np问题
 * 解空间 排列树
 * 约束条件：当前城市与上一个城市右边 就选，即进左子树，没有不选
 * 上界函数：没有 典型np问题
 *          后面会学的分支限界法都是处理这个上界函数的
 *          挺难的，感觉不好实现
 * 处理技巧：不用全源，因为是包括所有城市回路，指定一个城市，形成单源构造
 *           递归到倒数第二层就可以停止了，因为最后的选择只有一个
*/
#include <iostream>

using namespace std;

// 解空间树: 排列树

int m = 4; //顶点数
int n = 3;//下标数

int NoEdge = LONG_LONG_MAX;
int x[4];// 当前选择城市解x[i]，表示第i个选择的城市下标，
int bestX[4];//最优解

// 图的保存, 二维数组
int a[4][4] ={{NoEdge, 10, 15, 20},
              {10, NoEdge, 35, 25},
              {15, 35, NoEdge, 30},
              {20, 25, 30, NoEdge}};

// 当前的费用
int cc;
int bestC = LONG_LONG_MAX;// 最佳费用

void swap(int &a, int &b) {
    int temp =a;
    a=b;
    b =temp;
}

void backtrack(int t) {
    if (t == n-1) {//下标是从0开始的，然后从1~n-2个结点进行全排列 且顶点数 = n+1,n对应的是下标最大值
        // 此时已经处理n-1个顶点了还剩最后一个顶点进行处理 下标比n-1少1
        // 上一个选择城市与最后一个城市有边 且 最后一个城市与第一个选择的城市有边
        // 且当前解的最小花费比 之前解更小，
        if (a[x[n - 1]][x[n]] != NoEdge && a[x[n]][1] != NoEdge
            && (cc + a[x[n - 1]][x[n]] + a[x[n]][1] < bestC || bestC == NoEdge)) {
            for (int i = 1; i <= n; ++i) {
                bestX[i] = x[i]; //更新最优解
            }
            bestC = cc + a[x[n - 1]][x[n]] + a[x[n]][1];//更新最小花费
        }
    } else {
        for (int i = t; i <= n; ++i) {
            // 是否可以进入 x[i] 子树 ?
            // 剪枝，属于约束条件
            if (a[x[t - 1]][x[i]] != NoEdge && (cc + a[x[i - 1]][x[i]] < bestC || bestC == NoEdge)) {
                // 搜索子树
                swap(x[t], x[i]);
                cc += a[x[t - 1]][x[t]];
                backtrack(t + 1);
                cc -= a[x[t - 1]][x[t]];
                swap(x[t], x[i]);
            }
        }
    }
}
int main() {
    // 初始化x和bestX数组
    for (int i = 0; i <= n; ++i) {
        x[i] = bestX[i] = i;
    }
    // 调用回溯法求解
    backtrack(1);
    // 输出最优解
    cout << "Best circuit: ";
    for (int i = 0; i <= n; ++i) {
        cout << bestX[i] << " -> ";
    }
    cout << bestX[0] << endl;
    cout << "Minimum cost: " << bestC << endl;
    return 0;
}