//
// Created by AutumnSigni on 2023/10/4.
//

#ifndef ALGORITHM_0_VECTOR_TABLE_H
#define ALGORITHM_0_VECTOR_TABLE_H
// 结构体定义
#define max_size 10
typedef char vertexType;
typedef int edgeType;
typedef struct {
    vertexType v[max_size];
    edgeType e[max_size][max_size];
    int v_num,e_num;
}MGraph;

// 算法实现
// v[10][10];二维数组就行
// 变长的 vector< vector<int> > num

#endif //ALGORITHM_0_VECTOR_TABLE_H
