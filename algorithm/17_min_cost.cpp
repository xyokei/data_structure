//
// Created by AutumnSigni on 2023/10/22.
//
// 游艇租赁问题

/**
*  设定n个游艇出租站1~n 游客可以在出租站租用，并在下游任何站点归还
 *  限制只能从上游往下游
 *  站点i~到站点j的租金为r(i,j)1<=i<j<=n，计算出租站1~n的最小费用
 *
 *  方程
 *  cost[i] 表示第一站到第i站 的最小租金
 *  i =1 cost[i] = 0
 *  i > 1  cost[i] = min(cost[k] + r(k,i))
*/
#include <cstdlib>
#include <iostream>

using namespace std;
int r[5][5];

int min_cost(int n) {
    int cost[n + 1];
    cost[1] = 0;
    int temp;
    for (int i = 2; i <= n; ++i) {
        cost[i] = cost[i - 1] + r[i - 1][i]; //初始值
        for (int k = 2; k <= i; ++k) { //分割点
            temp = cost[k] + r[k][i];
            if (temp<cost[i]){
                cost[i] = temp;
            }
        }
    }
    return cost[n];
}

int main() {
    for (int i = 1; i <= 4; ++i) {
        for (int j = i + 1; j <= 4; ++j) {
            r[i][j] = rand() % 10 + 2;
        }
    }
    for (int i = 1; i <= 4; ++i) {
        for (int j = 1; j <= 4; ++j) {
            cout << r[i][j] << ' ';
        }
        cout << endl;
    }
    int cost = min_cost(4);
    cout<<cost;
}