//
// Created by AutumnSigni on 2023/11/5.
//
#include <iostream>
#include <vector>
using namespace std;
/**
 * 堆：完全二叉树，用数组表示
 * 大根堆，父节点大于等于子节点值
 * 小根堆，父节点小于等于子节点值
 *
 * 思想：建堆，然后堆排序
 * 对于大根堆：
 *  建堆：要求父节点大于等于子节点值
 *    则不需要考虑叶子结点了
 *    1.从最后一个非叶子结点开始遍历堆
 *    2.对于每个非叶子结点，即父节点，比较父节点与子节点值，进行交换
 *    3.递归进行堆化操作
 *  堆排序
 *    大根堆第一个元素是最大的
 *    1.设定初值 i = n-1 交换a[0] a[i]，即将最大直接放到末尾，同时 i--;
 *    2.调用调整堆算法maxheapify(a,i,0)
 *    3.重复1，直至i==0终止
 */

// 调整大根堆，确保根节点的值大于等于其子节点的值
/**
 *
 * @param arr
 * @param n 结点个数
 * @param i 当前调整结点
 */
void maxHeapify(vector<int>& arr, int n, int i) {//数组，数组长度，当前调整结点下标 即父节点
    int largest = i; //保存父节点下标位置
    int left = 2 * i + 1;//左子结点下标位置
    int right = 2 * i + 2;//右子结点下标位置
    //有左节点 且 左结点的值比父节点值大
    if (left < n && arr[left] > arr[largest]) {
        largest = left; //交换下标
    }
    //有右节点 且 右结点的值比父节点值大
    if (right < n && arr[right] > arr[largest]) {
        largest = right; //交换下标
    }

    if (largest != i) { //发生了交换
        //将对应值进行交换
        swap(arr[i], arr[largest]);
        //递归 此时largest对应的值是刚进来处理的对应i值，因为发生了交换
        //导致交换那个结点可能不符合大根堆条件，故需要递归调整
        maxHeapify(arr, n, largest);
    }
}

void buildMaxHeap(vector<int>& arr) {
    int n = arr.size(); //数组长度
    //完全二叉树有2^h-1个结点
    //最后一个非叶子结点开始调整
    for (int i = n / 2 - 1; i >= 0; --i) {
        maxHeapify(arr, n, i);
    }
}

void minHeapify(vector<int>& arr, int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest]) {
        smallest = left;
    }

    if (right < n && arr[right] < arr[smallest]) {
        smallest = right;
    }

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

void buildMinHeap(vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; --i) {
        minHeapify(arr, n, i);
    }
}

void heapSort(vector<int>& arr, bool isMaxHeap) {
    int n = arr.size();
    if (isMaxHeap) {
        buildMaxHeap(arr);
    } else {
        buildMinHeap(arr);
    }

    for (int i = n - 1; i > 0; --i) {
        swap(arr[0], arr[i]);
        if (isMaxHeap) {
            maxHeapify(arr, i, 0);
        } else {
            minHeapify(arr, i, 0);
        }
    }
}

int main() {
    vector<int> testArray = {12, 34, 54, 2, 3};

    cout << "原始数组: ";
    for (int num : testArray) {
        cout << num << " ";
    }
    cout << endl;

    // 大根堆排序
    heapSort(testArray, true);
    cout << "大根堆排序后的数组: ";
    for (int num : testArray) {
        cout << num << " ";
    }
    cout << endl;

    // 小根堆排序
    heapSort(testArray, false);
    cout << "小根堆排序后的数组: ";
    for (int num : testArray) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
