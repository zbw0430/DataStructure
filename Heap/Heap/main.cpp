//
//  main.cpp
//  Heap
//
//  Created by 暖暖 on 2022/5/23.
//

#include "Heap.hpp"

int main(int argc, const char * argv[])
{
    // insert code here...
    Heap hp;
    int a[10] = { 5,3,6,1,9,2,0,7,8,4 };
    
    // 堆的构建
    HeapCreate(&hp, a, 10, Greater);
    for (int i = 0; i < 10; i++)
    {
        cout << hp._arr[i] << " ";
    }
    cout << endl;
    
    // 堆的销毁
    //yoid HeapDestory(Heap* hp);
    
    // 堆的删除
    HeapPop(&hp);
    cout << endl;
    for (int i = 0; i < hp._size; i++)
    {
        cout << hp._arr[i] << " ";
    }
    
    // 堆的插入
    HeapPush(&hp, -1);
    cout << endl;
    for (int i = 0; i < hp._size; i++)
    {
        cout << hp._arr[i] << " ";
    }
    
    // 取堆顶的数据
    cout << endl;
    cout << HeapTop(&hp) << endl;

    // 堆的数据个数
    cout << HeapSize(&hp) << endl;

    // 堆的判空
    cout << HeapEmpty(&hp) << endl;

    // 对数组进行堆排序
    HeapSort(a, 10, Greater);
    cout << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << a[i] << " ";
    }
    
    return 0;
}
