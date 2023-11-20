//
// Created by AutumnSigni on 2023/11/5.
//

/**
* 思想：
 *  1.元素k~n-1，设定 初值k = 0，min = 0
 *  2.遍历元素 i 在k~n-1之间，if a[i]< min,min = a[i]
 *  3.将min与a[k]交换，k++重复 123
 *  4.终止条件 k = n-1 //两层for完事
*/