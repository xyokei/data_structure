//
// Created by AutumnSigni on 2023/8/2.
//

#include "liner_list_util.h"
#include "algorithm"
#include <chrono>
#include <thread>

using namespace std;

/**
 * 时间复杂度 o(max{n,m}) [修正：O(n)
 * 空间复杂度 o(m+n)      [O(2n)
 * 不如答案的算法性能高
 * 漏了个条件 两个序列是等长的
 * @param a
 * @param b
 * @param v
 */
void search_median(SqList a, SqList b, int &v) {
    SqList c;
    initList(c);
    int i = 0, j = 0;
    while (i < a.length && j < b.length) {
        if (a.data[i] <= b.data[j]) {           //主体合并是一样的 只不过用的while
            c.data[c.length++] = a.data[i++];
        } else {
            c.data[c.length++] = b.data[j++];
        }
    }
    while (i < a.length) {
        c.data[c.length++] = a.data[i++];
    }
    while (j < b.length) {
        c.data[c.length++] = b.data[j++];
    }
    v = c.data[(c.length + 1) / 2];
}

/**
 * 分别求两个数组的中位数 记为 aa bb
 * 若 aa=bb 则直接返回
 * 若aa<bb，舍弃 a 数组较小的，舍弃b 数组较大的 ,舍弃的长度必须一致
 * 若aa>bb，舍弃 a 数组较大的，舍弃b 数组较小的 ,舍弃的长度必须一致
 * 重复 直到 两个序列中只有一个元素，则返回较大的那个
 * 时间复杂度 O(log_n) 空间 O(1)
 * @param a
 * @param b
 * @param len
 * @return
 */
int search_median_answer(const int a[], const int b[], int len) {
    int ma, mb;
    int a_from = 0, a_to = len - 1;
    int b_from = 0, b_to = len - 1;
    while (a_from != a_to) {
        ma = (a_from + a_to) / 2; //ma 数组中间下标 数组长度奇数为中间值，偶数为2者前一个
        mb = (b_from + b_to) / 2; //mb 数组中间下标 数组长度奇数为中间值，偶数为2者前一个
        if (a[ma] == b[mb]) {
            return a[ma];
        }
        // if (a[ma] < b[mb]) { //答案分奇偶的，感觉我这个也行啊
        //     a_from = ma;
        //     b_to = mb + a_to - ma;
        // } else {
        //     b_from = mb;
        //     a_to = ma + b_to - mb;
        // }

        //必须分奇偶，否则当最后数组只有2个长度的时候，下列代码将陷入死循环
        // if (a[ma] < b[mb]) {
        //     a_from = ma;
        //     b_to = mb + a_to - ma;

        if (a[ma] < b[mb]) {
            //舍弃ma 左边，mb右边
            if ((a_from - a_to + 1) % 2 == 0) {//求元素个数 为偶数
                a_from = ma + 1;
                b_to = mb;
            } else {
                a_from = ma;
                b_to = mb;
            }
        }
        else{
            //舍弃ma 右边，mb左边
            if ((b_from - b_to + 1) % 2 == 0) {//求元素个数 为偶数
                b_from = mb + 1;
                a_to = ma;
            } else {
                b_from = mb;
                a_to = ma;
            }
        }

    }


}

int main() {
    SqList list, list2;
    initList(list);
    initList(list2);
    int *arr = random(5, 100);
    sort(arr, arr + 5);
    for (int i = 1; i <= 5; ++i) {
        insertList(list, i, *(arr + i - 1));
    }
    this_thread::sleep_until(chrono::system_clock::now() + 1s);

    int *arr2 = random(5, 100);
    sort(arr2, arr2 + 5);
    for (int i = 1; i <= 5; ++i) {
        insertList(list2, i, *(arr2 + i - 1));
    }
    printList(list);
    printList(list2);
    int v;
    search_median(list, list2, v);
    cout << "中位数：" << v << endl;
    delete[] arr; //释放
    delete[] arr2; //释放
}