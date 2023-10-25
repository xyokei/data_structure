//
// Created by AutumnSigni on 2023/10/24.
//

// 01 背包回溯法
// 同 21题装船问题类似

/**
* 解法
 * 约束条件：容量不超过c
 * 限界函数 当前物品处理后，后续物品所有价值之和都没有之前解集的价值高，剪掉
*/
#include <iostream>
#include <vector>

using namespace std;
int n = 4;//物品个数
int bestp = 0;
int *bestX = new int[n + 1]; //物品选择
int *x = new int[n + 1];//当前物品选择
int cp = 0;// 当前解的价值
int cw = 0;//当前解选择的物品总重量
int p[5] = {0, 3, 6, 9, 7};//当前解选择物品的价值
int c = 5;//背包容量
int w[5] = {0, 2, 3, 4, 2};//物品对应的重量 ，下标从1开始

// 书上这个方法不行，问题看注释,优化看另一个25
int bound(int i) {
    int cleft = c - cw; //当前剩余的容量
    int b = cp;
    // 需要排序？不排序怎么按单位价值递减装入呢？不然就是错的
    while (i <= n && w[i] <= cleft) {
        cleft -= w[i];
        b += p[i];
        i++;
    }
    if (i <= n) {
        // 上界 总是要比实际的要大，所以取单位价值量让背包全满，实际是不可能的
        // 为了保证正确性
        b += p[i] / w[i] * cleft;
    }
    return b;
}

void backTrack_01(int i) {
    if (i > n) {
        if (cp>bestp){
            bestp = cp;
        }
        return;
    }
    // 选择第i个物品
    if (cw + w[i] <= c) {
        cw += w[i];
        cp += p[i];
        backTrack_01(i + 1);
        cw -= w[i];
        cp -= p[i];
    }
    //写到这停止 上面就相当于暴力解了2^n-1
    //此时回溯到i 开始走右分支，即不选i 准备进行i+1 判断右边能不能走，不能走就继续往上回溯
    // 只要剩余物品价值存在比之前解的价值大的就继续执行
    if (bound(i + 1) > bestp) { //剪枝
        backTrack_01(i + 1);
    }
}
int main(){
    // 对物品进行单位价值降序排列
    backTrack_01(1);
    cout<<bestp;

};