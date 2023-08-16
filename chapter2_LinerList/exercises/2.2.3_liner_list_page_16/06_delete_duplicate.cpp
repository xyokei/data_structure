//
// Created by AutumnSigni on 2023/8/1.
//
#include <iostream>
#include "liner_list_util.h"
#include "algorithm"

using namespace std;

/**
 * 有序顺序表
 * 删除其值重复的数据
 *  方法还是 第3题的方法
 *  我的方法太傻了，还要创建hash表，一个字，不想写
 * @param list
 * @return
 */
bool delete_duplicate(SqList &list) {
    if (list.length < 1) return false;

    int k = 0;
    for (int i = 1; i < list.length; ++i) {
        if (list.data[i] != list.data[k]) {
            list.data[++k] = list.data[i];
        }
    }
    list.length = k + 1; //不同地方，因为是++k,k为下标，不是长度
    return true;
}

/**
 * 无序表试试
 * @param list 
 * @return 
 */
bool delete_duplicate_nosort(SqList &list) {
    if (list.length < 1) return false;
    int max = list.data[0]; //设定最大值，为了建y=x的hash表
    for (int i = 1; i < list.length; ++i) {
        if (max < list.data[i]) {
            max = list.data[i];
        }
    }
    bool arr[max + 1]; //建hash表
    for (int i = 0; i < list.length; ++i) {
        arr[list.data[i]] = true; //出现元素对应下标 设为true
    }
    int k =0;
    for (int i = 0; i < list.length; ++i) {
        if (arr[list.data[i]]){  //还未添加到表中
            list.data[k++]=list.data[i];
            arr[list.data[i]]=false; //该元素已添加设 为false 不再添加
        }
    }
    list.length = k;
    return true;
}

int main() {
    SqList list,list_nosort;
    initList(list);
    initList(list_nosort);
    /*
    int *arr = random(10, 100);
    // test data
    *(arr + 10) = 22;
    *(arr + 11) = 22;
    *(arr + 12) = 33;
    *(arr + 13) = 33;

    sort(arr, arr + 14); //此句+14 与本来就只有10的内存冲突导致内存泄漏错误代码 exit code -1073740940 (0xC0000374)
     //或许要重新思考 数组指针了
     */
    int *arr1 = random(10, 100);
    int arr[14];
    for (int i = 0; i < 10; ++i) {
        arr[i] = *(arr1 + i);
    }
    arr[10]=22;
    arr[11]=22;
    arr[12]=33;
    arr[13]=33;
    for (int i = 1; i <= 14; ++i) {
        insertList(list, i, arr[i-1]);
        if (i<=10){
            insertList(list_nosort, i, arr[i-1]);
        }
    }
    // test data
    insertList(list_nosort,2,22);
    insertList(list_nosort,6,22);
    insertList(list_nosort,9,22);


    printList(list);
    delete_duplicate(list);
    printList(list);

    cout<<"无序表测试："<<endl;
    printList(list_nosort);
    delete_duplicate_nosort(list_nosort);
    printList(list_nosort);
    return 0;
}