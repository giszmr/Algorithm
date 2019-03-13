#include "counting_sort.h"
#include "common.h"




void counting_sort(int* arr, int len)
{
    int *tmpArr = NULL;
    int i;
    int tmpLen = 0;
    int max = arr[0];

    for (i = 0; i < len; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    tmpLen = max + 1;
    tmpArr = (int*)malloc(sizeof(int) * tmpLen);
    memset(tmpArr, 0, sizeof(int) * tmpLen);
    
    for (i = 0; i < len; i++)
    {
        tmpArr[arr[i]]++;
    }
    
    for (i = 0; i < tmpLen; i++)
    {
        while(tmpArr[i]--)
        {
            *arr++ = i;
        }
    }
    
    free(tmpArr);
}