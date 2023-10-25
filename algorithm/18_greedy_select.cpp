//
// Created by AutumnSigni on 2023/10/23.
//

// 贪心算法 活动安排问题
/**
* 给定n个活动，每个活动有开始结束时间，这n个活动都在同一个地方开
 * 问，怎么安排最多活动
*/

#include <iostream>
using namespace std;
/**
 * 贪心策略：按结束时间最早选择 就可以最多 ，至于证明？
 * 实现：要按时间最早，必须排序，
 * @param n 活动个数
 * @param s s[i] 活动i 的开始时间
 * @param f f[i] 活动i 的结束时间
 * @param a a[i] 活动i true 选，false 不选
 */
int greedySelect(int n, const int *s, const int *f, bool *a) {
    // 关于排序的想法，可能要改下结构，定义结构体数组 三个成员 s f i表示是第几个活动
    // 按照 f进行 快速排序 O(nlogn)
    int count = 1;
    int j = 1;//控制选择活动下标的结束时间
    a[1] = true;
    for (int i = 2; i <= n; ++i) {
        if (s[i] >= f[j]) {
            a[i] = true;
            j = i;
            count++;
        } else {
            a[i] = false;
        }
    }
    return count;
}
void printArray(bool *a, int row) {
    for (int i = 1; i <=row; ++i) { //下标从1开始
            cout << a[i]<< "\t";
    }
}
int main() {
    int n = 9;
    int s[10] = {0, 8, 9, 11, 8, 12, 15, 16, 18, 20};
    int f[10] = {0,10,12,14,15,16,17,18,21,23};
    bool a[10] ={false};
    int count = greedySelect(n,s,f,a);
    printArray(a,n);
    cout<<endl<<count;
}