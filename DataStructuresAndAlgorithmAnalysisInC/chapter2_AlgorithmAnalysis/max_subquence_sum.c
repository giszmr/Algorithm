#include <stdio.h>
#include <sys/time.h>

#define LEN   10
#define RANGE 100

void random_array(int* arr, int len, int range);
void output(int* arr, int len);
int max_subsequence_sum(int* arr, int len);

int main(int argc, char* argv[])
{
    int sum         = 0;
    int arr[LEN]    = {0};
    struct timeval  tv_begin = {0};
    struct timeval  tv_end   = {0};

    random_array(arr, LEN, RANGE);
    
    //begin time stamp
    gettimeofday(&tv_begin, NULL);
    sum = max_subsequence_sum(arr, LEN);
    //end time stamp
    gettimeofday(&tv_end, NULL);

    output(arr, LEN);
    printf("sum = %d, begin[%ld] end[%ld]  time: %ld\n",
            sum,
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
        arr[i] = rand() % range - range / 2;
    }
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


int max_subsequence_sum(int* arr, int len)
{
    int i;
    int maxSum = 0;
    int thisMaxSum = 0;
    for(i = 0; i < len; i++)
    {
        thisMaxSum += arr[i];
        if (thisMaxSum > maxSum)
            maxSum =  thisMaxSum;
        if (thisMaxSum < 0)
            thisMaxSum = 0;
    }
    return maxSum;
}
