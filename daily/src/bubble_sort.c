#include "bubble_sort.h"
#include "common.h"

void bubble_sort(int* arr, int len)
{
    int i = 0;
    int j = 0;
    //Compare from arr[len] to arr[i]
    for(i = 0; i < len; i++)
    {
        for(j = len - 1; j > i; j--) //condition must be "j > i"
        {
            if(arr[j] < arr[j-1])
                swap(&arr[j], &arr[j-1]);
        }
    }
}

