//
// Created by AutumnSigni on 2023/10/6.
//

//思想：
// 如果 存在顶点k，以k为中介点，顶点i 到顶点j的距离缩短，
//  则使用顶点k作为顶点i 和顶点j 的中介点
// 动态规划
// 中介点的记录 用二维数组记录，两点最短路径也用二维数组记录
// 动态方程 min{ dis[i][k] + dis[k][j], dis[i][j]}
// 伪代码
/**
*   void Floyd(){
 *       遍历（枚举）所有顶点 k 属于 1~n
 *         以顶点 k 为中介点，枚举所有点
 *             if(dis[i][k]+dis[k][j]<dis[i][j])
 *                dis[i][j] = dis[i][k]+dis[k][j]
 *   }
 *
*/
#define max_v 200
#define inf 0x3fffffff
int dis[max_v][max_v]; //从顶点下标i 到顶点下标j的最短路径值
int pre[max_v][max_v]; //从顶点下标i 到顶点下标j的中转结点的标号

// 显然复杂度 O(n^3) 顶点的3次方
void floyd(int n, int m){ //顶点数，边数
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if(dis[i][k]!=inf && dis[k][j]!=inf && dis[i][k]+dis[k][j]<dis[i][j])
                      dis[i][j] = dis[i][k]+dis[k][j];
                      pre[i][j] = k;
            }
        }
    }
}