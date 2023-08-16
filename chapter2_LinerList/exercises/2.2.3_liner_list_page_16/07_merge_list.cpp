//
// Created by AutumnSigni on 2023/8/2.
//
#include <iostream>
#include "liner_list_util.h"
#include "algorithm"
#include <chrono>
#include <thread>

using namespace std;

/**
 * 将两个有序表合并成一个有序表
 * 归并排序 子方法
 * @param list
 * @param list2
 * @return
 */
bool merge_list(SqList &list,SqList list2){
    if (list.length==0&&list2.length==0) return false;

    SqList sqList;
    initList(sqList);
    int i,j,k=0;
    for (i = 0,j=0; i < list.length && j<list2.length;) {
        if (list.data[i]<=list2.data[j]){
            sqList.data[k++] =list.data[i++];
        } else{
            sqList.data[k++] =list2.data[j++];
        }
    }
    while (i<list.length){
        sqList.data[k++]=list.data[i++];
    }
    while (j<list2.length){
        sqList.data[k++]=list2.data[j++];
    }
    sqList.length = k;
    list = sqList;
    return true;
}

/**
 * 答案的写法显然要更简洁些
 * @param a
 * @param b
 * @param c
 * @return
 */
bool merge_list_answer(SqList a,SqList b,SqList c){
    if (a.length+b.length>c.MaxSize) return false; //顺序表有个最大值我一直给忘了

    int i =0,j=0,k=0;
    while (i<a.length&&j<b.length){
        if (a.data[i]<=b.data[j]){           //主体合并是一样的 只不过用的while
            c.data[k++] =a.data[i++];
        } else{
            c.data[k++] =b.data[j++];
        }
    }
    while (i<a.length){
        c.data[k++]=a.data[i++];
    }
    while (j<b.length){
        c.data[k++]=b.data[j++];
    }
    c.length = k;
    return true;
}


int main() {
    SqList list,list2;
    initList(list);
    initList(list2);
    int *arr = random(10, 100);
    sort(arr,arr+10);
    for (int i = 1; i <= 10; ++i) {
        insertList(list, i, *(arr + i - 1));
    }
    this_thread::sleep_until(chrono::system_clock::now()+1s);

    int *arr2 = random(12, 100);
    sort(arr2,arr2+12);
    for (int i = 1; i <= 12; ++i) {
        insertList(list2, i, *(arr2 + i - 1));
    }
    printList(list);
    printList(list2);
    merge_list(list,list2);
    printList(list);
    delete[] arr; //释放
    delete[] arr2; //释放
}