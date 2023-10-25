//
// Created by AutumnSigni on 2023/10/14.
//

//棋盘覆盖问题
int board[1024][1024]; //棋盘
int tile = 0; //骨牌编号 -> 最终搜用到的骨牌数量 (4^k -1)/3
/**
 *
 * @param tr 左上角行号
 * @param tc 左上角列号
 * @param dr 特殊方格行号
 * @param dc 特殊方格列号
 * @param size 棋盘尺寸 正方形，长宽等
 */
void chessBoard(int tr, int tc, int dr, int dc, int size) {
    if (size == 1) {
        return;
    }
    int s = size / 2; // 划分棋盘为4块
    int t = ++tile; // 本次骨牌编号 加 1 ->最终搜用到的骨牌数量
    // 判断新划分的左上角区域, 是否是特殊棋盘
    if (dr < tr + s && dc < tc + s) {
        // 是特殊棋盘,直接进行下一次覆盖操作
        chessBoard(tr, tc, dr, dc, s);
    } else {
        // 不是特殊棋盘, 用编号t覆盖右下角的一小块
        board[tr + s - 1][tc + s - 1] = t;
        chessBoard(tr, tc, tr + s - 1, tc + s - 1, s);
    }

    // 判断新划分的右上角区域, 是否是特殊棋盘
    if (dr < tr + s && dc >= tc + s) {
        // 是特殊棋盘,直接进行下一次覆盖操作
        chessBoard(tr, tc + s, dr, dc, s);
    } else {
        // 不是特殊棋盘, 用编号t覆盖左下角的一小块
        board[tr + s - 1][tc + s] = t;
        chessBoard(tr, tc + s, tr + s - 1, tc + s, s);
    }

    // 判断新划分的左下角区域, 是否是特殊棋盘
    if (dr >= tr + s && dc < tc + s) {
        // 是特殊棋盘, 直接进行下一次覆盖操作
        chessBoard(tr + s, tc, dr, dc, s);
    } else {
        // 不是特殊棋盘, 用编号t覆盖右上角的一小块
        board[tr + s][tr + s - 1] = t;
        chessBoard(tr + s, tc, tr + s, tr + s - 1, s);
    }

    // 判断新划分的右下角区域, 是否是特殊棋盘
    if (dr >= tr + s && dc >= tc + s) {
        // 是特殊棋盘, 直接进行下一次覆盖操作
        chessBoard(tr + s, tc + s, dr, dc, s);
    } else {
        // 不是特殊棋盘, 用编号t覆盖左上角的一小块
        board[tr + s][tc + s] = t;
        chessBoard(tr + s, tc + s, tr + s, tc + s, s);
    }
}