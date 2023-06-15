//
// Created by AutumnSigni on 2023/6/15.
//
//线性表 - 动态顺序表
// 定义
// 创建 删除
// 基本：增 删 查（按位查，按值查）
// 附加：判空，表长，扩容方法，输出格式

/**
 * 总结
 * 没什么难的 注意位序和下标就行
 * 测试时出bug了，
 * 原因是没有给 seqList.length 初始化，debug发现其值为负数且非常大
 * 导致 插入时疯狂报位置不合法
 * 还有 最好也把seqList.data初始化一下，虽然没测出问题
 */

#include <iostream>

using namespace std;

#define InitSize 50
#define ExtendSize 50

// 定义
typedef struct SeqList {
    int *data;
    int length;
    int MaxSize;
} SeqList;

//方法声明
// 定义
// 创建 删除
// 基本：增 删 查（按位查，按值查）
// 附加：判空，表长，扩容方法，输出格式
// 创建
void initList(SeqList &seqList);

// 删除
void DestroyList(SeqList &seqList);

// 增
bool listInsert(SeqList &seqList, int i, int value);

// 删
int listDelete(SeqList &seqList, int i);

// 按位查
int getElem(SeqList seqList, int i);

// 按值查
int locateValue(SeqList seqList, int value);

// 判空
bool isEmpty(SeqList seqList);

// 表长
int getLength(SeqList seqList);

// 扩容方法
SeqList extendList(SeqList seqList);

//输出格式
void printList(SeqList seqList);

/**
 * 创建
 * @param L
 */
void initList(SeqList &seqList) {
    seqList.data = (int *) malloc(sizeof(int) * InitSize);
    //有bug 然后重新加下面的代码，初始化
    seqList.length = 0;
    seqList.MaxSize = InitSize;
    // for (int i = 0; i < InitSize; ++i) {
    //     seqList.data[i] = 0; //初始化
    // }
    //seqList.data = new int[InitSize];  //c++初始化
}

/**
 * 销毁
 * @param seqList
 */
void DestroyList(SeqList &seqList) {
    for (int i = 0; i < seqList.length; ++i) {
        seqList.data[i] = 0;
    }
    free(seqList.data);
}

/**
 * 下标从0开始 但是插入位置是位序，注意这个
 * @param seqList
 * @param i 位序
 * @param value
 * @return
 */
bool listInsert(SeqList &seqList, int i, int value) {
    // 先检验输入数据合法
    if (i < 1 || i > seqList.length + 1) {
        cout << "输入位置不合法"<<"\n";
        return false;
    }
    if (seqList.length == seqList.MaxSize) {
        seqList = extendList(seqList);
    }
    for (int j = seqList.length; j >= i; --j) {
        //按位序 是第 i 个元素及以后 后移
        //对于数组是下标为 i-1 的元素及以后 后移
        seqList.data[j] = seqList.data[j - 1];
    }
    seqList.data[i - 1] = value;
    seqList.length++;
    return true;
}

/**
 * 删除
 * @param seqList
 * @param i
 * @return
 */
int listDelete(SeqList &seqList, int i) {
    if (i < 1 || i > seqList.length) {
        cout << "输入位置不合法";
        return -1;
    }
    int d_value = seqList.data[i - 1];
    for (int j = i; j < seqList.length; ++j) {
        seqList.data[j - 1] = seqList.data[j];
    }
    seqList.length--;
    return d_value;
}

/**
 * 按位查找
 * @param seqList
 * @param i
 * @return
 */
int getElem(SeqList seqList, int i) {
    return seqList.data[i - 1];
}

/**
 * 按值查找
 * @param seqList
 * @param value
 * @return 位序
 */
int locateValue(SeqList seqList, int value) {
    for (int i = 0; i < seqList.length; ++i) {
        if (seqList.data[i] == value) {
            return i + 1; //+1 很重要
        }
    }
    return -1;
}

/**
 * 判空
 * @param seqList
 * @return
 */
bool isEmpty(SeqList seqList) {
    return seqList.length == 0;
}

/**
 * 表长
 * @param seqList
 * @return
 */
int getLength(SeqList seqList) {
    return seqList.length;
}

/**
 * 扩容
 * @param seqList
 * @return
 */
SeqList extendList(SeqList seqList) {
    SeqList copyList;
    copyList.MaxSize = seqList.length+ ExtendSize;
    copyList.data = (int *) malloc(sizeof(int) * (copyList.MaxSize));
    copyList.length = 0;
    for (int i = 0; i < seqList.length; ++i) {
        copyList.data[i] = seqList.data[i];
    }
    copyList.length = seqList.length;
    return seqList;
}

void printList(SeqList seqList) {
    cout << "表长为：" << seqList.length << endl;
    cout << '[';
    for (int i = 0; i < seqList.length - 1; ++i) {
        if ((i + 1) % 7 == 0) {
            cout << seqList.data[i] << "\n" << " ";
            continue;
        }
        cout << seqList.data[i] << ',' << '\t';
        //printf("%d,",seqList.data[i]);
    }
    cout << seqList.data[seqList.length - 1] << ']'<<endl;
}


//Test
// 定义
// 创建 删除
// 基本：增 删 查（按位查，按值查）
// 附加：判空，表长，扩容方法，输出格式
int main() {
    SeqList seqList;
    initList(seqList);
    if (isEmpty(seqList)) {
        cout << "空表" << "\n";
    }
    for (int i = 1; i < 30; ++i) {
        listInsert(seqList, i, i);
    }
    printList(seqList);
    listDelete(seqList, 3);
    printList(seqList);
    listInsert(seqList, 6, -3);
    printList(seqList);
    cout << "表长为: " << getLength(seqList) << endl;
    cout << "-3的位序为: " << locateValue(seqList,-3)<<endl;
    cout << "位序为3的值: " << getElem(seqList,3)<<endl;
    DestroyList(seqList);
    printList(seqList);
}