//
//  Heap.cpp
//  Heap
//
//  Created by 暖暖 on 2022/5/23.
//

#include "Heap.hpp"


int Less(int left, int right)
{
    return left < right;
}
int Greater(int left, int right)
{
    return left > right;
}
void Swap(HPDataType* left, HPDataType* right)
{
    HPDataType temp = *left;
    *left = *right;
    *right = temp;
}


//扩容
void CheckCapacity(Heap* hp)
{
    if (NULL == hp)
    {
        return;
    }
    if (hp->_size == hp->_capacity)
    {
        HPDataType* temp = (HPDataType*)malloc(sizeof(HPDataType)*(hp->_capacity * 2));
        if (NULL == temp)
        {
            return;
        }
        for (int i = 0; i < hp->_size; i++)
        {
            temp[i] = hp->_arr[i];
        }
        free(hp->_arr);
        hp->_arr = temp;
        hp->_capacity *= 2;
    }
}


//向上调整
void AdjustUp(Heap* hp, int child)
{
    int parent = (child - 1) / 2;
    while (child)
    {
        //小根堆 if (hp->_arr[child] < hp->_arr[parent])
        //大根堆 if (hp->_arr[child] > hp->_arr[parent])
        if (hp->compare(hp->_arr[child],hp->_arr[parent]))
        {
            Swap(&(hp->_arr[child]), &(hp->_arr[parent]));
            child = parent;
            parent=(child - 1) / 2;
        }
        else
        {
            return;
        }
    }
}

//向下调整
void AdjustDown(Heap* hp, int parent)
{
    int child = parent * 2 + 1;
    while (child < hp->_size)
    {
        //右孩子存在且右孩子小于左孩子
        //if (child + 1 < hp->_size &&hp->_arr[child + 1] < hp->_arr[child])
        if (child + 1 < hp->_size && hp->compare(hp->_arr[child + 1] , hp->_arr[child]))
        {
            child++;
        }
        //if (hp->_arr[child] < hp->_arr[parent])
        if (hp->compare(hp->_arr[child] , hp->_arr[parent]))
        {
            Swap(&(hp->_arr[child]), &(hp->_arr[parent]));
            parent = child;
            child = parent * 2 + 1;
        }
        else
        {
            return;
        }
    }
}


//堆的构建
void HeapCreate(Heap * hp, HPDataType * a, int n, pCompare comper)
{
    if (NULL == hp)
    {
        return;
    }
    hp->_arr = (HPDataType*)malloc(sizeof(HPDataType)*n);
    if (NULL == hp->_arr)
    {
        return;
    }
    memcpy(hp->_arr, a, sizeof(HPDataType)*n);
    hp->_capacity = n;
    hp->_size = n;
    hp->compare = comper;

    //从第一个非叶子节点开始依次向下调整
    for (int root =(n-2)/2; root >= 0; root--)
    {
        AdjustDown(hp, root);
    }
}

//堆的销毁
void HeapDestory(Heap * hp)
{
    if (NULL == hp)
    {
        return;
    }
    free(hp->_arr);
    hp->_arr = NULL;
    hp->_size = 0;
    hp->_capacity = 0;
    hp = NULL;
}

//堆的插入
void HeapPush(Heap * hp, HPDataType x)
{
    if (NULL == hp)
    {
        return;
    }
    CheckCapacity(hp);
    hp->_arr[hp->_size] = x;//把元素插入到最后
    hp->_size++;
    AdjustUp(hp, hp->_size - 1);//向上调整
}

//堆的删除（删除堆顶元素）
void HeapPop(Heap * hp)
{
    if (NULL == hp)
    {
        return;
    }
    Swap(&(hp->_arr[0]), &(hp->_arr[hp->_size - 1]));//把堆顶元素和最后一个元素交换
    hp->_size--;
    AdjustDown(hp, 0);//向下调整
}

// 取堆顶的数据
HPDataType HeapTop(Heap * hp)
{
    if (NULL == hp || HeapEmpty(hp))
    {
        return -1;
    }
    return hp->_arr[0];
}

// 堆的数据个数
int HeapSize(Heap * hp)
{
    if (NULL == hp)
    {
        return -1;
    }
    return hp->_size;
}

// 堆的判空
int HeapEmpty(Heap * hp)
{
    if (NULL == hp)
    {
        return -1;
    }
    return 0==hp->_size;
}

//排序适用的向下调整
void Adjust(Heap *hp, int parent, int end)
{
    int child = parent * 2 + 1;
    while (child < end)//！！！！end
    {
        
        if (child + 1 < end &&hp->compare(hp->_arr[child + 1] , hp->_arr[child]))
        {
            child++;
        }
        if (hp->compare(hp->_arr[child] , hp->_arr[parent]))
        {
            Swap(&(hp->_arr[child]), &(hp->_arr[parent]));
            parent = child;
            child = parent * 2 + 1;
        }
        else
        {
            return;
        }
    }
}

//对数组进行堆排序
void HeapSort(int * a, int n, pCompare comper)
{
    Heap hp;
    //建堆（已经按堆的方式排列好了）
    HeapCreate(&hp, a, n, comper);

    int end = hp._size - 1;
    while (end)
    {
        Swap(&(hp._arr[0]), &(hp._arr[end]));//第一个和最后一个交换，即把最大的或者最小的排在后面
        Adjust(&hp, 0, end);
        end--;
    }
    memcpy(a, hp._arr, sizeof(HPDataType)*n);
}
