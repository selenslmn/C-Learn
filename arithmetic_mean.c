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
