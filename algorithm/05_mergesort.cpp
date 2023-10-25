//
// Created by AutumnSigni on 2023/10/14.
//

// 思想：将若干个有序序列进行合并，直至合并成一个有序序列

//分治思想 先分再治
//分 ->mergeSort 治->并 merge
#include <iostream>
#include "int_random.h"

using namespace std;

/**
 *
 * @param a 数组
 * @param l  l~mid
 * @param mid 把数组分成两个数组
 * @param r  mid+1~l
 */
void merge(int *a, int l, int mid, int r) {
    //i 是第一个数组的左 j是第二个数组的左
    int i = l, j = mid + 1, k = 0;

    int b[r - l + 1]; // 个数 = 右 - 左 + 1
    // mid 是第一个数组的右，r是第二个数组的右
    while (i <= mid && j <= r) {
        // 将较小的数据依次放入数组b中
        if (a[i] <= a[j]) b[k++] = a[i++];
        else b[k++] = a[j++];
    }
    // 第一个数组还有数据未处理
    while (i <= mid) b[k++] = a[i++];
    // 第二个数组还有数据未处理
    while (j <= r) b[k++] = a[j++];
    // 将临时存放的数据复制到数组a中
    for (int m = 0; m < k; ++m) {
        a[l + m] = b[m];//因为b数组下标从0开始
    }
}

/**
 *
 * @param a 数组
 * @param l 要排序的左下标
 * @param r 要排序的右下标
 */
void mergeSort(int *a, int l, int r) {
    if (l < r) {
        int mid = (l + r) / 2;//2路归并排序
        mergeSort(a, l, mid); //分
        mergeSort(a, mid + 1, r); //分
        merge(a, l, mid, r); //治
    }
}

int main() {
    int *a = random(10, 60);
    for (int i = 0; i < 10; ++i) {
        cout << a[i] << ' ';
    }
    cout << endl;
    mergeSort(a, 0, 9);
    for (int i = 0; i < 10; ++i) {
        cout << a[i] << ' ';
    }
    cout << endl;
}