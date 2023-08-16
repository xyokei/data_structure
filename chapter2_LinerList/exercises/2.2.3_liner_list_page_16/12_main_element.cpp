//
// Created by AutumnSigni on 2023/8/4.
//

//寻找主元素
#include "liner_list_util.h"
#include "algorithm"
#include <chrono>
#include <thread>

using namespace std;

/**
 * 算法思想胜在简单
 * 利用hash数组，下标表述元素值，数组值表示出现个数
 * 时间复杂度O(n) 空间 O(n)
 * @param list
 * @return
 */
int main_element(SqList list) {
    int arr[list.length];
    for (int i = 0; i < list.length; ++i) {
        arr[i] = 0;
    }
    for (int i = 0; i < list.length; ++i) {
        arr[list.data[i]]++;
    }

    for (int i = 0; i < list.length; ++i) {
        if (arr[i] > list.length / 2) return i;
    }
    return -1;
}

/**
 * 咋一看没看懂，debug试试
 *
 * 思想，如果一个元素为主元素，那么该元素必将占据数组长度一半以上位置
 * 候选主元素，若count>0 则 有两种可能
 *                         一种是 count = 1  即最后一个元素
 *                         一种是 count > 1  说明该元素重复出现
 * 哇，这个算法思想太难理解了 不想了
 * @param list
 * @return
 */
int main_element_answer(int a[], int len) {
    int c, count = 1;
    c = a[0];
    for (int j = 0; j < len; ++j) {
        if (a[j] == c) {
            count++;
        } else {
            if (count > 0) {
                count--;
            } else {
                c = a[j];
                count++;
            }
        }
    }
    if (count>0){
        count = 0;
        for (int i = 0; i < len; ++i) {
            if (a[i]==c){
                count++;
            }
        }
    }
    if (count>len/2) return c;
    return -1;
}

int main() {
    SqList list;
    initList(list);
    int *arr = random(6, 6);
    sort(arr, arr + 3);
    for (int i = 1; i <= 3; ++i) {
        insertList(list, i, *(arr + i - 1));
    }
    insertList(list, 4, 3);
    insertList(list, 4, 3);
    insertList(list, 4, 3);
    printList(list);
    int main_v = main_element(list);
    cout << "主元素：" << main_v << endl;
    delete[] arr; //释放

    int arr1[7] ={0,5,0,5,0,3,0,};
}