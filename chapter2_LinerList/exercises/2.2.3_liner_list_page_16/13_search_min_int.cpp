//
// Created by AutumnSigni on 2023/8/4.
//

//找出未出现的最小正整数
#include "liner_list_util.h"
#include "algorithm"

/**
 * hash表通杀 大部分题目啊
 * 空间复杂度 o(数组中的最大值)
 * 时间复杂度 o(max{n+数组中的最大值})
 * 感觉性能不行，试试别的
 * @param a
 * @param len
 * @return
 */
int search_min_int(int a[], int len) {
    // 算法改进之处
    // 限定max = len
    // 因为是返回最小整数值
    //  故，当a[]正好1~len，则返回 n+1
    // 若 max 在 len 之外，则最小正整数，一定取在 1~len 之间
    // 这个优化思想很有用，就不写代码了，应该牢记
    int max = -1;
    for (int i = 0; i < len; ++i) {
        if (max < a[i]) {
            max = a[i];
        }
    }
    if (max < 1) return 1;
    bool b[max + 1];
    // for (int i = 0; i < max; ++i) {
    //     b[max] = false;
    // }
    for (int i = 0; i < len; ++i) {
        if (a[i] > 0) {
            b[a[i]] = true;
        }
    }
    for (int i = 1; i < max; ++i) {
        if (!b[i])return i;
    }
    return max + 1;
}

// 如果得到一个有序 且 无重复的数组
// 定义自然数 i 遍历 j,若 i!=a[j] 则return i; 最后return i + 1

// 解决有序 最好的排序算法 需要o(nlog_n)复杂度
int search_min_int_2(int a[], int len) {
    int j = 0;
    for (int i = 0; i < len; ++i) {
        if (a[i] > 0) {
            a[j] = a[i];

        }
    }
}

int main() {
    int *arr = random(6, -6, 6);
    printArr(arr, 6);
    int v = search_min_int(arr, 6);
    cout << "最小正整数为：" << v;
}