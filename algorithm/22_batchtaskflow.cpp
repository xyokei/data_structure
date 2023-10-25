//
// Created by AutumnSigni on 2023/10/23.
//

// 批处理作业调度

/**
 * n 个作业集合 每个作业先由机器1处理，再由机器2处理。作业i需要机器j的处理时间 mij
 *  给点力n个作业 最佳作业调度方案，使其完成时间和最小
 *  解空间：排列树
 *  按套路写
 *      if(i>n) 最底层了
 *           比较当前解 与 最优解
 *           设定最优解
 *       else
 *           计算完成时间之和
 *           可行性约束函数 到当前作业的完成时间为止比最优解还大 ->总是剪掉左分支
 *                        剪掉左分支返回当前结点父结点进入右分支
 *            swap
 *            递归方法
 *            swap
 */
#include <iostream>

using namespace std;

int M[4][3] = {{0, 0, 0},
               {0, 2, 1},
               {0, 3, 1},
               {0, 2, 3}}; //3个作业 在机器1 机器2 上运行的时间，下标都从1开始
int x[4] = {0, 1, 2, 3};//作业编号,下标从1开始
int bestX[4];//最优解结构
int f2[4]; //机器2完成处理时间
int f1 = 0;//机器1完成处理时间
int f = 0;//当前解的完成时间之和
int bestF = INT16_MAX; //当前解之前解的最优解
int n = 3; //作业个数

//交换函数
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
void batchTask(int i) {
    if (i > n) {//最底层结点，i从1开始，n是最后一个，n+1说明后面没了
        if (f < bestF) { //比之前解更优
            bestF = f;//更新最优解
            for (int j = 1; j <= n; ++j) {
                bestX[j] = x[j]; //更新最优解结构
            }
        }
    } else {
        for (int j = i; j <= n; ++j) {
            f1 += M[x[j]][1]; //选择当前作业进行处理，加上当前作业在机器1的时间
            //上一个作业2的完成时间若比f1的完成时间大，用上一个的作业2的完成时间+此时作业在机器2的完成时间
            f2[i] = ((f2[i - 1] > f1) ? f2[i - 1] : f1) + M[x[j]][2];
            f += f2[i];//到目前作业完成的时间之和
            if (f < bestF) { //剪枝
                swap(x[i], x[j]);  //排列写法 参照00算法全排列
                batchTask(i + 1);      // +1别忘了
                swap(x[i], x[j]);
            }
            f1 -= M[x[j]][1]; //回溯
            f -= f2[i];
        }
    }
}

int main() {
    batchTask(1);
    cout << "min work time: " << bestF << endl;
    cout << "work select sequence: ";
    for (int i = 1; i <= n; ++i) {
        cout << bestX[i] << ' ';
    }
}