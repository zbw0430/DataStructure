//
//  SeqList.cpp
//  2022.5.6
//
//  Created by 暖暖 on 2022/5/10.
//

#include "SeqList.hpp"

// 顺序表初始化
void SeqListInit(SeqList* ps, size_t capacity)
{
    if(NULL == ps)
    {
        assert(0);
        return;
    }
    ps->capicity = (capacity <= 0 ? 10 : capacity);
    ps->array = (SLDataType*)malloc(sizeof(SLDataType)*ps->capicity);
    ps->size = 0;
}

// 顺序表销毁
void SeqListDestory(SeqList* ps)
{
    free(ps->array);
    ps->array = NULL;
    ps->capicity = 0;
    ps->size = 0;
}

// 顺序表打印
void SeqListPrint(SeqList* ps)
{
    if(NULL == ps)
    {
        assert(0);
        return;
    }
    for(int i = 0; i < ps->size; i++)
    {
        cout << ps->array[i] << " ";
    }
    cout << endl;
}

// 检查空间，如果满了，进行增容
void CheckCapacity(SeqList* ps)
{
    if(NULL == ps)
    {
        assert(0);
        return;
    }
    if(ps->size == ps->capicity)
    {
        ps->array = (SLDataType*)realloc(ps->array, ps->capicity*2*sizeof(SLDataType));
        ps->capicity = ps->capicity*2;
    }
}

// 顺序表尾插
void SeqListPushBack(SeqList* ps, SLDataType data)
{
    if(NULL == ps)
    {
        assert(0);
        return;
    }
    CheckCapacity(ps);
    ps->array[ps->size] = data;
    ps->size++;
}

// 顺序表尾删
void SeqListPopBack(SeqList* ps)
{
    if(NULL == ps)
    {
        assert(0);
        return;
    }
    if(ps->size == 0) return;
    ps->size--;
}

// 顺序表头插
void SeqListPushFront(SeqList* ps, SLDataType data)
{
    if(NULL == ps)
    {
        assert(0);
        return;
    }
    CheckCapacity(ps);
    for(int i = ps->size-1; i >= 0; i--)
    {
        ps->array[i+1] = ps->array[i];
    }
    ps->array[0] = data;
    ps->size++;
}

// 顺序表头删
void SeqListPopFront(SeqList* ps)
{
    if(NULL == ps)
    {
        assert(0);
        return;
    }
    if(ps->size == 0) return;
    for(int i = 1; i < ps->size; i++)
    {
        ps->array[i-1] = ps->array[i];
    }
    ps->size--;
}

// 顺序表查找
int SeqListFind(SeqList* ps, SLDataType data)
{
    if(NULL == ps)
    {
        assert(0);
        return 0;
    }
    if(ps->size == 0) return -1;
    for(int i = 0; i < ps->size; i++)
    {
        if(ps->array[i] == data) return i;
    }
    return -1;
}

// 顺序表在pos位置插入data
void SeqListInsert(SeqList* ps, size_t pos, SLDataType data)
{
    if(NULL == ps)
    {
        assert(0);
        return;
    }
    CheckCapacity(ps);
    for(int i = ps->size-1; i >= pos; i--)
    {
        ps->array[i+1] = ps->array[i];
    }
    ps->array[pos] = data;
    ps->size++;
}

// 顺序表删除pos位置的值
void SeqListErase(SeqList* ps, size_t pos)
{
    if(NULL == ps)
    {
        assert(0);
        return;
    }
    for(int i = pos+1; i < ps->size; i++)
    {
        ps->array[i-1] = ps->array[i];
    }
    ps->size--;
}

//检查顺序表是否为空
int SeqListEmpty(SeqList* ps)
{
    if(NULL == ps)
    {
        assert(0);
        return 0;
    }
    return ps->size == 0;
}

//求长度
int Seqlength(SeqList* ps)
{
    if(NULL == ps)
    {
        assert(0);
        return 0;
    }
    return ps->size;
}
