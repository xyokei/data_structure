//
// Created by AutumnSigni on 2023/10/16.
//
/**
 * 快速排序 分治思想 给定表l  个数1~n ,不稳定，排序算法中平均性能最好
 * 1. 选一个元素，通常选首元素，做为基准 pivot
 * 2. 通过一趟排序 将表分成两个表 1~k pivot k~n,pivot 左边的元素都比pivot小，右边的都比pivot大
 *    此时 pivot的所在位置就是其最终排序所在位置
 *      容易求，给定表中第k大的的数据->后面会写的线性时间选择的算法
 * 3. 对1~k表 k~n表再重复1,2操作 直至 划分的表长为1 或空结束
 */
#include <iostream>
#include "int_random.h"
using namespace std;

/**
 *
 * @param a
 * @param i 左界
 * @param j 右界
 * @return
 */
int partition(int a[], int i, int j) {
    int pivot = a[i]; //通常取首元素
    // 此循环最终的 i=j 此时i所在的位置就是pivot的最终位置
    while (i<j){
        //当前第j个元素 在pivot右边 并且其值比 pivot大 说明其所在位置满足条件，直接进行下一个
        while (i < j && a[j] >= pivot) j--;
        //此时 说明第j个元素已经比pivot小了
        a[i] = a[j]; //换位
        //当前第i个元素 在pivot左边 并且其值比 pivot小 说明其所在位置满足条件，直接进行下一个
        while (i < j && a[i] <= pivot) i++;
        a[j] = a[i]; // 换位
    }
    // 将基准放在最终位置上
    a[i] =pivot;
    return i;
}

/**
 * @param a
 * @param l 当前表的左界
 * @param r 当前表的右界
 */
void quickSort(int a[], int l, int r) {
    if (l < r) {//直至 划分的表长为1 或空结束
        int p = partition(a, l, r);//p的位置就是p最终排序的位置
        quickSort(a, l, p - 1);
        quickSort(a, p + 1, r);
    }

}
int main() {
    int *a = random(10, 60);
    for (int i = 0; i < 10; ++i) {
        cout << a[i] << ' ';
    }
    cout << endl;
    quickSort(a, 0, 9);
    for (int i = 0; i < 10; ++i) {
        cout << a[i] << ' ';
    }
    cout << endl;
}