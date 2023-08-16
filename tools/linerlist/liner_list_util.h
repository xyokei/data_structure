//
// Created by AutumnSigni on 2023/7/31.
//

#ifndef CHAPTER3_STACKANDQUEUE_LINER_LIST_UTIL_H
#define CHAPTER3_STACKANDQUEUE_LINER_LIST_UTIL_H

#include "structure/0_sq_single_list_util.cpp"
#include "structure/1_link_single_list_util.cpp"
#include "structure/2_link_no_head_list_util.cpp"
#include "structure/3_link_2_head_list_util.cpp"
#include "structure/4_link_circle_head_list_util.cpp"
#include "structure/5_link_cicle_2_head_list_util.cpp"
#include "../int_random.h"


void printArr(int a[], int len) {
    cout << "数组长：" << len << endl << "[";
    for (int i = 0; i < len - 1; ++i) {
        if ((i + 1) % 7 == 0) {
            cout << a[i] << endl;
        } else {
            cout << a[i] << "\t";
        }
    }
    cout << a[len - 1] << "]" << endl;
}

#endif //CHAPTER3_STACKANDQUEUE_LINER_LIST_UTIL_H
