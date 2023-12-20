//
// Created by AutumnSigni on 2023/11/5.
//

/**
* 思想：交换
 * 1.元素 0~n-1 ,设定k=0，end = n-1,swap_flag =true
 * 2.依次比较a[k] a[k+1] ，将swap_flag =false
 *     if a[k+1]<a[k] 交换 将swap_flag 置true
 * 3. k = end时，一趟冒泡结束，end--,k=0重新再来一次
 * 4，终止条件 此次swap_flag == false;即有序
*/
#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        // 标志变量，用于判断本轮是否有元素交换，如果没有则数组已经有序
        bool swapped = false;

        // 通过相邻元素比较和交换，将较大元素逐渐交换到数组末尾
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                // 如果前面的元素大于后面的元素，交换它们的位置
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // 如果本轮没有元素交换，说明数组已经有序，可以提前结束排序
        if (!swapped) {
            break;
        }
    }
}
// 双向冒泡排序
void cocktailSort(int arr[], int n) {
    bool swapped = true;
    int start = 0;
    int end = n - 1;

    while (swapped) {
        // 从左向右遍历，将较大元素交换到右边
        swapped = false;
        for (int i = start; i < end; ++i) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }

        // 如果没有元素交换，说明序列已经有序
        if (!swapped) {
            break;
        }

        // 从右向左遍历，将较小元素交换到左边
        swapped = false;
        --end;
        for (int i = end - 1; i >= start; --i) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }

        // 更新左指针
        ++start;
    }
}
int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "排序前的数组: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    bubbleSort(arr, n);

    cout << "排序后的数组: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
