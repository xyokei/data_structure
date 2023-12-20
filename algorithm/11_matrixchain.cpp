//
// Created by AutumnSigni on 2023/10/17.
//

// 动态规划
// 矩阵连乘问题

/**
* 矩阵连乘顺序影响其所进行的乘法次数，乘法次数决定了时间大小
 * 目的：找最优的乘法顺序
 * 穷举搜索法不写了，就两个for
 * 1.找最优解结构：设 Ai一直乘到Aj ->A[i:j]
 *   A[i:j] 的最小计算次数 = a[i:k]的最小次数+ a[k:j]的最小次数 +A{K-1}A{K}A{K+1} k从 i~j 枚举
 *   递归式就这个，i=j就是递归边界
 *   关于证明：一般用数学归纳法 或反证法，
 * 2.自底向上求最优解，
 *   此类非常典型，记录问题规模为1 的所有值
 *                根据问题规模1 计算问题规模2的所有值
 *                ...一直计算到规模为n的所有值
 *  最后 dp[1][n]就是最后的结果
 * 前置知识：矩阵相乘 mxn nxs，两个矩阵相乘的次数 就矩阵m*n*s
 * 时间复杂度 O(n^3)
 * 空间复杂度 O(n^2)
 *
*/
#include <iostream>

using namespace std;

/**
 *
 * @param p 矩阵维数即矩阵的列数，p[1] 就是第一个矩阵的列数，也是第二个矩阵的行数
 * @param n 矩阵个数
 * @param m 最优解值
 * @param s 最优解结构
 */
void matrixChain(const int *p, int n, int **m, int **s) {
    for (int i = 1; i <=n; ++i) {
        m[i][i] = 0;//一个矩阵不需要计算，次数0
    }
    // 规模为2开始求最优解 即两两矩阵相乘次数
    // 规模为3, ... 规模一直到n
    for (int r = 2; r <= n; ++r) {
        // 两个矩阵的组合如 ABCD -> AB BC CD
        // 三个矩阵的组合-> ABC BCD 个数: r个矩阵相乘 的话总共有 n-r+1 个不同的组合
        // 对每个组合都要进行计算
        for (int i = 1; i <= n - r + 1; ++i) {
            //j 就是当前r个矩阵相乘，最后一个要乘的矩阵下标
            //如当前2个矩阵相乘 下标就是2
            int j = i + r - 1;
            //举个例子：3阵相乘BCD初始默认第一个最优即 B * CD,将CD看成一个整体
            // i = 2时 BCD  m[2][4] = m[3][4] + p[1]*p[2]*p[4]
            // p[1]即B的行数 p[2]即B的列数p[4]即CD的列数 这个不好理解需要矩阵的前置知识
            m[i][j] = m[i + 1][j] + p[i - 1] * p[i] * p[j];//设定默认值，就是假定此时k=1时分割最小
            s[i][j] = i;//即在i~j个矩阵中以i分界拆成两个矩阵
            for (int k = i + 1; k < j; ++k) { //枚举开始，因为k=1已经设定初值，直接从下一个枚举
                int t = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j]; //同上
                if (t < m[i][j]) { //更小，更新状态方程
                    m[i][j] = t;  //更新最优解值
                    s[i][j] = k;  //最优解划分位置
                }
            }
        }
    }
}

/**
 * 构造最优解
 * @param i
 * @param j
 * @param s
 */
void traceBack(int i, int j, int **s) { //初始 i 矩阵第一个位置，j矩阵最后一个位置
    if (i == j) {
        return;
    }
    traceBack(i, s[i][j], s); // 此时s[i][j]表示将 矩阵分成两个矩阵的位置 递归左边矩阵的最优解
    traceBack(s[i][j] + 1, j, s); //递归拆分的右面矩阵最优解
    cout << i << ',' << s[i][j];
    cout << "and" << s[i][j] + 1 << "," << j << endl;
}

void printArray(int **a, int n) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout<<a[i][j]<<"\t";
        }
        cout<<endl;
    }
}

void initArray(int **a,int n){
    for (int i = 0; i <= n; ++i) {
        a[i] = new int[n + 1];
    }
    for (int i = 0; i <= n; ++i) {
        for (int j = 1; j <=n; ++j) {
            a[i][j]=0;
        }
    }
}
int main() {
    int n = 6;
    // 30是第一个矩阵的行数，35是第一个矩阵的列数即维数也是第二个矩阵的行数
    int p[7] = {30, 35, 15, 5, 10, 20, 25};
    int **m= new int *[n+1];//第0行第0列不用
    int **s= new int *[n+1];
    // 初始化数组，二维数组必须初始化
    initArray(m,n+1);
    initArray(s,n+1);

    matrixChain(p, n, m, s);

    printArray(m, n);
    cout<<endl;
    printArray(s, n);
    traceBack(1, n, s);

    // 释放内存
    for (int i = 0; i <= n; ++i) {
        delete[] m[i];
        delete[] s[i];
    }
    delete[] m;
    delete[] s;
    return 0;
}