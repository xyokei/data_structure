//
// Created by AutumnSigni on 2023/8/1.
//

#include <iostream>
#include "liner_list_util.h"

using namespace std;

/* 删除顺序表最小值 （唯一）
 *
 */

int delete_min_value(SqList &list) {

    if (list.length == 0) return -1;
    int min_value = list.data[0];
    int index = 0;

    for (int i = 1; i < list.length; ++i) {
        if (min_value > list.data[i]) {
            min_value = list.data[i]; //遍历获取最下值
            index = i;              //记录最小值下标
        }
    }
    list.data[index] = list.data[list.length - 1]; //最后一个值赋给删除位置
    list.length--;
    return min_value;
}//思想 和 答案一样，就不写答案了

int main() {
    SqList list;
    initList(list);
    int *arr = random(20, 100);
    for (int i = 1; i <= 20; ++i) {
        insertList(list, i, *(arr + i - 1));
    }

    printList(list);
    cout << "最小值：" << delete_min_value(list) << endl;
    printList(list);
    delete[] arr; //释放
}
