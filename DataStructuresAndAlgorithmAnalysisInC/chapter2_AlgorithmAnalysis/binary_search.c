#include <stdio.h>
#include <sys/time.h>

#define LEN   1000
#define RANGE 10000

// len   1000
//       80

void random_array(int* arr, int len, int range);
void quick_sort(int* arr, int begin, int end);
void output(int* arr, int len);
int binary_search(int* arr, int len, int element);

int main(int argc, char* argv[])
{
    int index       = 0;
    int element     = 0;
    int arr[LEN]    = {0};
    struct timeval  tv_begin = {0};
    struct timeval  tv_end   = {0};

    random_array(arr, LEN, RANGE);
    quick_sort(arr, 0, LEN);

    srand((unsigned int)time(NULL));
    element = rand() % RANGE;

    //begin time stamp
    gettimeofday(&tv_begin, NULL);
    index   = binary_search(arr, LEN, element);
    //end time stamp
    gettimeofday(&tv_end, NULL);

    output(arr, LEN);
    printf("element = %d, index[%d], begin[%ld] end[%ld]  time: %ld\n",
            element, index,
            (tv_begin.tv_sec * 1000 * 1000 + tv_begin.tv_usec),
            (tv_end.tv_sec * 1000 * 1000 + tv_end.tv_usec),
            (tv_end.tv_sec * 1000 * 1000 + tv_end.tv_usec) - (tv_begin.tv_sec * 1000 * 1000 + tv_begin.tv_usec));

    return 0;
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

//input must be address
void swap(int* a, int* b)
{
    int c = 0;
    c = *a;
    *a = *b;
    *b = c;
}

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

void output(int* arr, int len)
{
    int i = 0;
    for(i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int binary_search(int* arr, int len, int element)
{
    int mid  = 0;
    int low  = 0;
    int high = len - 1;
    while(low <= high)
    {
    printf("low[%d]  high[%d]\n", low, high);
        mid = (low + high) / 2;
        if(element > arr[mid])
            low = mid + 1;
        else if(element < arr[mid])
            high = mid - 1;
        else
            return mid;
    }
    return -1;
}
