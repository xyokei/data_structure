//
// Created by AutumnSigni on 2023/8/1.
//

#include <ctime>
#include <cstdlib>

#ifndef CHAPTER2_LINERLIST_INT_RANDOM_H
#define CHAPTER2_LINERLIST_INT_RANDOM_H


int *random(int len, int max) {
    int *arr = new int[len]; //int arr[len];会被释放掉，不能这样写
    srand((unsigned) time(nullptr)); //每次随机，不加只会随机一次
    for (int i = 0; i < len; ++i) {
        arr[i] = rand() % max + 1;
    }
    return arr;
}

int *random(int len, int min, int max) {
    int *arr = new int[len]; //int arr[len];会被释放掉，不能这样写
    srand((unsigned) time(nullptr)); //每次随机，不加只会随机一次
    for (int i = 0; i < len; ++i) {
        // arr[i] = rand() % (max - min) + min;     //[min, max)
        arr[i] = rand() % (max - min + 1) + min; //[min, max]
        // arr[i] = rand() % (max - min) + min + 1; //(min, max]
    }
    return arr;
}

#endif //CHAPTER2_LINERLIST_INT_RANDOM_H
