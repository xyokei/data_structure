//
// Created by AutumnSigni on 2023/10/25.
//

// 圆排列问题
#include <cmath>

// 解空间是: 排列树
int n = 10;
// 排列情况
int x[10];
// 每个圆的半径
int r[10];
// 当前最小圆排列长度
int min = 0;

void swap(int &a, int &b) {
    a ^= b;
    b ^= a;
    a ^= b;
}
/**
 * 计算当前圆排列的长度
 */
void compute() {
    float low = 0, high = 0;
    for (int i = 1; i <= n; ++i) {
        if (x[i] - r[i] < low) low = x[i] - r[i];
        if (x[i] + r[i] > high) high = x[i] + r[i];
    }
    if (high - low < min) {
        min = high - low;
    }
}

/**
 * 计算当前所选择的圆心横坐标
 * @param t
 * @return
 */
float center(int t) {
    float temp = 0;
    for (int j = 1; j < t; ++j) {
        float value = x[j] + 2.0 * sqrt(r[t] * r[j]);
        if (value > temp) temp = value;
    }
    return temp;
}

void backtrack(int t) {
    if (t > n) {
        compute();
    } else {
        for (int j = t; j <= n; ++j) {
            swap(r[t], r[j]);
            float centerX = center(t);
            if (centerX + r[t] + r[1] < min) {
                x[t] = centerX;
                backtrack(t + 1);
            }
            swap(r[t], r[j]);
        }
    }
}

