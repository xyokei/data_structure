//
// Created by AutumnSigni on 2023/10/21.
//
#include <iostream>
#include <vector>

// 不管了，就找矩阵连乘的改，就权值那地方修改下就性了
using namespace std;

int minTrian(vector<int> &weights, int **s) {
    int n = weights.size(); // 顶点的个数
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // 填充dp数组
    for (int len = 2; len <= n; ++len) {
        for (int i = 1; i < n - len + 1; ++i) {
            int j = i + len - 1;
            dp[i][j] = dp[i + 1][j] + weights[i - 1] * weights[i] * weights[j];
            s[i][j] = i;
            for (int k = i + 1; k < j; ++k) {
                // 计算当前分割点的权值和，并更新最小值
                int weight = dp[i][k] + dp[k + 1][j] + weights[i - 1] * weights[k] * weights[j];
                dp[i][j] = min(dp[i][j], weight);
                if (weight < dp[i][j]) {
                    dp[i][j] = weight;
                    s[i][j] = k;
                }
            }
        }
    }
    return dp[0][n - 1];
}

//chatgpt
int minTriangulationWeight(vector<int> &weights) {
    int n = weights.size(); // 顶点的个数
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // 填充dp数组
    for (int len = 2; len < n; ++len) {
        for (int i = 0; i < n - len; ++i) {
            int j = i + len;
            dp[i][j] = INT_MAX;
            for (int k = i + 1; k < j; ++k) {
                // 计算当前分割点的权值和，并更新最小值
                int weight = dp[i][k] + dp[k][j] + weights[i] * weights[k] * weights[j];
                dp[i][j] = min(dp[i][j], weight);
            }
        }
    }
    return dp[0][n - 1];
}

int main() {
    // 顶点之间的边权值
    // 任何凸多边形，有多少顶点就有多少条边
    // 所以设定 边权w表示 顶点下标 i与顶点 下标 i+1的权值
    vector<int> weights = {6, 1, 2, 3, 4, 5, 6}; //68
    int **s = new int *[7];
    for (int i = 0; i <= 7; ++i) {
        s[i] = new int[7];
    }
    // 计算最小权值和的最优三角剖分
    int minWeight = minTriangulationWeight(weights);
    int minWeight1 = minTrian(weights, s);

    // 输出结果
    cout << "Minimum triangulation weight: " << minWeight << endl;
    return 0;
}
