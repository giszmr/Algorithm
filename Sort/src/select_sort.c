#include "common.h"
#include "select_sort.h"

void select_sort(int* arr, int len)
{
    int i, j;
    int index = 0;
    for(i = 0; i < len - 1; i++)
    {
        index = i;
        for(j = i + 1; j < len; j ++)
        {
            if(arr[j] < arr[index])
                index = j;
        }
        if(index != i)
            swap(&arr[i], &arr[index]);
    }
}

