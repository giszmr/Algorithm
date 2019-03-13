#include <time.h>
#include <sys/time.h>
#include <stdio.h>

#include "../src/bubble_sort.h"
#include "../src/quick_sort.h"
#include "../src/insert_sort.h"
#include "../src/shell_sort.h"
#include "../src/merge_sort.h"

#include "../src/counting_sort.h"
#include "../src/bucket_sort.h"
#include "../src/radix_sort.h"

#define LEN   10
#define RANGE 100

/******************************************************************************
** Linux FNSHC165 3.10.0-327.el7.x86_64 #1 SMP Thu Nov 19 22:10:57 UTC 2015 x86_64 x86_64 x86_64 GNU/Linux
** Array LEN         = 10,  100,  1,000,   10,000     100,000       1,000,000        10,000,000
** ///switch//////////
** bubble_sort(usec) = 2    95    8,000    500,000    47,000,000    4,800,000,000    ?segmentation fault
** quick_sort(usec)  = 2    27    200      3,000      40,000        400,000          ?segmentation fault
** ///insert//////////
** insert_sort       = 2    50    4,600    350,000    24,000,000    2,200,000,000    ?segmentation fault
** inser_sort2       = 2    20    2,000    150,000    10,000,000    900,000,000      ?segmentation fault
** shell_sort        = 2    20    300      4,000      56,000        600,000          ?segmentation fault
** ///select//////////
** select_sort       = 2    50    3,500    260,000    17,000,000    1,700,000,000    ?segmentation fault
** heap_sort         = 5    100   8,000    500,000    45,000,000    4,500,000,000    ?segmentation fault
** merge_srot        = 100  140   400      5,000      53,000        420,000          ?segmentation fault
** ///non-compare sort///////
** counting_sort     = 100  100   430      2,900      27,000        180,000          ?segmentation fault
** bucket_sort       = 70   140   4,000    300,000    69,000,000    ?
** radix_sort        = 60   98    350      3,600      38,000        280,000          ?segmentation fault
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
    //merge_sort(arr, 0, LEN - 1);

    /*****radix sort*******/
    counting_sort(arr, LEN);
    //bucket_sort(arr, LEN);
    //radix_sort(arr, LEN);

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


