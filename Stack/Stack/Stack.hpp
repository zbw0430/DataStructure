//
//  Stack.hpp
//  Stack
//
//  Created by 暖暖 on 2022/5/18.
//

#ifndef Stack_hpp
#define Stack_hpp

#include <stdio.h>

#pragma once

#include<iostream>
#include "stdlib.h"
using namespace std;


typedef int STDataType;

typedef struct Stack
{
    STDataType* array;
    int capacity; //容量
    int size;
}Stack;

//栈的初始化
void StackInit(Stack* sta);

//检测容量
void CheckCapacity(Stack* sta);

// 入栈
void StackPush(Stack* sta, STDataType data);

// 出栈
void StackPop(Stack* sta);

// 获取栈顶元素
STDataType StackTop(Stack* sta);

// 获取栈中有效元素个数
int StackSize(Stack* sta);

// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0
int StackEmpty(Stack* sta);

// 销毁栈
void StackDestroy(Stack* sta);
#endif /* Stack_hpp */
