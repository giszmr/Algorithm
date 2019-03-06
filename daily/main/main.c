#include <time.h>
#include <sys/time.h>
#include <stdio.h>

#include "../src/bubble_sort.h"
#include "../src/quick_sort.h"
#include "../src/insert_sort.h"
#include "../src/shell_sort.h"
#include "../src/merge_sort.h"

#define LEN   10
#define RANGE 10

/******************************************************************************
** Linux FNSHC165 3.10.0-327.el7.x86_64 #1 SMP Thu Nov 19 22:10:57 UTC 2015 x86_64 x86_64 x86_64 GNU/Linux
** Array LEN        = 10,  100,  1,000,   10,000     100,000       1,000,000        10,000,000
** ///switch//////////
** BubbleSort(usec) = 2    95    8,000    500,000    47,000,000    4,800,000,000    ?
** QuickSort(usec)  = 2    27    200      3,000      40,000        400,000          ?
** ///insert//////////
** insertSort       = 2    50    4,600    350,000    24,000,000    2,200,000,000    ?
** inserSort2       = 2    20    2,000    150,000    10,000,000    900,000,000      ?
** shellSort        = 2    20    300      4,000      56,000        600,000          ?
** ///select//////////
** selectSort       = 2    50    3,500    260,000    17,000,000    1,700,000,000    ?
** heapSort         = 5    100   8,000    500,000    45,000,000    4,500,000,000    ?
** mergeSrot        = 100  140   400      5,000      53,000        420,000          ?
*******************************************************************************/


int main(int argc, char* argv[])
{
    int arr[LEN] = {0};
    struct timeval  tv_begin = {0};
    struct timeval  tv_end = {0};

    random_array(arr, LEN, RANGE);

    //output the initial state of the array
    //output(arr, LEN);

    //begin time stamp
    gettimeofday(&tv_begin, NULL);

    /*****switch sort******/
    //bubble_sort(arr, LEN);
    //quick_sort(arr, 0, LEN-1);
    
    /*****insert sort******/
    //insert_sort(arr, LEN);
    //insert2_sort(arr, LEN);  //0.5 time of insert_sort().
    //shell_sort(arr, LEN);
    
    /*****select sort******/
    //select_sort(arr, LEN);
    //heap_sort(arr, LEN);
    
    /*****merge sort******/
    merge_sort(arr, 0, LEN - 1);

    //end time stamp
    gettimeofday(&tv_end, NULL);

    //output the sorted array
    //output(arr, LEN);

    printf("begin[%ld] end[%ld]  time: %ld\n",
            (tv_begin.tv_sec * 1000 * 1000 + tv_begin.tv_usec),
            (tv_end.tv_sec * 1000 * 1000 + tv_end.tv_usec),
            (tv_end.tv_sec * 1000 * 1000 + tv_end.tv_usec) - (tv_begin.tv_sec * 1000 * 1000 + tv_begin.tv_usec));

    return 0;
}


