//
// Created by AutumnSigni on 2023/10/21.
//

// 01背包问题 动态规划解决
// 第三类动态规划问题
// 多阶段动态规划：问题可以描述为若干个有序的阶段，且每个阶段只和上一个阶段的状态有关
/**
 *  问题：n件物品，每件物品重量w[i] 价值v[i],背包容量c,如何选取物品放入背包，使得背包内物品总价值最大
 *  ：每种物品只有一件
 *  最优子结构
 *    设dp[i][j] 表示 前i个物品装入容量为j的背包所能获得的最大价值
 *    两种情况：当第i个物品 选择不装入时  dp[i][j] = dp[i-1][j]
 *             当第i个物品 选择装入时  c-w[i]是装入后的剩余容量 因此 c-w[i]>=0
 *                                   dp[i-1][c-w[i]]是前面i-1个物品装入容量为c-w[i]的最大价值，这个值已经被计算过了
 *                                   dp[i-1][c-w[i]] +v[i] 就是当前物品装入时的价值
 *                                   max{dp[i-1][j],dp[i-1][c-w[i]] +v[i]} 取最大值
 *    边界：初始：
 *         当容量 c >= w[1]时 即第一个物品的重量可以放下，此时对应的dp[1][c] = v[1]
 *    将背包容量看成动态的
*/
#include <iostream>
#include <cstring>

using namespace std;

void printArray(int **a, int row,int col) {
    for (int i = 1; i <=row; ++i) { //下标从1开始
        for (int j = 0; j <= col; ++j) {//下标从0开始
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }
}

/**
 *
 * @param w w[i] 第i个物品的重量 下标从1 开始
 * @param v v[i] 第i个物品的价值 下标从1 开始
 * @param i i 物品下标 从1开始
 * @param j j 容量下标 从0开始
 * @param dp dp[i][j] 容量为j的背包处理装入前i个物品的最大价值
 */
void packet(const int *w, int *v, int i, int j, int **dp) {
    for (int k = 0; k <= j; ++k) {
        // 边界
        // 当容量 k >= w[1]时 即第一个物品的重量可以放下，此时对应的dp[1][k] = v[1]
        if (k >= w[1]) {
            dp[1][k] = v[1];
        }
    }
    for (int k = 0; k <= i; ++k) {
        // 背包容量为0 即没有物品能装入，所以价值为 0
        dp[k][0] = 0;
    }
    // 第一个物品已经放入且价值已经处理好，从第二个物品开始
    for (int k = 2; k <= i; ++k) {
        // 背包容量从 1 开始增
        for (int c = 1; c <= j; ++c) {
            // 当第i个物品 选择装入时 c-w[k]是装入后的剩余容量 因此 c-w[k]>=0
            if (c >= w[k]) {
                // dp[k-1][c-w[i]] + v[k] 就是当前物品装入时的价值 + 此前的最大价值
                dp[k][c] = max(dp[k - 1][c], (dp[k - 1][c - w[k]] + v[k]));
            } else {
                // 当第i个物品 选择不装入时  dp[i][j] = dp[i-1][j]
                dp[k][c] = dp[k - 1][c];
            }
        }
    }
}
void traceBack(int **dp, const int *w, int i, int j, int *x) {
    for (int k = i; k > 0; --k) {
        // 总容量为j, 第k个物品与第k-1个物品的价值相同，说明第k个物品没选
        // 第k个物品没装
        if (dp[k][j] == dp[k - 1][j]) {
            x[k] = 0;
        } else {
            x[k] = 1;
            j -= w[k];
        }
    }
}
int main() {
    int w[5] = {0, 2, 3, 4, 2};
    int v[5] = {0, 3, 6, 9, 7};
    int i = 4; //物品个数
    int j = 5; //背包容量
    int **dp =new int *[i+1]; //0 不用 行是物品
    for (int k = 0; k < 5; ++k) {
        dp[k] = new int[j+1]; // 0 用 列是容量
        memset(dp[k], 0, sizeof(int) * (j + 1)); // 使用memset将dp[k]数组初始化为0
    }
    packet(w, v, i, j, dp);
    printArray(dp,i,j);
    cout << endl;
    int *x = new int[i + 1]; // 为x分配内存空间;
    int total =dp[i][j];
    // 第i个物品选择与否 0 不选 1 选
    traceBack(dp,w,i,j,x);
    for (int k = 1; k <=i; ++k) {
        cout<<x[k]<<' ';
    }
    // 最大价值
    cout<<endl<<"max value："<<total<<endl;

    // 删除内存
    for (int k = 0; k < i; ++k) {
        delete[] dp[k];
    }
    delete[] dp;
    delete[] x;
    return 0;
}