#include "merge_sort.h"
#include "common.h"
#include <stdlib.h>


void merge(int* arr, int left, int mid, int right);

void merge_sort(int* arr, int left, int right)
{
    int mid = (left + right) / 2;
    if (arr == NULL || left < 0 || right < 0 || left >= right)
        return;

    merge_sort(arr, left, mid);
    merge_sort(arr, mid + 1, right);
    
    merge(arr, left, mid, right);
    
}

void merge(int* arr, int left, int mid, int right)
{
    int i     = left;
    int j     = mid + 1;
    int index = 0;

    int* tmpArr = (int*)malloc((right - left + 1) * sizeof(int));

    while(i <= mid && j <= right)
    {
        if(arr[i] <= arr[j])
        {
            tmpArr[index++] = arr[i++];
        }
        else
        {
            tmpArr[index++] = arr[j++];
        }
    }

    while(i <= mid)
        tmpArr[index++] = arr[i++];

    while(j <= right)
        tmpArr[index++] = arr[j++];

    for(i = 0; i < index; i++)
    {
        arr[left + i] = tmpArr[i];
    }
    free(tmpArr);

}

