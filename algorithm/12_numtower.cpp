//
// Created by AutumnSigni on 2023/10/17.
//

// 数字塔问题
/**
* 自塔顶沿箭头移动到地城，如何使得移动路径上数字和最大，最大值是多少，路径是什么
 *
 * 1.找最优解的性质
 * 2.从底往上找最大值，因为一个结点最多只有两个选择，与之相加取最大值覆盖这样递归上去就能得到最大值
 * 方程s[i][j] =A[i][j] + max{s[i+1][j+1],s[i+1][j]} ,这是根据存储结构决定的
 * 时间复杂度 O(n^2)
 * 空间复杂度 O(n^2)
*/

#include <iostream>
using namespace std;
void numTower(int **a, int **s, int n) {//a塔 s最优解 n 行
    for (int i = 1; i <= n; ++i) {
        s[n][i] = a[n][i]; //最值结果是从最低一行递归上去的
    }
    int max;
    for (int i = n - 1; i >= 1; --i) { //从倒数第二行计算最大值
        for (int j = 1; j <= i; ++j) {//第i行就有第i个数字
            max = s[i + 1][j] > s[i + 1][j + 1] ? s[i + 1][j] : s[i + 1][j + 1];
            s[i][j] = a[i][j] + max;
        }
    }
}

void traceBack(int **a,int **s,int i,int j,int n){//i 第一行 j 第一列往下构造最优解
    if (i == n) {//i到第n行，即递归到最后一层了
        cout << "(" << i << ", " << j << ")" << endl; //最后一行选取值的下标，边界条件
        return;
    }
    cout << "(" << i << ", " << j << ")" << endl;//第i行选取值的下标
    if (s[i][j] == a[i][j] + s[i + 1][j]) { //如果
        // max = s[i+1][j]
        traceBack(a, s, i + 1, j, n);

    } else {
        // max = s[i+1][j]
        traceBack(a, s, i + 1, j + 1, n);
    }
}
void printArray(int **a, int n) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout<<a[i][j]<<"\t";
        }
        cout<<endl;
    }
}

void initArray(int **a,int n){
    for (int i = 0; i <= n; ++i) {
        a[i] = new int[n + 1];
    }
    for (int i = 0; i <= n; ++i) {
        for (int j = 1; j <=n; ++j) {
            a[i][j]=0;
        }
    }
}
int main(){
    int n = 5;
    int **m= new int *[n+1];//第0行第0列不用
    int **s= new int *[n+1];
    // 初始化数组，二维数组必须初始化
    initArray(m,n+1);
    initArray(s,n+1);
    m[1][1] = 30;
    m[2][1] = 23;
    m[2][2] = 21;
    m[3][1] = 20;
    m[3][2] = 13;
    m[3][3] = 10;
    m[4][1] = 7;
    m[4][2] = 12;
    m[4][3] = 10;
    m[4][4] = 22;
    m[5][1] = 4;
    m[5][2] = 5;
    m[5][3] = 2;
    m[5][4] = 6;
    m[5][5] = 5;
    numTower(m, s, n);
    printArray(m, n);
    printArray(s, n);
    traceBack(m, s, 1, 1, n);
}