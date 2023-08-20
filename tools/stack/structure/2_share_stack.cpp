//
// Created by AutumnSigni on 2023/8/20.
//

#include "2_share_stack.h"
#include <iostream>

using namespace std;

bool push(ShareStack &s, int i, int x) {
    if (i < 0 || i > 1) {
        cout << "栈号错误，正确：0, 1" << endl;
        return false;
    }

    if (s.top[1] - s.top[0] == 1) {
        cout << "栈满" << endl;
        return false;
    }
    switch (i) {
        case 0:
            s.data[++s.top[0]] = x;
            return true;
        case 1:
            s.data[--s.top[1]] = x;
            return true;
        default:
            return false;
    }
}

int pop(ShareStack &s, int i) {
    if (i < 0 || i > 1) {
        cout << "栈号错误，正确：0, 1" << endl;
        return -1;
    }


    switch (i) {
        case 0:
            if (s.top[0] == -1) {
                cout << "栈空" << endl;
                return -1;
            } else {
                return s.data[s.top[0]--];
            }
        case 1:
            if (s.top[1] == MaxSize) {
                cout << "栈空" << endl;
                return -1;
            } else {
                return s.data[s.top[1]++];
            }
        default:
            return false;
    }
}