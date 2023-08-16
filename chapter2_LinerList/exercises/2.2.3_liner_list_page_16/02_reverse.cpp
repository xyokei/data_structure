//
// Created by AutumnSigni on 2023/8/1.
//

#include <iostream>
#include "liner_list_util.h"

using namespace std;

/* 逆置顺序表
 * 要求 时间O(n) 空间O(1)
 */
void reverse(SqList &list) {
    if (list.length == 0) return;
    int temp;
    int mid = list.length / 2;
    int last = list.length - 1;
    for (int i = 0; i < mid; ++i) {  //长度为奇，5/2 = 2 长度为偶 4/2 =2 为位序，不能<=
        temp = list.data[i];
        list.data[i] = list.data[last - i];
        list.data[last - i] = temp;
    }
}//和答案一样，只不过答案没定 mid 和last 我是为了代码好看

int main() {
    SqList list;
    initList(list);
    int *arr = random(10, 100);
    for (int i = 1; i <= 10; ++i) {
        insertList(list, i, *(arr + i - 1));
    }

    printList(list);
    reverse(list);
    printList(list);
    delete[] arr; //释放
}