//
// Created by AutumnSigni on 2023/7/31.
// 顺序表

#include "0_sq_single_list_util.h"
#include <iostream>
using namespace std;

#define InitSize 50
#define ExtendSize 50

/**
 * 创建
 * @param L
 */
void initList(SqList &sqList) {
    sqList.data = (int *) malloc(sizeof(int) * InitSize);
    //有bug 然后重新加下面的代码，初始化
    sqList.length = 0;
    sqList.MaxSize = InitSize;
    // for (int i = 0; i < InitSize; ++i) {
    //     SqList.data[i] = 0; //初始化
    // }
    //SqList.data = new int[InitSize];  //c++初始化
}

/**
 * 销毁
 * @param sqList
 */
void DestroyList(SqList &sqList) {
    for (int i = 0; i < sqList.length; ++i) {
        sqList.data[i] = 0;
    }
    free(sqList.data);
}

/**
 * 扩容
 * @param sqList
 * @return
 */
SqList extendList(SqList sqList) {
    SqList copyList;
    copyList.MaxSize = sqList.length+ ExtendSize;
    copyList.data = (int *) malloc(sizeof(int) * (copyList.MaxSize));
    copyList.length = 0;
    for (int i = 0; i < sqList.length; ++i) {
        copyList.data[i] = sqList.data[i];
    }
    copyList.length = sqList.length;
    return sqList;
}

/**
 * 下标从0开始 但是插入位置是位序，注意这个
 * 时间复杂度
 *           最好：直接插到表尾 即 i = n+1 :O(1)
 *           最坏：插到表头 i = 1 :O(n)
 *           平均：(1+2+..+n)*p = n/2 , p =1/(1+n)
 * @param SqList
 * @param i 位序
 * @param value
 * @return
 */
bool insertList(SqList &sqList, int i, int value) {
    // 先检验输入数据合法
    if (i < 1 || i > sqList.length + 1) {
        cout << "输入位置不合法"<<"\n";
        return false;
    }
    if (sqList.length == sqList.MaxSize) {
        sqList = extendList(sqList);
    }
    for (int j = sqList.length; j >= i; --j) {
        //按位序 是第 i 个元素及以后 后移
        //对于数组是下标为 i-1 的元素及以后 后移
        sqList.data[j] = sqList.data[j - 1];
    }
    sqList.data[i - 1] = value;
    sqList.length++;
    return true;
}

/**
 * 删除
 * @param SqList
 * @param i
 * @return
 */
int listDelete(SqList &sqList, int i) {
    if (i < 1 || i > sqList.length) {
        cout << "输入位置不合法";
        return -1;
    }
    int d_value = sqList.data[i - 1];
    for (int j = i; j < sqList.length; ++j) {
        sqList.data[j - 1] = sqList.data[j];
    }
    sqList.length--;
    return d_value;
}

/**
 * 按位查找
 * @param sqList
 * @param i
 * @return
 */
int getElem(SqList sqList, int i) {
    return sqList.data[i - 1];
}

/**
 * 按值查找
 * @param sqList
 * @param value
 * @return 位序
 */
int locateValue(SqList sqList, int value) {
    for (int i = 0; i < sqList.length; ++i) {
        if (sqList.data[i] == value) {
            return i + 1; //+1 很重要
        }
    }
    return -1;
}

/**
 * 判空
 * @param sqList
 * @return
 */
bool isEmpty(SqList sqList) {
    return sqList.length == 0;
}

/**
 * 表长
 * @param sqList
 * @return
 */
int getLength(SqList sqList) {
    return sqList.length;
}

void printList(SqList sqList) {
    cout << "表长为：" << sqList.length << endl;
    cout << '[';
    for (int i = 0; i < sqList.length - 1; ++i) {
        if ((i + 1) % 7 == 0) {
            cout << sqList.data[i] << "\n" << " ";
            continue;
        }
        cout << sqList.data[i] << ',' << '\t';
        //printf("%d,",SqList.data[i]);
    }
    cout << sqList.data[sqList.length - 1] << ']'<<endl;
}
