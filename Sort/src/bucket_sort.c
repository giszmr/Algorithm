#include "bucket_sort.h"
#include "common.h"
#include "quick_sort.h"

#define DEFAULT_BUCKET_SIZE 10


//void bucket_sort(int* arr, int len, int bucketSize)
void bucket_sort(int* arr, int len)
{
    int i, j;
    int index = 0;
    int space = 0;
    int min = arr[0];
    int max = arr[0];
    int bucketCount = 0;
    int **tmpArr = NULL;
    int row = 0;
    int col = 0;
    int *bucketLenArr = NULL;

    //if (bucketSize < DEFAULT_BUCKET_SIZE)
    //    bucketSize = DEFAULT_BUCKET_SIZE;
//printf("%d:\n", __LINE__);
    for (i = 0; i < len; i++)
    {
        if (arr[i] < min)
            min = arr[i];
        else if (arr[i] > max)
            max = arr[i];
    }

    //bucketCount = (max - min) / bucketSize + 1;
    bucketCount = (max - min) / DEFAULT_BUCKET_SIZE + 1;
    space = (max - min) / bucketCount + 1;        //must +1   ??????
//printf("%d: min[%d] max[%d] bucketCount[%d] space[%d]\n", __LINE__, min, max, bucketCount, space);
    tmpArr = (int**)malloc(sizeof(int*) * bucketCount);
    memset(tmpArr, 0, sizeof(int*) * bucketCount);
    for (i = 0; i < bucketCount; i++)
    {
        tmpArr[i] = (int*)malloc(sizeof(int) * len);
        memset(tmpArr[i], 0, sizeof(int) * len);
    }

    bucketLenArr = (int*)malloc(sizeof(int) * bucketCount);
    memset(bucketLenArr, 0, sizeof(int) * bucketCount);
//printf("%d:\n", __LINE__);
    for (i = 0; i < len; i++)
    {
        index = (arr[i] - min) / space;
//printf("%d: arr[%d]=%d index=%d\n", __LINE__, i, arr[i], index);
        for (j = 0; j < len; j++)
        {
//printf("%d:\n", __LINE__);
            if (tmpArr[index][j] == 0)
            {
                tmpArr[index][j] = arr[i];
                bucketLenArr[index]++;
//printf("%d: arr[%d]=%d bucketLenArr[%d]=%d\n", __LINE__, i, arr[i], index, bucketLenArr[index]);
                break;
            }
        }
    }
//printf("%d:\n", __LINE__);
//output(bucketLenArr, bucketCount);
    for (i = 0; i < bucketCount; i++)
    {
        quick_sort(tmpArr[i], 0, bucketLenArr[i] - 1);
    }
//printf("%d:\n", __LINE__);
    for (i = 0; i < bucketCount; i++)
    {
        for (j = 0; j < bucketLenArr[i]; j++)
        {
            *arr++ = tmpArr[i][j];
        }
    }

    for (i = 0; i < bucketCount; i++)
    {
        free(tmpArr[i]);
    }
    free(tmpArr);
    
}

