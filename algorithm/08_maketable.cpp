//
// Created by AutumnSigni on 2023/10/16.
//

// 循环赛日程表
#include <iostream>
#include <vector>

using namespace std;

/**
 * 要求
 * 1.选手人数n = 2 的整数次幂
 * 2.每个选手必须与其他n-1个选手各赛一次，
 * 3.每个选手一天只能赛一次
 * 4.循环赛进行n-1天
 * 分治思想
 * 1.将选手分成两半，直至只剩一个选手 则不需要排了
 * 2.主副对角线一直复制，这个需要理解下
 * O(nlogn)
*/

int a[100][100];

void copy(int x, int y, int x1, int y1, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            a[x1 + i][y1 + j] = a[x + i][y + j];
        }
    }
}
void makeTable(int x, int y, int n) { //
    if (n > 1) {
        makeTable(x, y, n / 2); //左上角一直分
        makeTable(x + n / 2, y, n / 2);//左下角一直分
        copy(x, y, x + n / 2, y + n / 2, n / 2); //左上表拷贝到右下表
        copy(x + n / 2, y, x, y + n / 2, n / 2);//左下表拷贝到右上表
    }
}

int main() {
    int n;
    cout << "Enter the number of teams: ";
    cin >> n;
    // 初始化第一列 不然没值了
    for (int i = 1; i <= n; ++i) {
        a[i][1]=i;
    }
    makeTable(1,1,n);//下标从1开始
    cout << "Round Robin Schedule:" << endl;
    for (int i = 1; i <=n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout<<a[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}