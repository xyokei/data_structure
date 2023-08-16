//
// Created by AutumnSigni on 2023/8/16.
// 给定三元组 ，寻找其中最小的举例
// 顺序表存储且表元素升序

#include "liner_list_util.h"
#include "algorithm"
#include <chrono>
#include <thread>


bool min_compare(int a, int b, int c) {
    if (a <= b && a <= c) return true;
    return false;
}

/**
 * 有算法思想
 * 设 s1 取 a ,s2 取 b ,s3 取c
 * 不放设 a<b<c
 * |a-b| +|a-c|+|b-c|
 * 取绝对值 就是 2(c-a) 也就是最小值与最大值距离的2倍
 * 与中间取值无关
 *
 * 若要距离最小，找最小值，最大值
 *
 * 算法描述：
 * d_min数组记录 三元组最小距离
 * 设定i j k 循环
 *      分别计算3个距离，若d<d_min 更新d_min
 *      因为表是升序的，找三个中的最小值对应的i j k
 *      让找到对应的 i 或 j 或 k +1
 *
 * @param s1
 * @param s2
 * @param s3
 */
int triad_min_distance(SqList s1, SqList s2, SqList s3,int a[]) {
    int i = 0, j = 0, k = 0;
    int d_min = INT_FAST16_MAX;
    int d;
    while (i < s1.length && j < s1.length && k < s1.length) {
        d = abs(s1.data[i] - s2.data[j]) + abs(s1.data[i] - s3.data[k]) + abs(s2.data[j] - s3.data[k]);
        if (d < d_min){
            d_min = d;
            a[0] = s1.data[i];
            a[1] = s2.data[j];
            a[2] = s3.data[k];
        }
        if (min_compare(s1.data[i], s2.data[j], s3.data[k])) i++;
        if (min_compare(s2.data[j], s1.data[i], s3.data[k])) j++;
        else k++;
    }
    return d_min;
}

int main() {
    SqList s1, s2, s3;
    initList(s1);
    initList(s2);
    initList(s3);
    int *arr = random(6, -5,6);
    sort(arr, arr + 6);
    for (int i = 1; i <= 6; ++i) {
        insertList(s1, i, *(arr + i - 1));
    }

    this_thread::sleep_until(chrono::system_clock::now() + 1s);

    int *arr1 = random(6, -3,8);
    sort(arr1, arr1 + 6);
    for (int i = 1; i <= 6; ++i) {
        insertList(s2, i, *(arr1 + i - 1));
    }

    this_thread::sleep_until(chrono::system_clock::now() + 1s);

    int *arr2 = random(6, -10,10);
    sort(arr2, arr2 + 6);
    for (int i = 1; i <= 6; ++i) {
        insertList(s3, i, *(arr2 + i - 1));
    }
    printList(s1);
    printList(s2);
    printList(s3);
    int a[3];
    int d_min = triad_min_distance(s1,s2,s3,a);
    cout<<"最小距离为："<<d_min<<endl;
    cout<<"元组为：["<<a[0]<<","<<a[1]<<","<<a[2]<<"]"<<endl;
}







