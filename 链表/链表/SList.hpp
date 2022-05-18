//
//  SList.hpp
//  链表
//
//  Created by 暖暖 on 2022/5/17.
//

#ifndef SList_hpp
#define SList_hpp

#include <stdio.h>

#pragma once
#include<iostream>
//#include<malloc.h>
#include "stdlib.h"
#include<assert.h>
#include "algorithm"
using namespace std;


typedef int SLTDateType;
typedef struct SListNode
{
    SLTDateType data;
    struct SListNode* next;
}SListNode;


// 动态申请一个节点
SListNode* BuySListNode(SLTDateType data);

// 单链表打印
void SListPrint(SListNode* plist);

// 单链表尾插
void SListPushBack(SListNode** pplist, SLTDateType x);

// 单链表的头插
void SListPushFront(SListNode** pplist, SLTDateType x);

// 单链表的尾删
void SListPopBack(SListNode** pplist);

// 单链表头删
void SListPopFront(SListNode** pplist);

// 单链表查找
SListNode* SListFind(SListNode* plist, SLTDateType x);

// 单链表在pos位置之后插入x
// 分析思考为什么不在pos位置之前插入？
void SListInsertAfter(SListNode* pos, SLTDateType x);


// 单链表删除pos位置之后的值
// 分析思考为什么不删除pos位置？
void SListEraseAfter(SListNode* pos);

//销毁链表
void SListDestroy(SListNode** ppList);

//反转链表
SListNode* reverseList(SListNode* plist );

//单链表删除pos位置
void SListDelCur(SListNode* pos);

#endif /* SList_hpp */
