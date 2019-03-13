#include "common.h"
#include "heap_sort.h"

/************************
** �ѵ����ԣ�
** //�������Ԫ�ظ���Ϊn(n>0),���Ϊh(h>0)
** ���Ϊ0�Ľڵ��Ǹ�
** ����i > 0, �丸�ڵ���Ϊ(i-1)/2
** ��2*i + 1 < n, �����ӽڵ����Ϊ2*i+1, ����û�����ӽڵ�
** ��2*i + 2 < n, �����ӽڵ����Ϊ2*i+2, ����û�����ӽڵ�
** �������2^h - 1���ڵ�
** ��k�������2^(k-1)���ڵ�
*************************/

/***************************************************
** С���ѣ���С�ѣ�
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
    //�ӵ����ڶ������һ���ڵ㿪ʼ������shift_down.
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

