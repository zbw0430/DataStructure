//
//  main.cpp
//  链表
//
//  Created by 暖暖 on 2022/5/17.
//

#include "SList.hpp"

int main(int argc, const char * argv[])
{
    // insert code here...
    
    SListNode* L = NULL;
    
    // 单链表尾插
    SListPushBack(&L, 1);
    SListPushBack(&L, 2);
    // 单链表的头插
    SListPushFront(&L, 3);
    SListPushFront(&L, 4);
    // 单链表打印
    SListPrint(L);
    
    // 单链表的尾删
    SListPopBack(&L);
    SListPrint(L);
    // 单链表头删
    SListPopFront(&L);
    SListPrint(L);

    // 单链表在pos位置之后插入x
    SListInsertAfter(SListFind(L, 3), 5);
    SListPrint(L);

    // 单链表删除pos位置之后的值
    SListEraseAfter(SListFind(L, 3));
    SListPrint(L);

    //反转链表
    SListNode* P = reverseList(L);
    SListPrint(P);

    //单链表删除pos位置
    SListDelCur(SListFind(P, 1));
    SListPrint(P);
    
    //销毁链表
    SListDestroy(&P);
    SListPrint(P);
    
    return 0;
}
