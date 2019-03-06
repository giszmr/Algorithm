#include <stdio.h>
#include <sys/time.h>

#define N 1000

void sum1();
void sum2();
void sum3();
void sum4();
void sum5();
void sum6();

int main(int argc, char* argv[])
{
    /******************************************************/
    /*   N =   10    100          1000 */
    sum1(); // 1     1            6
    sum2(); // 1     66           6,500
    sum3(); // 7     6,500        3,500,00
    sum4(); // 1     30           1,218
    sum5(); // 45    2,500,000    
    sum6(); // 10    310,000      

    return 0;
}


void sum1()
{
    struct timeval  tv_begin = {0};
    struct timeval  tv_end   = {0};
    int i, sum = 0;

    //begin time stamp
    gettimeofday(&tv_begin, NULL);

    for(i = 0; i < N; i++)
        sum++;

    //end time stamp
    gettimeofday(&tv_end, NULL);

    printf("begin[%ld] end[%ld]  time: %ld\n",
            (tv_begin.tv_sec * 1000 * 1000 + tv_begin.tv_usec),
            (tv_end.tv_sec * 1000 * 1000 + tv_end.tv_usec),
            (tv_end.tv_sec * 1000 * 1000 + tv_end.tv_usec) - (tv_begin.tv_sec * 1000 * 1000 + tv_begin.tv_usec));
}


void sum2()
{
    struct timeval  tv_begin = {0};
    struct timeval  tv_end   = {0};
    int i,j, sum = 0;

    //begin time stamp
    gettimeofday(&tv_begin, NULL);

    for(i = 0; i < N; i++)
        for(j = 0; j < N; j++)
            sum++;

    //end time stamp
    gettimeofday(&tv_end, NULL);

    printf("begin[%ld] end[%ld]  time: %ld\n",
            (tv_begin.tv_sec * 1000 * 1000 + tv_begin.tv_usec),
            (tv_end.tv_sec * 1000 * 1000 + tv_end.tv_usec),
            (tv_end.tv_sec * 1000 * 1000 + tv_end.tv_usec) - (tv_begin.tv_sec * 1000 * 1000 + tv_begin.tv_usec));
}

void sum3()
{
    struct timeval  tv_begin = {0};
    struct timeval  tv_end   = {0};
    int i,j, sum = 0;

    //begin time stamp
    gettimeofday(&tv_begin, NULL);

    for(i = 0; i < N; i++)
        for(j = 0; j < N*N; j++)
            sum++;

    //end time stamp
    gettimeofday(&tv_end, NULL);

    printf("begin[%ld] end[%ld]  time: %ld\n",
            (tv_begin.tv_sec * 1000 * 1000 + tv_begin.tv_usec),
            (tv_end.tv_sec * 1000 * 1000 + tv_end.tv_usec),
            (tv_end.tv_sec * 1000 * 1000 + tv_end.tv_usec) - (tv_begin.tv_sec * 1000 * 1000 + tv_begin.tv_usec));
}

void sum4()
{
    struct timeval  tv_begin = {0};
    struct timeval  tv_end   = {0};
    int i,j, sum = 0;

    //begin time stamp
    gettimeofday(&tv_begin, NULL);

    for(i = 0; i < N; i++)
        for(j = 0; j < i; j++)
                sum++;

    //end time stamp
    gettimeofday(&tv_end, NULL);

    printf("begin[%ld] end[%ld]  time: %ld\n",
            (tv_begin.tv_sec * 1000 * 1000 + tv_begin.tv_usec),
            (tv_end.tv_sec * 1000 * 1000 + tv_end.tv_usec),
            (tv_end.tv_sec * 1000 * 1000 + tv_end.tv_usec) - (tv_begin.tv_sec * 1000 * 1000 + tv_begin.tv_usec));
}

void sum5()
{
    struct timeval  tv_begin = {0};
    struct timeval  tv_end   = {0};
    int i,j,k, sum = 0;

    //begin time stamp
    gettimeofday(&tv_begin, NULL);

    for(i = 0; i < N; i++)
        for(j = 0; j < i*i; j++)
            for(k = 0; k < j; k++)
                sum++;

    //end time stamp
    gettimeofday(&tv_end, NULL);

    printf("begin[%ld] end[%ld]  time: %ld\n",
            (tv_begin.tv_sec * 1000 * 1000 + tv_begin.tv_usec),
            (tv_end.tv_sec * 1000 * 1000 + tv_end.tv_usec),
            (tv_end.tv_sec * 1000 * 1000 + tv_end.tv_usec) - (tv_begin.tv_sec * 1000 * 1000 + tv_begin.tv_usec));
}

void sum6()
{
    struct timeval  tv_begin = {0};
    struct timeval  tv_end   = {0};
    int i,j,k, sum = 0;

    //begin time stamp
    gettimeofday(&tv_begin, NULL);

    for(i = 0; i < N; i++)
        for(j = 0; j < i*i; j++)
            if(j % i == 0)
                for(k = 0; k < j; k++)
                    sum++;

    //end time stamp
    gettimeofday(&tv_end, NULL);

    printf("begin[%ld] end[%ld]  time: %ld\n",
            (tv_begin.tv_sec * 1000 * 1000 + tv_begin.tv_usec),
            (tv_end.tv_sec * 1000 * 1000 + tv_end.tv_usec),
            (tv_end.tv_sec * 1000 * 1000 + tv_end.tv_usec) - (tv_begin.tv_sec * 1000 * 1000 + tv_begin.tv_usec));
}

