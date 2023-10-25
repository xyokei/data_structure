//
// Created by AutumnSigni on 2023/10/23.
//

// 最优装载问题
/**
*  问题：重量为c ，集装箱为i的重量是 w[i] 体积不限，装尽可能多的箱子
*/

#include <iostream>
#include <algorithm>

using namespace std;

struct Container {
    int w;
    int index;

    // 有参构造
    // Container(int _w, int _index) : w(_w), index(_index) {}

    //操作符 < 号重载
    bool operator<(const Container &other) const {
        return w < other.w;
    }
};

/**
 * 贪心策略 ： 优先装重量轻的
 * @param x 最优解结构 1 选 0 不选
 * @param w 第i个箱子重量
 * @param c 容量
 * @param n 箱子个数
 */
void loadShip(int *x, int *w, int c, int n) {
    vector<Container> t;//为了重新排序，使用可变数组
    for (int i = 1; i <= n; ++i) {
        t.push_back({w[i], i});
    }
    // 时间复杂度 O(nlogn)
    sort(t.begin(), t.end()); //按照 w 降序排列此处重载了<的运算符
    for (int i = 1; i <= n; ++i) {
        x[i] = 0;   //初始化，全不选
    }
    // t的下标是从0开始的
    for (int i = 0; i < n && t[i].w <= c; ++i) {
        x[t[i].index] = 1; //对应下标是选的
        c -= t[i].w;
    }
}
int main() {
    int c = 10; // 轮船的重量限制
    int weights[] = {0, 3, 2, 5, 4}; // 各个集装箱的重量，下标从1开始
    int n = 4; // 集装箱数量
    int x[n+1];
    loadShip(x, weights, c, n);
    cout << "装载的集装箱编号：";
    for (int i = 1; i <=n ; ++i) {
        cout<<x[i]<<" ";
    }
    cout << endl;
    return 0;
}