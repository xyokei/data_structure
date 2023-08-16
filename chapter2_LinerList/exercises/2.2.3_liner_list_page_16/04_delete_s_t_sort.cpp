//
// Created by AutumnSigni on 2023/8/1.
//

#include "liner_list_util.h"
#include "algorithm"

using namespace std;

/**
 * 有序顺序表删除
 * 本来我是 3 个for循环的
 * 看了答案觉得我的解法太蠢了
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
    sort(arr,arr+10);
    for (int i = 1; i <= 10; ++i) {
        insertList(list, i, *(arr + i - 1));
    }

    printList(list);
    delete_s_x(list,20,40);
    printList(list);
    delete[] arr; //释放
}