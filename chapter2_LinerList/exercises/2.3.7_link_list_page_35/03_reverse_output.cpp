//
// Created by AutumnSigni on 2023/8/17.
//


#include "liner_list_util.h"
#include "algorithm"

/**
 * 法一
 * 递归输出时，头结点不好弄啊，除非设定头结点数据来判断
 * @param list
 */
void reverse_output(SingleList list){
    if (list == nullptr) return;
    reverse_output(list->next);
    cout<<list->data<<" ";
}

void reverse_output_1(SingleList list){
    if (list->next == nullptr) return;
    reverse_output_1(list->next);
    if (list!= nullptr){
        cout<<list->next->data<<" ";
    }
}

//没想到这个，抄答案的
void ignore_head(SingleList list){
    if (list->next != nullptr)
        reverse_output(list->next);
}

int main(){
    SingleList list;
    int *arr  = random(6,10);
    sort(arr,arr+6);

    headCreateListAfter(list,arr,6);
    printList(list);
    // reverse_output_1(list);
    //改进
    ignore_head(list);
}
