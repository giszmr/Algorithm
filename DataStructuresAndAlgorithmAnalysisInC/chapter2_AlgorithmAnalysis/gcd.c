#include <stdio.h>
#include <sys/time.h>

//计算两个整数的最大公约数

#define M  15
#define N  50


unsigned gcd(unsigned m, unsigned n);

int main(int argc, char* argv[])
{
    unsigned result = 0;
    struct timeval  tv_begin = {0};
    struct timeval  tv_end   = {0};

    //begin time stamp
    gettimeofday(&tv_begin, NULL);

    result = gcd(M, N);

    //end time stamp
    gettimeofday(&tv_end, NULL);

    printf("result=%ld, begin[%ld] end[%ld]  time: %ld\n",
            result,
            (tv_begin.tv_sec * 1000 * 1000 + tv_begin.tv_usec),
            (tv_end.tv_sec * 1000 * 1000 + tv_end.tv_usec),
            (tv_end.tv_sec * 1000 * 1000 + tv_end.tv_usec) - (tv_begin.tv_sec * 1000 * 1000 + tv_begin.tv_usec));

    return 0;
}

unsigned gcd(unsigned m, unsigned n)
{
    unsigned rem;
    
    while(n > 0)
    {
        rem = m % n;
        m = n;
        n = rem;
    }
    return m;
}

