#include "radix_sort.h"
#include "common.h"

void radix_sort(int* arr, int len)
{
    int* counter = (int*)malloc(10 * sizeof(int));
    int* tmpArr  = (int*)malloc(len * sizeof(int));
    int i, j, exp;
    int max = 0;
    int sum = 0;
    memset(counter, 0, 10 * sizeof(int));
    memset(tmpArr, 0, len * sizeof(int));

    //get max number of this array.
    for(i = 0; i < len; i++)
    {
        if (max < arr[i])
            max = arr[i];
    }
//printf("zhumengri line[%d] max = %d\n", __LINE__, max);
    for(exp = 1; max / exp > 0; exp *= 10)
    {
//printf("    zhumengri line[%d]: counter -- ", __LINE__, max);
//output(counter, 10);
        //get number of each bucket
        for(i = 0; i < len; i++)
        {
//printf("        (arr[%d] / %d) % 10 = %d\n", i, exp, (arr[i] / exp) % 10);
            counter[(arr[i] / exp) % 10]++;
        }
//printf("    zhumengri line[%d]: counter -- ", __LINE__, max);
//output(counter, 10);

        //caculate the number of each digit
        for(i = 1; i < 10; i++)
        {
            counter[i] += counter[i - 1];
        }
//printf("    zhumengri line[%d]: counter -- ", __LINE__, max);
//output(counter, 10);
        for(i = 9; i > 0; i--)
        {
            counter[i] = counter[i - 1];
        }
        counter[0] = 0;
//printf("    zhumengri line[%d]: counter -- ", __LINE__);
//output(counter, 10);

        //radix sort, store data to temporary array.
        for(i = 0; i < len; i++)
        {
            tmpArr[counter[(arr[i] / exp) % 10]] = arr[i];
            counter[(arr[i] / exp) % 10]++;
        }
//printf("    zhumengri line[%d]: tmpArr  -- ", __LINE__);
//output(tmpArr, len);
        //restore data to arr
        for(i = 0; i < len; i++)
        {
            arr[i] = tmpArr[i];
        }

        //clear array --- important////
        memset(counter, 0, 10 * sizeof(int));
        memset(tmpArr, 0, len * sizeof(int));
    }
    free(counter);
    free(tmpArr);
}