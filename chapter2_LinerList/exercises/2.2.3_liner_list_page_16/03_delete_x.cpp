//
// Created by AutumnSigni on 2023/8/1.
//
#include <iostream>
#include "liner_list_util.h"

using namespace std;

/* 删除元素
 * 删除所有 值为x 的元素
 * 要求 时间O(n) 空间O(1)
 */
// 没想出来，怎么说都要到达 n*logn

/**
 * 真秒啊
 * 删除后的表必然小于之前的表长
 * 若不等保留 直接赋值
 * 若相等 以下一个不等值覆盖 就达到删除目的了
 * @param list
 * @param x
 * @return
 */
bool delete_x(SqList &list, int x) {
    if (list.length < 1) return false;

    int k = 0;
    for (int i = 0; i < list.length; ++i) {
        if (list.data[i] != x) {
            list.data[k] = list.data[i];
            k++;
        }
    }
    list.length=k;
    return true;
}

int main() {
    SqList list;
    initList(list);
    int *arr = random(10, 100);
    for (int i = 1; i <= 10; ++i) {
        if(i%3==0){
            insertList(list, i, 3);
            continue;
        }
        insertList(list, i, *(arr + i - 1));
    }

    printList(list);
    delete_x(list,3);
    printList(list);
    delete[] arr; //释放
}