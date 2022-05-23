//
//  Heap.hpp
//  Heap
//
//  Created by 暖暖 on 2022/5/23.
//

#ifndef Heap_hpp
#define Heap_hpp

#include <stdio.h>

#pragma once
#include<iostream>
#include<stdlib.h>
using namespace std;

int Less(int left, int right);
int Greater(int left, int right);

typedef int(*pCompare)(int left, int right);


typedef int HPDataType;
//顺序表实现堆
typedef struct Heap
{
    HPDataType* _arr;
    int _size;
    int _capacity;
    pCompare compare;
}Heap;



// 堆的构建
void HeapCreate(Heap* hp, HPDataType* a, int n, pCompare comper);
//void HeapCreate(Heap* hp, HPDataType* a, int n);
// 堆的销毁
void HeapDestory(Heap* hp);
// 堆的插入
void HeapPush(Heap* hp, HPDataType x);
// 堆的删除（删除堆顶元素）
void HeapPop(Heap* hp);
// 取堆顶的数据
HPDataType HeapTop(Heap* hp);
// 堆的数据个数
int HeapSize(Heap* hp);
// 堆的判空
int HeapEmpty(Heap* hp);

// 对数组进行堆排序
void HeapSort(int * a, int n, pCompare comper);

#endif /* Heap_hpp */
