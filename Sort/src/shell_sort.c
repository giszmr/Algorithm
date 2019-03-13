#include "common.h"
#include "shell_sort.h"


void shell_sort(int* arr, int len)
{
    int i, j, k;
    int gap = 0;
    int key = 0;
    
    while(gap < len/3)
        gap = gap * 3 + 1;
    do{
        //printf("*gap[%d]*\n", gap);
        for(i = 0; i < gap; i++)
        {
            //printf("i[%d]:\n", i);
            //insert sort
            for(j = i; j < len - gap; j += gap)
            {
                key = arr[j+gap];
                //printf("     j[%d]:\n", j);
                //printf("          key=arr[%d+%d]=%d\n", j, gap, key);
                for(k = j; k >= 0 && key < arr[k]; k -= gap)
                {
                    //printf("          switch arr[%d+%d] and arr[%d]:\n          ", k, gap, k);
                    arr[k+gap] = arr[k];
                    //output(arr, len);
                }
                //after loop, k already minus gap. so plus gap.
                arr[k+gap] = key;
                //printf("     ");
                //output(arr, len);
            }
        }
        gap = gap / 3;   //reduce gap
    }while(gap > 0);
}