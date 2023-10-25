//
// Created by AutumnSigni on 2023/10/14.
//

#include <iostream>
using namespace std;
//二分搜索
// 解题：一般是给定有序数列，
//      要求查给定x，或比x大的的第一个数字，或比x小的第一个数字

//有序数列 找给定x
// 递归做
// 时间复杂度 logn 主定理方式求解
int biSearch(int *a, int left, int right, int x) {
    if (left > right) return -1; //边界

    int i = (left + right) / 2;
    if (a[i] == x) return i;
    if (a[i] < x) {
        biSearch(a, i + 1, right, x);
    } else {
        biSearch(a, left, i - 1, x);

    }
}

//非递归
int biSearch_1(int a[], int l, int r, int x) {
    int mid;
    while (l <= r) {
        mid = (l + r) / 2;
        if (a[mid] == x) return mid;
        else if (a[mid] > x) r = mid - 1;
        else l = mid + 1;
    }
    return -1;
}

int main(){
    int a[] ={1,3,5,6,7,8};
    int loc = biSearch(a,0,5,6);
    cout<<loc<<endl;
    loc = biSearch_1(a,0,5,6);
    cout<<loc<<endl;
}