#pragma once
#include <iostream>
using namespace std;
//动态增长内存，策略 将存放数据的内存放到堆上
//容量capacity
//size概念 记录当前数组中具体的元素个数
typedef struct DYNAMICARRAY{
    int* pAddr; //存放数据的地址
    int size; //当前元素个数
    int capacity; //容量
}Dynamic_Array;

//写一系列的相关对结构体操作的函数
//初始化
Dynamic_Array* Init_Array();
//插入
void Push_Back_Array(Dynamic_Array* arr, int val);
//根据位置删除
void RemoveByPos_Array(Dynamic_Array* arr, int pos);
//根据值删除
void RemoveByValue_Array(Dynamic_Array* arr, int value);
//查找
int Find_Array(Dynamic_Array* arr, int value);
//打印
void Print_Array(Dynamic_Array* arr);
//释放动态数组的内存
void FreeSpace_Array(Dynamic_Array* arr);