//
// Created by AutumnSigni on 2023/10/24.
//
#include <iostream>
#include <vector>
#include <algorithm>

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
// 优化的
struct wp {
    int w; //重量
    int p; //价值
    int i; //下标
    // 关于为什么重载的是<号的原因
    // 虽然重载的是<，但具体实现是降序排列的，
    // c++STL sort函数第三个参数不写的时候，默认是升序排列的，为了代码简洁就明修栈道了
    // 当然可以重载> 只不过此时参数要这样写sort(t.begin,t.end,greater<wp>())
    bool operator<(const wp &other) const {
        return p / w > other.p / other.w;
    }
};

int bound(int i, const vector<wp> wps) {
    int cleft = c - cw; //当前剩余的容量
    int b = cp;
    // 此时对应的已经排序了
    while (i < n && wps[i].w <= cleft) {
        cleft -= wps[i].w;
        b += wps[i].p;
        i++;
    }
    if (i < n) {
        // 上界 总是要比实际的要大，所以取单位价值量让背包全满，实际是不可能的
        // 为了保证正确性
        b += wps[i].p / wps[i].w * cleft;
    }
    return b;
}

void backTrack_01(int i, const vector<wp> &wps) {
    if (i > n - 1) { //wps从0开始
        if (cp > bestp) {
            for (int j = 1; j <= n; ++j) {
                bestX[j] = x[j];
            }
            bestp = cp;
            return;
        }
    }
    // 选择第i个物品
    if (cw + wps[i].w <= c) {
        cw += wps[i].w;
        cp += wps[i].p;
        x[wps[i].i] = 1;//选择当前物品
        backTrack_01(i + 1, wps);
        cw -= wps[i].w;
        cp -= wps[i].p;
        x[wps[i].i] = 0;//不选当前物品
    }
    //写到这停止 上面就相当于暴力解了2^n-1
    //此时回溯到i 开始走右分支，即不选i 准备进行i+1 判断右边能不能走，不能走就继续往上回溯
    // 只要剩余物品价值存在比之前解的价值大的就继续执行
    if (bound(i + 1, wps) > bestp) { //剪枝
        backTrack_01(i + 1, wps);
    }
}

int main() {
    // 数组初始化,发现每次不初始化，总是乱七八糟的值
    for (int i = 0; i < n + 1; ++i) {
        bestX[i] = 0;
        x[i] = 0;
    }
    vector<wp> wps;
    // 对物品进行单位价值降序排列
    for (int j = 1; j <= n; ++j) {
        wps.push_back({w[j], p[j], j});
    }
    // 实现降序排列
    sort(wps.begin(), wps.end());
    for (auto &wp: wps) {
        cout << wp.w << ':' << wp.p << ':' << wp.i << '\t';
    }
    cout << endl;
    backTrack_01(0, wps);
    cout << "max value: " << bestp << endl << "select sequence:";
    for (int i = 1; i <= n; ++i) {
        cout << bestX[i] << ' ';
    }
    // 释放动态分配的内存
    delete[] bestX;
    delete[] x;
    return 0;
}