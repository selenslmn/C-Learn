// Finding the arithmetic mean of an array

#include <stdio.h>

#define SIZE        10

int main(void)
{
    int a[SIZE] = {1, 3, 5, 5, 24, 63, 2, 17, 4, 89};
    int total;
    double avg;

    total = 0;
    for (int i = 0; i < SIZE; ++i)
        total += a[i];

    avg = (double)total / SIZE;

    printf("%f\n", avg);

    return 0;
}

-------------------------------------------------------------------------------
    
#include <stdio.h>

double mean(double *pd, size_t size)
{
    double total;

    total = 0;
    for (size_t i = 0; i < size; ++i)
        total += pd[i];

    return total / size;
}

int main(void)
{
    double a[5] = {1, 2, 3, 4, 5};
    double result;

    result = mean(a, 5);
    printf("%f\n", result);

    return 0;
}
