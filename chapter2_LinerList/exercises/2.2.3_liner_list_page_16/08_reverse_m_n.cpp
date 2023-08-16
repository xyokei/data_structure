//
// Created by AutumnSigni on 2023/8/2.
//

#include <iostream>
#include "liner_list_util.h"
#include "algorithm"
#include <ctime>

using namespace std;

/**
 * 难点，mid值 要 + start,不然只是长度中值，而不是索引中值
 * 参数 对应 的是索引，如果是位序，+1就行，写的时候表明清楚
 * @param arr
 * @param start
 * @param end
 * @return
 */
bool reverse(int arr[], int start, int end) {
    int temp;
    int mid = start + (end - start + 1) / 2; //start + (end - start + 1)/2 不等于 (start + end + 1)/2;
    int k = 0;
    for (int i = start; i < mid; ++i) {
        temp = arr[i];
        arr[i] = arr[end - k];
        arr[end - k] = temp;
        k++;
    }
    return true;
}

/**
 * 觉得答案的写法更好
 * @param arr
 * @param start
 * @param end
 * @return
 */
bool reverse_answer(int arr[], int start, int end) {
    int temp;
    int mid = (end - start + 1) / 2; //start + (end - start + 1)/2 不等于 (start + end + 1)/2;
    for (int i = 0; i < mid; ++i) {
        temp = arr[start + i];
        arr[start + i] = arr[end - i];
        arr[end - i] = temp;
    }
    return true;
}

bool reverse_m_n(int arr[], int len, int m) {

    reverse(arr, 0, m - 1); //传的是下标。不是位序，注意区分
    reverse(arr, m, len - 1);
    reverse(arr, 0, len - 1);

    // test
    // reverse_answer(arr, 0, m - 1);
    // reverse_answer(arr, m, len - 1);
    // reverse_answer(arr, 0, len - 1);
    return true;
}

void printArr(int arr[], int len) {
    cout << "数组长度：" << len << endl;
    for (int i = 0; i < len - 1; ++i) {
        if ((i + 1) % 7 == 0) {
            cout << arr[i] << endl;
            continue;
        }
        cout << arr[i] << "\t";
    }
    cout << arr[len - 1] << endl;
}

int main() {
    SqList list;
    initList(list);
    int *arr = random(21, 100);
    int a[21];
    for (int i = 0; i < 21; ++i) {
        a[i] = *(arr + i);
    }
    printArr(a, 21);
    clock_t start, end;
    start = clock();
    reverse_m_n(a, 21, 7);
    end = clock();
    printArr(a, 21);
    cout << endl << "算法时间: " << (double) (end - start) / CLOCKS_PER_SEC << endl;
    delete[] arr; //释放
}