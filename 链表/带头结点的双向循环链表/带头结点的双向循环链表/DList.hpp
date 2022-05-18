//
//  DList.hpp
//  带头结点的双向循环链表
//
//  Created by 暖暖 on 2022/5/18.
//

#ifndef DList_hpp
#define DList_hpp

#include <stdio.h>

#pragma once
#include<iostream>
#include<stdlib.h>
#include<assert.h>
using namespace std;

//带头结点的双向循环链表

typedef int DLTDateType;
typedef struct DListNode
{
    DLTDateType data;
    struct DListNode* next;
    struct DListNode* prev;
}DListNode;

//创建头结点
DListNode* CreatDList();

// 动态申请一个节点
DListNode* BuyDListNode(DLTDateType data);

// 链表打印
void DListPrint(DListNode* pHead);

// 链表尾插
void DListPushBack(DListNode* pHead, DLTDateType x);

// 链表的头插
void DListPushFront(DListNode* pHead, DLTDateType x);

// 链表的尾删
void DListPopBack(DListNode* pHead);

// 链表头删
void DListPopFront(DListNode* pHead);

// 链表查找
DListNode* DListFind(DListNode* pHead, DLTDateType x);

// 链表在pos位置之后插入x
void DListInsertAfter(DListNode* pos, DLTDateType x);

// 链表删除pos位置的值
void DListEraseCur(DListNode* pos);

//销毁链表
void SListDestroy(DListNode** pHead);


#endif /* DList_hpp */
