//
// Created by AutumnSigni on 2023/12/11.
//
#include <iostream>
#include <vector>

using namespace std;

// 获取数组中最大值
int getMax(const vector<int>& arr) {
    int max = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// 对数组按照指定的位数进行计数排序
void countSort(vector<int>& arr, int exp) {
    const int n = arr.size();
    vector<int> output(n);
    vector<int> count(10, 0);

    // 计算每个数字出现的次数
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // 将 count 转换为累积次数数组
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // 从后向前遍历原数组，根据 count 数组将元素放到输出数组中
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // 将输出数组复制回原数组
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// 基数排序主函数
void radixSort(vector<int>& arr) {
    int max = getMax(arr);

    // 从最低位到最高位进行基数排序
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countSort(arr, exp);
    }
}

int main() {
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};

    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    radixSort(arr);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
