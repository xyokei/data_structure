//
// Created by AutumnSigni on 2023/8/2.
//
#include <iostream>
#include "liner_list_util.h"
#include "algorithm"
#include <ctime>

using namespace std;

void search_x(SqList &list, int x) {
    if (list.length == 0) {
        list.data[++list.length] = x;
        return;
    }

    if (list.data[list.length - 1] < x) { //特殊值单独处理
        insertList(list, list.length + 1, x);
        return;
    }

    for (int i = 0; i < list.length; ++i) {
        if (list.data[i] == x && i != list.length - 1) {
            int temp = list.data[i];  //交换
            list.data[i] = list.data[i + 1];
            list.data[i + 1] = temp;
            return;
        }
        if (x < list.data[i]) { //有比 x 还大的值 意味着总不是最后一位
            insertList(list, i + 1, x); //注意参数是位序，而i是下标
            return;
        }
        // if(x>list.data[i] &&i==list.length-1){
        //     insertList(list,list.length,x);
        // }
    }
}


int main() {
    SqList list;
    initList(list);
    int *arr = random(10, 100);
    sort(arr, arr + 10);
    for (int i = 1; i <= 10; ++i) {
        insertList(list, i, *(arr + i - 1));
    }

    printList(list);
    search_x(list, 0);
    printList(list);
    delete[] arr; //释放
}