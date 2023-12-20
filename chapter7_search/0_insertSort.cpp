//
// Created by AutumnSigni on 2023/11/5.
//

// 直接插入排序
/** 思想: 要排序 0~n-1
 *   1.排序 k~n-1，k从1开始，0~k-1已经有序 初始a[0]就一个元素故有序
 *   2.处理 a[k] ,设定暂存值temp = a[k]
 *       遍历 i 属于k-1~0，i--
 *          if a[i]>a[k] 则 a[i+1]=a[i] //后移一位
 *          else break;
 *       i+1 就是a[k]所在位置a[i] =temp;
 */
#include <iostream>
#include <vector>

void insertionSort(std::vector<int>& arr) {
    int n = arr.size();

    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        // 移动已排序部分中比key大的元素
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }

        // 插入key到正确的位置
        arr[j + 1] = key;
    }
}


void binaryInsertionSort(std::vector<int>& arr) {
    int n = arr.size();

    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        // 使用二分查找找到插入位置
        int low=0,high = i-1;
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == key) {
                high = mid; //有重复元素时处理
                break; // 如果找到 key，则返回 key 在数组中的位置
            } else if (arr[mid] < key) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        // 移动已排序部分中比key大的元素
        // 当数据没有重复元素时算出的 high low是一样
        while (j >= high) {
            arr[j + 1] = arr[j];
            --j;
        }

        // 插入key到正确的位置
        arr[j + 1] = key;
    }
}