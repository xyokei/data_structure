//
// Created by AutumnSigni on 2023/10/18.
//

//最长公共子序列
// 动态规划做到这题已经有三种类型了，
// 一种自底向上的，如矩阵连乘，数字塔（其实也是从底往上的，只不过底是n-1）
// 此题就是第二种 利用状态转移方程 dp 其dp的值依靠前面的解能算出，说起来前两个也是这样

/**
*  问题：给定两个字符序列集合，找出他们最长的公共部分，子序列可以不连续
 *  {B,C,D,B} {A,B,C,B,D,A,B}->{B,C,D,B}
 *  1. 暴力解法，假的两个集合长度n,m 每个字符都有选不选两种状态，即2的m+n次方
 *              比较两个子序列是否相同需要O(max{m,n})，两个复杂度一乘，时间太长了
 *  2. 动态规划：
 *     d[i][j]:表示集合A的第i 与集合B的j位 之前的LCS长度（下标从1开始）
 *       如 A:SADS B ADMIN d[4][5] 就是 A,B的 LCS,即最终dp[n][m]即为所求；
 *     分析：
 *     1. A[i] == [j]，即A的第i个字符，B的第j个字符相等 dp[i-1][j-1] + 1
 *     2. A[i] != [j]，字符不等，dp[i][j] = max{dp[i-1][j]，dp[i][j-1]}
 *        这两个值必定是之前算过的，
*/
#include <iostream>
#include <cstring>

using namespace std;

void lcs(char *a, char *b, int **dp, int n, int m, int **B) {
    // 定初值
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= n; ++i) {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i] == b[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                B[i][j] = 1;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                dp[i][j] = dp[i - 1][j];
                B[i][j] = 2;
            } else {
                dp[i][j] = dp[i][j - 1];
                B[i][j] = 3;
            }
        }
    }
}

void traceBack_1(int i, int j, char *X, char *Y, int **dp) {
    if (i == 0 || j == 0) {
        return;
    }
    // 两个数相等, 则此数是公共子序列中的一个
    if (X[i] == Y[j]) {
        traceBack_1(i - 1, j - 1, X, Y, dp);
        cout << X[i] << " ";
    } else if (dp[i - 1][j] > dp[i][j - 1]) {
        traceBack_1(i - 1, j, X, Y, dp);
    } else {
        traceBack_1(i, j - 1, X, Y, dp);
    }
}

/**
* B[i][j] = 1 , 两个数相等
* B[i][j] = 2 , 对应lcs算法里的第二种
* B[i][j] = 3 , 对应lcs算法里的第三种
*/
void traceBack(int i, int j, char *X, int **B) {
    if (i == 0 || j == 0) {
        return;
    }
    // 两个数相等, 则此数是公共子序列中的一个
    if (B[i][j] == 1) {
        traceBack(i - 1, j - 1, X, B);
        cout << X[i] << ' ';
    } else if (B[i][j] == 2) {
        // 是第二种情况, 往前找x==y的情况
        traceBack(i - 1, j, X, B);
    } else {
        // 是第三种情况, 往前找x==y的情况
        traceBack(i, j - 1, X, B);
    }
}

void printArray(int **a, int n) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    const int MAX_SIZE = 101; // 定义字符数组的最大长度，这里是101因为下标从1开始，加上一个额外的字符位置
    char a[MAX_SIZE], b[MAX_SIZE]; // 分配内存给字符数组
    cin.getline(a + 1, MAX_SIZE); // 注意下标从1开始
    cin.getline(b + 1, MAX_SIZE); // 注意下标从1开始

    int lena = strlen(a + 1); // 实际字符串长度从1开始
    int lenb = strlen(b + 1); // 实际字符串长度从1开始

    int **dp = new int *[lena + 1];
    int **B = new int *[lena + 1];
    for (int i = 0; i <= lena; ++i) {
        dp[i] = new int[lenb + 1];
        B[i] = new int[lenb + 1];
    }

    lcs(a, b, dp, lena, lenb, B);
    cout << "length: " << dp[lena][lenb] << endl;
    cout << "Longest Common Subsequence: ";
    traceBack(lena, lenb, a, B);
    cout << endl;

    // 释放动态分配的内存
    for (int i = 0; i <= lena; ++i) {
        delete[] dp[i];
    }
    delete[] dp;
    return 0;
}