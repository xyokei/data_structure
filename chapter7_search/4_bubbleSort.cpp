//
// Created by AutumnSigni on 2023/11/5.
//

/**
* 思想：交换
 * 1.元素 0~n-1 ,设定k=0，end = n-1,swap_flag =true
 * 2.依次比较a[k] a[k+1] ，将swap_flag =false
 *     if a[k+1]<a[k] 交换 将swap_flag 置true
 * 3. k = end时，一趟冒泡结束，end--,k=0重新再来一次
 * 4，终止条件 此次swap_flag == false;即有序
*/