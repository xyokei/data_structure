//
// Created by AutumnSigni on 2023/6/28.
//

//线性表 - 循环单链表 -有头结点

// 定义
// 基本： 增(节点前增，节点后增)  只写前增
//       删
//       查（按位查，按值查）只写按位
// 附加：判空，表长，输出格式 只写输出
//       前插法建立表，后插法建立表

#include <iostream>

using namespace std;

// 定义
typedef struct Node {
    int data;
    Node *next;
} Node, *LinkList;

// 创建 销毁
bool initList(LinkList &list);

void destroyList(LinkList &list);

// 插(节点前插，节点后插) 按位插
bool insertBefore(Node *p, int data);

bool insertAfter(Node *p, int data);

bool insertById(LinkList &list, int i, int data);

// 删（按位删，按节点删）
bool deleteAt(LinkList &list, int i);

bool deleteNode(LinkList &list, Node *p);

//查（按位查，按值查）
Node *getElem(LinkList list, int i);

Node *locateValue(LinkList list, int value);

// 附加：判空，表长，输出格式
bool isEmpty(LinkList list);

int getLength(LinkList list);

void printList(LinkList list);

//       前插法建立表，后插法建立表

LinkList headCreateListPre(LinkList &list, int data[], int len);

LinkList headCreateListAfter(LinkList &list, int data[], int len);

/**
 * 初始化一个带头结点的链表
 * @return 头结点
 */
bool initList(LinkList &list) {
    list = (Node *) malloc(sizeof(Node));
    if (list == nullptr) { //未申请到空间判断
        return false;
    }
    list->next = nullptr;
    return true;
}

/**
 * 销毁表
 * @param list
 */
void destroyList(LinkList &list) {
    Node *p = list->next;
    Node *next;
    while (p != nullptr) {
        next = p->next;
        free(p);
        p = next;
    }
}

/**
 * 前插法，采用后插法思想
 * @param p
 * @param data
 * @return
 */
bool insertBefore(Node *p, int data) {
    if (p != nullptr) {
        auto *node = (Node *) malloc(sizeof(Node));
        //交换数据
        node->data = p->data;
        p->data = data;
        //交换结点
        node->next = p->next;
        p->next = node;
        return true;
    }

    return false;
}

/**
 * 后插法
 * @param list
 * @param p
 * @param data
 * @return
 */
bool insertAfter(Node *p, int data) {
    auto *node = (LinkList) malloc(sizeof(Node));
    node->data = data;
    node->next = p->next;
    p->next = node;
    return true;
}

/**
 *指定位置插人数据，即前插法
 * @param list
 * @param i
 * @param data
 * @return false:插入位置不合法
 */
bool insertById(LinkList &list, int i, int data) {
    auto *p = getElem(list, i);
    if (p == nullptr) {
        return false;
    }
    return insertBefore(p, data);
}

// 删（按位删，按节点删）
/**
 *
 * @param list 感觉不用带地址符号，因为删除总删除不了头节点
 * @param i
 * @return
 * 没有有偷梁换柱的方法，是因为尾节点不好处理
 */
bool deleteAt(LinkList &list, int i) {
    auto *p = getElem(list, i);
    if (p == nullptr) {
        return false;
    }
    Node *q = list;
    while (q->next != p) {
        q++;
    }
    q->next = p->next;
    free(p);
    return true;
}

bool deleteNode(LinkList &list, Node *p) {
    if (p == list || p == nullptr) {
        return false;
    }
    Node *q = list;
    while (q->next != p) {
        q++;
    }
    q->next = p->next;
    free(p);
    return true;
}

/**
 * 按位查
 * @param list
 * @param i
 * @return 第i个结点，若表长小于位序，返回nullptr
 */
Node *getElem(LinkList list, int i) {
    int j = 1;
    Node *p = list->next;
    if (i < 1)
        return nullptr;
    while (p && j < i) {
        p = p->next;
        j++;
    }
    return p;
}

/**
 * 按值查结点
 * @param list
 * @param value
 * @return 结点，未查到返回nullptr
 */
Node *locateValue(LinkList list, int value) {
    Node *p = list->next;
    while (p != nullptr && p->data != value) {
        p = p->next;
    }
    return p;
    // 我写的
    // while (p != nullptr) {
    //     if (p->data == value) return p;
    //     p = p->next;
    // }
    // return nullptr;
}

// 附加：判空，表长，输出格式
bool isEmpty(LinkList list) {
    return list->next == nullptr;
}

int getLength(LinkList list) {
    int i = 0;
    while (list->next != nullptr) {
        i++;
    }
    return i;
}

/**
 * 前插法建立单链表
 * @param list
 * @param data 建立数据
 * @param len 数据长度
 * @return
 */
LinkList headCreateListPre(LinkList &list, int data[], int len) {
    Node *s;
    list = (LinkList) malloc(sizeof(Node));
    list->next= nullptr; //不置空输出的时候有bug，无限循环
    for (int i = 0; i < len; ++i) {
        s = (LinkList) malloc(sizeof(Node));
        s->data = data[i];
        s->next = list->next;
        list->next = s;
        if(i==0){
            s->next=list;
        }
    }
    return list;
}

/**
 * 后插法建立表
 * @param list
 * @param data
 * @param len
 * @return
 */
LinkList headCreateListAfter(LinkList &list, int data[],int len){
    Node *s,*rear;
    list = (LinkList) malloc(sizeof(Node));
    list->next= nullptr;
    rear = list;
    for (int i = 0; i < len; ++i) {
        s = (LinkList)malloc(sizeof(Node));
        s->data= data[i];
        rear->next = s;
        rear = s;
    }
    return list;
}

void printList(LinkList list) {
    Node *p = list->next;
    if (isEmpty(list)) {
        cout << "空表" << endl;
        return;
    }
    int i = 0;
    cout << "单链表：" << endl << "[";
    while (p && p->next != list) {
        if (i!=0 && i % 7 == 0) cout << endl <<' ';
        cout << p->data<< ',' << '\t';
        p = p->next;
        i++;
    }
    cout << p->data << ']' << endl;
}

//Test
// 定义
// 创建 销毁
// 基本： 增(节点前增，节点后增)
//       删(节点前增，节点后增) 查（按位查，按值查）
// 附加：判空，表长，输出格式
int main() {
    int len = 20;
    int data[len];
    for (int i = 0; i < len; ++i) {
        data[i] = i+1;
    }
    LinkList listPre,listAfter;

    headCreateListPre(listPre,data,len);
    printList(listPre);
    deleteAt(listPre,1);
    printList(listPre);
    deleteAt(listPre,3);
    printList(listPre);
    Node *p = getElem(listPre,18);
    cout<<p->data<<endl;
    insertBefore(p,21);
    p = getElem(listPre,19);
    cout<<p->data<<endl;
    insertAfter(p,22);
    printList(listPre);
    p = getElem(listPre,2);
    deleteNode(listPre,p);
    printList(listPre);

    // headCreateListAfter(listAfter,data,len);
    // printList(listAfter);
}