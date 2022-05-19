//
//  main.cpp
//  Queue
//
//  Created by 暖暖 on 2022/5/18.
//

#include "Queue.hpp"

int main(int argc, const char * argv[])
{
    // insert code here...
    
    Queue q;
    // 初始化队列
    QueueInit(&q);
    // 队尾入队列
    QueuePush(&q,1);
    QueuePush(&q,2);
    QueuePush(&q,3);
    // 队头出队列
    QueuePop(&q);
    // 获取队列头部元素
    cout << QueueFront(&q)<< endl;
    // 获取队列队尾元素
    cout << QueueBack(&q) << endl;
    // 获取队列中有效元素个数
    cout << QueueSize(&q) << endl;
    // 销毁队列
    QueueDestroy(&q);

    return 0;
}
