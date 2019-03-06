#include "common.h"

//input must be address
void swap(int* a, int* b)
{
    int c = 0;
    c = *a;
    *a = *b;
    *b = c;
}

void output(int* arr, int len)
{
    int i = 0;
    for(i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void random_array(int* arr, int len, int range)
{
    int i = 0;
    srand((unsigned int)time(NULL));
    for (i = 0; i <  len; i++)
    {
        arr[i] = rand() % range;
    }
}