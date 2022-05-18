//
//  main.cpp
//  带头结点的双向循环链表
//
//  Created by 暖暖 on 2022/5/18.
//

#include <iostream>
#include "DList.hpp"

int main(int argc, const char * argv[])
{
    // insert code here...
    
    //创建头结点
    DListNode* head = CreatDList();

    // 链表尾插
    DListPushBack(head, 1);
    DListPushBack(head, 2);
    // 链表的头插
    DListPushFront(head,3);
    DListPushFront(head,4);
    DListPrint(head);

    // 链表的尾删
    DListPopBack(head);
    DListPrint(head);

    // 链表头删
    DListPopFront(head);
    DListPrint(head);

    // 链表在pos位置之后插入x
    DListInsertAfter(DListFind(head, 3), 5);
    DListPrint(head);

    // 链表删除pos位置的值
    DListEraseCur(DListFind(head, 5));
    DListPrint(head);

    //销毁链表
    SListDestroy(&head);
    DListPrint(head);

    return 0;
}
