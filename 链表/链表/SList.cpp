//
//  SList.cpp
//  链表
//
//  Created by 暖暖 on 2022/5/17.
//

#include "SList.hpp"

// 动态申请一个节点
SListNode* BuySListNode(SLTDateType data)
{
    SListNode* NewNode = (SListNode*)malloc(sizeof(SListNode));
    if(NewNode == NULL)
    {
        assert(NewNode);
    }
    NewNode->data = data;
    NewNode->next = NULL;
    return NewNode;
}

// 单链表打印
void SListPrint(SListNode* plist)
{
    //assert(plist);
    while(plist)
    {
        cout << plist->data;
        cout << "--->";
        plist = plist->next;
    }
    cout << "NULL" << endl;
}

// 单链表尾插
void SListPushBack(SListNode** pplist, SLTDateType x)
{
    assert(pplist);
    SListNode* NewNode = BuySListNode(x);
    //空和非空
    if(*pplist == NULL)
    {
        *pplist = NewNode;
    }
    else
    {
        SListNode* cur = *pplist;
            while(cur->next)
            {
                cur = cur->next;
            }
            cur->next = NewNode;
            NewNode->next = NULL;
    }
    
}

// 单链表的头插
void SListPushFront(SListNode** pplist, SLTDateType x)
{
    assert(pplist);
    SListNode* NewNode = BuySListNode(x);
    NewNode->next = *pplist;
    *pplist = NewNode;
}

// 单链表的尾删
void SListPopBack(SListNode** pplist)
{
    assert(pplist);
    //空链表
    if(*pplist == NULL)
    {
        return;
    }
    //只有一个节点
    else if((*pplist)->next == NULL)
    {
        free(*pplist);
        *pplist = NULL;
    }
    else
    {
        SListNode* cur = *pplist;
        SListNode* pre = NULL;
        while(cur->next)
        {
            pre = cur;
            cur = cur->next;
        }
        pre->next = NULL;
        free(cur);
    }
}

// 单链表头删
void SListPopFront(SListNode** pplist)
{
    assert(pplist);
    //空链表
    if(*pplist == NULL)
    {
        return;
    }
    //只有一个节点
    else if((*pplist)->next == NULL)
    {
        free(*pplist);
        *pplist = NULL;
    }
    else
    {
        SListNode* cur = *pplist;
        *pplist = (*pplist)->next;
        free(cur);
    }
}

// 单链表查找
SListNode* SListFind(SListNode* plist, SLTDateType x)
{
    assert(plist);
    while(plist)
    {
        if(plist->data == x)
        {
            return plist;
        }
        else
        {
            plist = plist->next;
        }
    }
    return NULL;
}

// 单链表在pos位置之后插入x
void SListInsertAfter(SListNode* pos, SLTDateType x)
{
    assert(pos);
    SListNode* NewNode = BuySListNode(x);
    NewNode->next = pos->next;
    pos->next = NewNode;
}

// 单链表删除pos位置之后的值
void SListEraseAfter(SListNode* pos)
{
    assert(pos);
    if(pos->next)
    {
        SListNode* cur = pos->next;
        pos->next = pos->next->next;
        free(cur);
    }
    else return;
}

//销毁链表
void SListDestroy(SListNode** ppList)
{
    assert(ppList);
    SListNode* cur = *ppList;
    while(cur)
    {
        *ppList = cur->next;
        free(cur);
        cur = *ppList;
    }
}

//反转链表
SListNode* reverseList(SListNode* plist )
{
    SListNode* p;
    for(p = NULL; plist; swap(plist,p))
    {
        swap(p, plist->next);
    }
    return p;
}

//单链表删除pos位置
void SListDelCur(SListNode* pos)
{
    assert(pos);
    SListNode* next = pos->next;
    pos->data = pos->next->data;
    pos->next = pos->next->next;
    free(next);
}
