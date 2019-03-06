#include "insert_sort.h"
#include "common.h"

//need swap
void insert_sort(int* arr, int len)
{
    int i = 0;
    int j = 0;

    for(i = 0; i < len - 1; i++)
    {
        for(j = i + 1; j > 0; j--)
        {
            if(arr[j] >= arr[j - 1])
                break;
            else
                swap(&arr[j], &arr[j-1]);
        }
    }
}


//do not need swap
void insert2_sort(int* arr, int len)
{
    int i = 0;
    int j = 0;
    int key = 0;

    for(i = 0; i < len - 1; i++)
    {
        key = arr[i+1];
        for(j = i; j >= 0; j--)
        {
            if(key >= arr[j])//could place this statement in side loop condition
            {
                //after break, j1 = j2
                //printf("j1 = %d ", j);
                break;
            }
            else
                arr[j+1] = arr[j];
        }
        //printf("j2 = %d\n", j);
        arr[j+1] = key;
        //output(arr, len);
    }
}
