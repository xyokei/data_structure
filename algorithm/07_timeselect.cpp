//
// Created by AutumnSigni on 2023/10/16.
//

/**
* 线性时间选择
 * 给定线性集合 n个元素，和一个整数k，找出第k小的元素
 * 用快排的思想
 * 1. 选首元素元素做为基准 pivot
 * 2. 通过一趟排序 将表分成两个表 1~m pivot m~n,pivot
 * 3. 若 确定位置 == k 返回 pivot
 *    若 确定位置 < k 则在 右表查找 重复12操作
 *    若 确定位置 > k 则在 左表查找 重复12操作
 */

#include <iostream>
#include "int_random.h"

using namespace std;
//？感觉没问题啊，怎么有个bug 运行一次是对的，运行第二次就不正确呢？

/**
 *
 * @param a
 * @param i 左界
 * @param j 右界
 * @return
 */
int partition(int a[], int i, int j) {
    int pivot = a[i]; //通常取首元素
    // 此循环最终的 i=j 此时i所在的位置就是pivot的最终位置
    while (i < j) {
        //当前第j个元素 在pivot右边 并且其值比 pivot大 说明其所在位置满足条件，直接进行下一个
        while (i < j && a[j] >= pivot) j--;
        //此时 说明第j个元素已经比pivot小了
        a[i] = a[j]; //换位
        //当前第i个元素 在pivot左边 并且其值比 pivot小 说明其所在位置满足条件，直接进行下一个
        while (i < j && a[i] <= pivot) i++;
        a[j] = a[i]; // 换位
    }
    // 将基准放在最终位置上
    a[i] = pivot;
    return i;
}

/**
 * @param a
 * @param l 当前表的左界
 * @param r 当前表的右界
 */
int timeSelect(int a[], int l, int r, int k) {
    if (l < r) {//直至 划分的表长为1 或空结束
        int p = partition(a, l, r);//p的位置就是p最终排序的位置
        if (p == k) return a[p];
        //确定位置 < k 则在 右表查找 重复12操作
        if (p < k) {
            timeSelect(a, p + 1, r, k);
        }
        //若 确定位置 > k 则在 左表查找 重复12操作
        if (p > k) {
            timeSelect(a, l, p - 1, k);
        }
    }
}
int main() {
    int *a = random(10, 60);
    for (int i = 0; i < 10; ++i) {
        cout << a[i] << ' ';
    }
    cout << endl;
    int s = timeSelect(a, 0, 9, 4);//下标从0开始 第4个小的传5
    for (int i = 0; i < 10; ++i) {
        cout << a[i] << ' ';
    }
    cout << endl << s << endl;
}