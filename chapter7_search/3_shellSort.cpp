//
// Created by AutumnSigni on 2023/11/5.
//

/**希尔排序
 * 思想：直接插入排序基于有序表能有更好的性能
 * 取 步长dk = n/2
*/
void shellSort(int a[], int n) {
    int temp;
    for (int gap = n / 2; gap >= 1; gap = gap / 2) {
        for (int i = gap; i < n; ++i) {
            temp = a[gap];
            int j;
            for (j = i; j >= gap && temp < a[j - gap] ; j -= gap) {
                a[j] =a[j-gap];
            }
            a[j] =temp;
        }
    }
}