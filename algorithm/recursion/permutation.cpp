//
// Created by AutumnSigni on 2023/10/1.
//

//给定集合，求出所有全排列

#include <iostream>

using namespace std;

// 算法思想
// n = 1时，集合只有一个元素，
// n > 1时，perm(R) 由{r1,perm(R1)},{r2,perm(R2)}...{rn,perm(Rn)}构成
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void perm(int a[], int start, int len) {
    if (start == len) { //只有一个集合时 排列是其自身
        for (int i = 0; i < len; ++i) {
            cout << a[i];
        }
        cout << endl;
    } else {
        for (int i = start; i < len; ++i) {
            swap(a[start], a[i]); //每次固定最开始元素，第一次start=i，即第一个位置，第二次 固定第二个元素
            perm(a, start + 1, len);
            swap(a[start], a[i]);//保证元素顺序不变，需要再换
        }
    }
}
int main(){
    int a[]={1,2,3};
    perm(a,0,3);
}