//
//  Stack.cpp
//  Stack
//
//  Created by 暖暖 on 2022/5/18.
//

#include "Stack.hpp"

//栈的初始化
void StackInit(Stack* sta)
{
    if(NULL == sta)
    {
        return;
    }
    sta->array = (STDataType*)malloc(sizeof(STDataType)*10);
    if(sta->array == NULL)
    {
        return;
    }
    sta->size = 0;
    sta->capacity = 10;
}

//检测容量
void CheckCapacity(Stack* sta)
{
    //判空
    if(NULL == sta)
    {
        return;
    }
    if(sta->size == sta->capacity)
    {
        //申请新空间
        STDataType* temp = (STDataType*)malloc(sizeof(STDataType)*2*(sta->capacity));
        if(NULL == temp)
        {
            return;
        }
        //拷贝元素
        for(int i = 0; i < sta->size; i++)
        {
            temp[i] = sta->array[i];
        }
        //释放旧空间
        free(sta->array);
        sta->array = temp;
        sta->capacity *= 2;
    }
   
}

// 入栈
void StackPush(Stack* sta, STDataType data)
{
    if(NULL == sta)
    {
        return;
    }
    CheckCapacity(sta);
    sta->array[sta->size] = data;
    sta->size++;
}

// 出栈
void StackPop(Stack* sta)
{
    if(StackEmpty(sta))
    {
        return;
    }
    sta->size--;
}

// 获取栈顶元素
STDataType StackTop(Stack* sta)
{
    if(StackEmpty(sta))
    {
        return -1;
    }
    return sta->array[sta->size-1];
}

// 获取栈中有效元素个数
int StackSize(Stack* sta)
{
    if(NULL == sta)
    {
        return -1;
    }
    return sta->size;
}

// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0
int StackEmpty(Stack* sta)
{
    if(NULL == sta)
    {
        return -1;
    }
    return sta->size == 0;
}

// 销毁栈
void StackDestroy(Stack* sta)
{
    if(NULL == sta)
    {
        return;
    }
    free(sta->array);
    sta->array = NULL;
    sta->size = 0;
    sta->capacity = 0;
}
