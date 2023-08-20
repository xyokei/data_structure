//
// Created by AutumnSigni on 2023/8/20.
//

//给定栈 输入输出序列 ，判断是否合法
#include <iostream>

using namespace std;

bool isLegal(char c[]) {
    int i = 0;
    int j = 0, k = 0;//输入次数 输出次数
    while (c[i] != '\0') { //字符型数组未占用全是\0
        switch (c[i]) {
            case 'I':
                j++;
                break;
            case 'O':
                k++;
                if (k > j) cout << "非法序列";
                return false;
        }
        i++;
    }
    if (j != k) {
        cout << "非法序列";
        return false;
    } else {
        cout << "合法序列";
        return true;
    }
}