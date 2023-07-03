//
// Created by AutumnSigni on 2023/7/3.
//


// 定义
// 赋值
// 基本：复制，求子串，串联接 定位，比较，串长，
// 附加：清空，销毁
//       打印
#include <iostream>

#define MaxSize 20

// ch[0]废弃，和位置保持一致，长度单独设置int 型变量
// typedef struct Node {
//     char ch[4]; //32位 电脑一个节点可存4个字符，存一个浪费，用上面的
//     Node *next;
// } Node,*String;

typedef struct Node {
    char ch;
    Node *next;
} Node, *String;


void sub(char str[], String s, int pos, int len);

int index(String s, String t);

int strLength(String s);

/**
 * 不写了，感觉链式存储写不了，极其不方便
 * 朴素模式匹配 暴力破解
 * 返回t在s 中的位置
 * @param s 主串
 * @param t 模串
 * @return 模串第一次出现的位置 0:未匹配到
 */
int index(String s, String t) {
    String i = s->next, j = t->next;
    String p;
    int s_len = strLength(s);
    int t_len = strLength(t);
    while (i->next!= nullptr && j->next != nullptr) {// 前面控制匹配总次数，后面控制匹配第一次跳出
        if (s->ch == t->ch) {
            s = s->next;
            t = t->next;
        } else {
            p=s->next;
            j = t->next;
        }
    }
    if (j== nullptr) {
        return nullptr;
    }
    return 0;
}


