#include <stdio.h>
#include <sys/time.h>

//¼ÆËãxµÄn´ÎÃÝ

#define X 3
#define N 1000
long power(long x, unsigned n);
/******************************************************************************
** Linux FNSHC165 3.10.0-327.el7.x86_64 #1 SMP Thu Nov 19 22:10:57 UTC 2015 x86_64 x86_64 x86_64 GNU/Linux
** N          = 10,  100,  1,000,   10,000     100,000       1,000,000        10,000,000
** power        0    1     1        1
** power_loop = 0    1     8        77
*******************************************************************************/

long power_loop(long x, unsigned n);

int main(int argc, char* argv[])
{
    long result = 0;
    struct timeval  tv_begin = {0};
    struct timeval  tv_end   = {0};

    //begin time stamp
    gettimeofday(&tv_begin, NULL);

    result = power(X, N);

    //end time stamp
    gettimeofday(&tv_end, NULL);

    printf("result=%ld, begin[%ld] end[%ld]  time: %ld\n",
            result,
            (tv_begin.tv_sec * 1000 * 1000 + tv_begin.tv_usec),
            (tv_end.tv_sec * 1000 * 1000 + tv_end.tv_usec),
            (tv_end.tv_sec * 1000 * 1000 + tv_end.tv_usec) - (tv_begin.tv_sec * 1000 * 1000 + tv_begin.tv_usec));
    /////////////////////////////////////////////////////////
    //begin time stamp
    gettimeofday(&tv_begin, NULL);

    result = power_loop(X, N);

    //end time stamp
    gettimeofday(&tv_end, NULL);

    printf("result=%ld, begin[%ld] end[%ld]  time: %ld\n",
            result,
            (tv_begin.tv_sec * 1000 * 1000 + tv_begin.tv_usec),
            (tv_end.tv_sec * 1000 * 1000 + tv_end.tv_usec),
            (tv_end.tv_sec * 1000 * 1000 + tv_end.tv_usec) - (tv_begin.tv_sec * 1000 * 1000 + tv_begin.tv_usec));

    return 0;
}

/**************************************************************
** if n is even, x ^ n = x ^ (n/2) * x ^ (n/2) 
** if n is odd,  x ^ n = x ^ ((n - 1)/2) * x ^ ((n - 1)/2) * x
***************************************************************/
long power(long x, unsigned n)
{
    if (n == 0)
        return 1;
    
    if(n % 2 == 0)
        return power(x * x, n / 2);   
    else
        return power(x * x, n / 2) * x;  //or pow(x, n - 1);
}

long power_loop(long x, unsigned n)
{
    long result = 1;
    while(n > 0)
    {
        result *= x;
        n--; 
    }
}
