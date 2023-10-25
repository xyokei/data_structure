//
// Created by AutumnSigni on 2023/10/7.
//

// hanoi 塔问题
// 此题
void move(int a,int b);

void hanoi(int n, int a, int b, int c) {
    if (n > 0) {
        hanoi(n - 1, a, c, b);// 将n-1个圆盘从A移动到C， 辅助为B
        move(a, b);// 将最后一个大圆盘从A移动到B；
        hanoi(n - 1, c, b, a);// 将n-1个圆盘从C移动到B， 辅助为A
    }
}