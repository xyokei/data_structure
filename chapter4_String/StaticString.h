//
// Created by AutumnSigni on 2023/7/3.
//
// 字符串

// 定义
// 赋值
// 基本：复制，求子串，串联接 定位，比较，串长，
// 附加：清空，销毁
//       打印

#define MaxSize 20

// ch[0]废弃，和位置保持一致，长度单独设置int 型变量
typedef struct sstring {
    char ch[MaxSize];
    int length;
} sstring;


// 基本：复制，求子串，串联接 定位，比较，串长，


void subString(char str[], sstring s, int pos, int len);

int index(sstring s, sstring t);

int strLength(sstring s);

/**
 * 朴素模式匹配 暴力破解
 * 返回t在s 中的位置
 * @param s 主串
 * @param t 模串
 * @return 模串第一次出现的位置 0:未匹配到
 */
int index(sstring s, sstring t) {
    int i = 1, j = 1;
    int s_len = strLength(s);
    int t_len = strLength(t);
    while (i <= s_len - t_len + 1 && j <= t_len) {// 前面控制匹配总次数，后面控制匹配第一次跳出
        if (s.ch[i] == t.ch[j]) {
            ++i;
            ++j;
        } else {
            i = i - j + 2; //重点
            j = 1;         //重点
        }
    }
    if (j > t_len) {
        return j - t_len;
    }
    return 0;
}

int strLength(sstring s) {
    return s.length;
}