#include "common.h"
#include "heap_sort.h"

/************************
** 堆的特性：
** //假设堆中元素个数为n(n>0),深度为h(h>0)
** 序号为0的节点是根
** 对于i > 0, 其父节点编号为(i-1)/2
** 若2*i + 1 < n, 其左子节点序号为2*i+1, 否则没有左子节点
** 若2*i + 2 < n, 其右子节点序号为2*i+2, 否则没有右子节点
** 堆最多有2^h - 1个节点
** 第k层最多有2^(k-1)个节点
*************************/

/***************************************************
** 小顶堆（最小堆）
****************************************************/
void shift_down(int* arr, int parentIndex, int len);
void shift_up(int* arr, int childIndex, int len);

void heap_sort(int* arr, int len)
{
    int i;
    for(i = 0; i < len; i++)
    {
        creat_heap(arr, len - i);
        swap(&arr[0], &arr[len - i - 1]);
    }
}

void creat_heap(int* arr, int len)
{
    int i;
    if(len < 2) return;
    //从倒数第二层最后一个节点开始，往上shift_down.
    for(i = len/2 - 1; i >= 0; i--)
    {
        shift_down(arr, i, len);
    }
}

void creat_heap2(int* arr, int len)
{
    int i;
    if(len < 2) return;
    for(i = 1; i < len; i++)
    {
        //printf("i = %d:\n");
        shift_up(arr, i, len);
    }
}

void shift_down(int* arr, int parentIndex, int len)
{
    int tmp        = arr[parentIndex];
    int childIndex = 2 * parentIndex + 1;
    while(childIndex < len)
    {
        if((childIndex + 1 < len)
                && (arr[childIndex] > arr[childIndex + 1]))
            childIndex++;
        if(tmp <= arr[childIndex])
            break;
        arr[parentIndex] = arr[childIndex];
        parentIndex      = childIndex;
        childIndex       = 2 * parentIndex + 1;
    }
    arr[parentIndex] = tmp;
}

void shift_up(int* arr, int childIndex, int len)
{
    int tmp         = arr[childIndex];
    int parentIndex = (childIndex - 1) / 2;

    //printf("     before while: arr[%d]=%d, arr[%d]=%d\n", childIndex, arr[childIndex], parentIndex, arr[parentIndex]);
    while(childIndex > 0 && tmp < arr[parentIndex])    //childIndex > 0; could not be parentIndex >= 0;
    {
        //printf("     in     while: childIndex = %d, parentIndex = %d\n", childIndex, parentIndex);
        arr[childIndex] = arr[parentIndex];
        childIndex      = parentIndex;
        parentIndex     = (childIndex - 1) / 2;
        //printf("                 : ");
        //output(arr, len);
    }
    arr[childIndex] = tmp;                            //the index should be childIndex.
    //printf("     after  while: childIndex = %d, parentIndex = %d\n                   ", childIndex, parentIndex);
    //output(arr, len);
}

void delete(int* arr, int len)
{
    int i;

    if(len < 1)
        return;

    if(len < 2)
    {
        arr[0] = 0;
        return;
    }
    
    arr[0] = arr[len - 1];
    arr[len - 1] = 0;
    for(i = 1; i < len - 2; i++)
    {
        shift_up(arr, i, len - 1);
    }
}

void insert()
{

}


void heap_remove()
{

}

void remove_at_index()
{

}

void search()
{

}

void replace()
{

}

void peek()
{

}

