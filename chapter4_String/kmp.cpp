//
// Created by AutumnSigni on 2023/7/3.
//

//kmp算法
#include "StaticString.h"
#include <iostream>

/**
 * 感觉和kmp 一样 只是多了赋值next数组 操作
 * @param t 字符串
 * @param next 返回的数组
 * 可以想成两个一样的 字符串在做匹配 。
 * O(t)
 */
void get_next(sstring t, int next[]) {
    int i = 2,j=0;
    next[1] = 0;
    next[2] = 1;
    while (i<t.length){
        if (j==0 || t.ch[i] ==t.ch[j]){
            ++i;
            ++j;
            next[i] = j;
        }else{
            j = next[j];
        }
    }
}

/**
 * 优化
 * @param t
 * @param nextval
 */
void get_nextval(sstring t,int nextval[]){
    int i =1,j=0;
    nextval[1] =0;
    while (i<t.length){
        if (j==0||t.ch[i]==t.ch[j]){
            ++i;++j;
            if (t.ch[i]!=t.ch[j]) nextval[i] =j;
            else nextval[i] =nextval[j];
        } else{
            j = nextval[j];
        }
    }
}


/**
 * 就硬记吧，主要会手算就行
 * @param s 主串
 * @param t 模串
 * @return
 * O(s+t) = O(s)
 */
int kmp_sstring(sstring s, sstring t) {
    int i=1, j = 1; // i为主串下标 ，j为模式串下标
    int next[t.length];
    get_next(t, next); //时间复杂度 O(m)
    while (i <= s.length - t.length + 1 && j <= t.length) { //只循环i，即 时间复杂度O(n)
        if (j == 0 || s.ch[i] == s.ch[j]) {
            ++i;
            ++j;
        } else {
            j = next[j];
        }
    }
    if (j > t.length) {
        return i - t.length;
    }
    return 0;
}


int main() {

}