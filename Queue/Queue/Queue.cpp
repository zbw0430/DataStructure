//
//  Queue.cpp
//  Queue
//
//  Created by 暖暖 on 2022/5/18.
//

#include "Queue.hpp"

//创建节点
QNode* BuyQNode(QDataType x)
{
    QNode* NewNode = (QNode*) malloc (sizeof(QNode));
    if(NULL == NewNode)
    {
        return NULL;
    }
    NewNode->_pNext = NULL;
    NewNode->_data = x;
    return NewNode;
}

// 初始化队列
void QueueInit(Queue* q)
{
    if(NULL == q)
    {
        return;
    }
    QNode* NewNode = BuyQNode(0);
    q->_front = NewNode;
    q->_rear = NewNode;
    q->size = 0;
}

// 队尾入队列
void QueuePush(Queue* q, QDataType data)
{
    if(NULL == q)
    {
        return;
    }
    QNode* NewNode = BuyQNode(data);
    q->_rear->_pNext = NewNode;
    q->_rear = NewNode;
    q->size++;
    
}

// 队头出队列
void QueuePop(Queue* q)
{
    if(NULL == q || QueueEmpty(q) == 1)
    {
        return;
    }
    QNode* DelNode = q->_front->_pNext;
    q->_front->_pNext = DelNode->_pNext;
    free(DelNode);
    q->size--;
    if(q->size == 0)
    {
        q->_rear = q->_front;
    }
}

// 获取队列头部元素
QDataType QueueFront(Queue* q)
{
    if(NULL == q || QueueEmpty(q) == 1)
    {
        return -1;
    }
    return q->_front->_pNext->_data;
}

// 获取队列队尾元素
QDataType QueueBack(Queue* q)
{
    if(NULL == q || QueueEmpty(q) == 1)
    {
        return -1;
    }
    return q->_rear->_data;
}

// 获取队列中有效元素个数
int QueueSize(Queue* q)
{
    if(NULL == q)
    {
        return -1;
    }
    return q->size;
}

// 检测队列是否为空，如果为空返回非零结果，如果非空返回0
int QueueEmpty(Queue* q)
{
    if(NULL == q)
    {
        return -1;
    }
    return q->size == 0;
}

// 销毁队列
void QueueDestroy(Queue* q)
{
    if(NULL == q)
    {
        return;
    }
    while(!QueueEmpty(q))
    {
        QueuePop(q);
    }
    free(q->_front);
    q = NULL;
}
