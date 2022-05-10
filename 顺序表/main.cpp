//
//  main.cpp
//  2022.5.6
//
//  Created by 暖暖 on 2022/5/6.
//

#include "SeqList.hpp"

int main()
{
    SeqList s;
    // 顺序表初始化
    SeqListInit(&s, 10);
    
    // 顺序表头插
    SeqListPushFront(&s, 1);
    // 顺序表尾插
    SeqListPushBack(&s, 3);
    // 顺序表在下标为1的位置插入2
    SeqListInsert(&s, 1, 2);
    //检查顺序表是否为空
    SeqListEmpty(&s);
    // 顺序表打印
    SeqListPrint(&s);
    //求长度
    int num1 = Seqlength(&s);;
    cout << num1 << endl;
    // 顺序表查找
    int num2 = SeqListFind(&s, 2);
    cout << num2 << endl;
    // 顺序表尾删
    SeqListPopBack(&s);
    // 顺序表打印
    SeqListPrint(&s);
    // 顺序表头删
    SeqListPopFront(&s);
    // 顺序表打印
    SeqListPrint(&s);
    // 顺序表删除pos位置的值
    SeqListErase(&s, 0);
    
    // 顺序表销毁
    SeqListDestory(&s);
   
   
    return 0;
}
