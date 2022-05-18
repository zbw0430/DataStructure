//
//  DList.cpp
//  带头结点的双向循环链表
//
//  Created by 暖暖 on 2022/5/18.
//

#include "DList.hpp"

/*
typedef struct DListNode
{
    DLTDateType data;
    struct DListNode* next;
    struct DListNode* prev;
}DListNode;
*/

//动态申请一个节点
DListNode* BuyDListNode(DLTDateType data)
{
    DListNode* NewNode = (DListNode*)malloc(sizeof(DListNode));
    if(NULL == NewNode)
    {
        return NULL;
    }
    NewNode->data = data;
    NewNode->next = NULL;
    NewNode->prev = NULL;
    return NewNode;
}

//创建头结点
DListNode* CreatDList()
{
    DListNode* head = BuyDListNode(-1);
    head->next = head;
    head->prev = head;
    return head;
}

// 链表打印
void DListPrint(DListNode* pHead)
{
    if(NULL == pHead)
    {
        cout << "NULL" <<endl;
        return;
    }
    cout << "head-->";
    DListNode* cur = pHead->next;
    while(cur != pHead)
    {
        cout << cur->data << "-->";
        cur = cur->next;
    }
    cout << "head" << endl;
}

//尾插
void DListPushBack(DListNode* pHead, DLTDateType x)
{
    if(NULL == pHead)
    {
        return;
    }
    //申请节点
    DListNode* NewNode = BuyDListNode(x);
    NewNode->prev = pHead->prev;
    NewNode->next = pHead;
    pHead->prev->next = NewNode;
    pHead->prev = NewNode;
}

// 链表的头插
void DListPushFront(DListNode* pHead, DLTDateType x)
{
    if(NULL == pHead)
    {
        return;
    }
    DListNode* NewNode = BuyDListNode(x);
    NewNode->next = pHead->next;
    NewNode->prev = pHead;
    pHead->next->prev = NewNode;
    pHead->next = NewNode;
}

// 链表的尾删
void DListPopBack(DListNode* pHead)
{
    if(NULL == pHead || pHead == pHead->next)
    {
        return;
    }
    pHead->prev = pHead->prev->prev;
    free(pHead->prev->next);
    pHead->prev->next = pHead;
}

// 链表头删
void DListPopFront(DListNode* pHead)
{
    if(NULL == pHead || pHead == pHead->next)
    {
        return;
    }
    DListNode* DelNode = pHead->next;
    DelNode->next->prev = pHead;
    pHead->next = DelNode->next;
    free(DelNode);
}

// 链表查找
DListNode* DListFind(DListNode* pHead, DLTDateType x)
{
    if(NULL == pHead)
    {
        return NULL;
    }
    DListNode* cur = pHead->next;
    while(cur != pHead)
    {
        if(cur->data == x)
        {
            return cur;
        }
        cur = cur->next;
    }
    return NULL;
}

// 链表在pos位置之后插入x
void DListInsertAfter(DListNode* pos, DLTDateType x)
{
    if(NULL == pos)
    {
        return;
    }
    DListNode* NewNode = BuyDListNode(x);
    NewNode->next = pos->next;
    NewNode->prev = pos;
    pos->next = NewNode;
    NewNode->next->prev = NewNode;
}

// 链表删除pos位置的值
void DListEraseCur(DListNode* pos)
{
    if(NULL == pos)
    {
        return;
    }
    pos->prev->next = pos->next;
    pos->next->prev = pos->prev;
    free(pos);
}

//销毁链表
void SListDestroy(DListNode** pHead)
{
    if(NULL == pHead)
    {
        return;
    }
    DListNode* cur = (*pHead)->next;
    while(cur != (*pHead))
    {
        (*pHead)->next = cur->next;
        free(cur);
        cur = (*pHead)->next;
    }
    free(*pHead);
    *pHead = NULL;
}
