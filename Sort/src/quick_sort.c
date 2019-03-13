#include "quick_sort.h"
#include "common.h"

void quick_sort(int* arr, int begin, int end)
{
    int key  = begin;
    int left  = begin;
    int right = end;
    
    if (begin < 0 || end < 0 
        || begin >= end)
        return;
    
    while(left < right)
    {
        while(left < right && arr[left] <= arr[key])
            left++;
        while(left < right && arr[right] >= arr[key])
            right--;
        
        swap(&arr[left], &arr[right]);
    }
    //printf("key[%d], left[%d], right[%d], arr[left]=%d, arr[right]=%d\n",
    //    key, left, right, arr[left], arr[key]);
    if (arr[left] < arr[key])            //this condition is important
        swap(&arr[left], &arr[key]);
    //output(arr, end + 1);
    
    quick_sort(arr, begin, left - 1);   //should be "left - 1", could not be "left" 
    quick_sort(arr, left, end);         //left
}

