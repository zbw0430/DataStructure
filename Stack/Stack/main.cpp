//
//  main.cpp
//  Stack
//
//  Created by 暖暖 on 2022/5/18.
//

#include <iostream>
#include "Stack.hpp"

int main(int argc, const char * argv[])
{
    // insert code here...
    
    Stack sta;
    //栈的初始化
    StackInit(&sta);

    // 入栈
    StackPush(&sta,1);
    StackPush(&sta,2);
    StackPush(&sta,3);

    // 出栈
    StackPop(&sta);

    // 获取栈顶元素
    cout << StackTop(&sta) << endl;

    // 获取栈中有效元素个数
    cout << StackSize(&sta) << endl;

    // 检测栈是否为空，如果为空返回非零结果，如果不为空返回0
    cout << StackEmpty(&sta) << endl;

    // 销毁栈
    StackDestroy(&sta);
    cout << StackSize(&sta) << endl;
    
    return 0;
}
