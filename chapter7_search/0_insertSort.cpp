//
// Created by AutumnSigni on 2023/11/5.
//

// 直接插入排序
/** 思想: 要排序 0~n-1
 *   1.排序 k~n-1，k从1开始，0~k-1已经有序 初始k为0
 *   2.处理 a[k] ,设定暂存值temp = a[k]
 *       遍历 i 属于k-1~0，
 *          if a[i]>a[k] 则 a[i+1]=a[i] //后移一位
 *          else break;
 *       i+1 就是a[k]所在位置a[i] =temp;
 */
