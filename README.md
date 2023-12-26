# 25交流群 831828534

# data_structure
>数据结构学习记录   
> <font color=grey size=2>*就随便记记，也不知道啥时候就停止了*</font>

## 第一章
### 1.线性表 6 个 结构
 
- 顺序表
- 单链表
- 无头单链表
- 带头结点双链表
- 带头结点循环链表
- 带头结点循环双链表

    *<font size=3>[具体代码参见](https://github.com/xyokei/data_structure/tree/main/tools/linerlist/structure)</font>*

### 2.基本方法
```c++
//以顺序表为例，其他都是一样的
// 创建
void initList(SqList &sqList);
// 删除
void DestroyList(SqList &sqList);
// 增
bool insertList(SqList &sqList, int i, int value);
// 删
int listDelete(SqList &sqList, int i);
// 按位查
int getElem(SqList sqList, int i);
// 按值查
int locateValue(SqList sqList, int value);
// 判空
bool isEmpty(SqList sqList);
// 表长
int getLength(SqList sqList);
----------------------------------------
```
