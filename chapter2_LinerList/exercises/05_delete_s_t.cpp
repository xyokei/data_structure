//
// Created by AutumnSigni on 2023/8/1.
//
#include <iostream>
#include "liner_list_util.h"

using namespace std;

/**
 * 顺序表删除
 * 删除在给定值s到t之间
 * @param list
 * @return
 */
bool delete_s_x(SqList &list, int s, int t) {
    if (list.length < 1) return false;
    //从03 的方法学来的

    int k = 0;
    for (int i = 0; i < list.length; ++i) {
        if (list.data[i] < s || list.data[i] > t) {
            list.data[k++] = list.data[i];
        }
    }
    list.length = k;
    return true;
}

int main() {
    SqList list;
    initList(list);
    int *arr = random(10, 100);
    for (int i = 1; i <= 10; ++i) {
        if(i%3==0){
            insertList(list, i, 20+i);
            continue;
        }
        insertList(list, i, *(arr + i - 1));
    }

    printList(list);
    delete_s_x(list,20,30);
    printList(list);
    delete[] arr; //释放
}