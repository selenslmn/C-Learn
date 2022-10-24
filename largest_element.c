// Finding the largest element of an array

#include <stdio.h>

#define SIZE        10

int main(void)
{  
    int a[SIZE] = {1, 3, 5, 5, 24, 63, 2, 17, 4, 89};
    int max;

    max = a[0];

    for (int i = 1; i < SIZE; ++i)
        if (a[i] > max)
            max = a[i];

    printf("%d\n", max);

    return 0;
}

-----------------------------------------------------------------------
    
#include <stdio.h>

int getmax(int *pi, size_t size)
{
    int max = pi[0];

    for (size_t i = 1; i < size; ++i)
        if (pi[i] > max)
            max = pi[i];

    return max;
}

int main(void)
{
    int a[10] = {45, 23, 11, 67, 21, 7, 32, 76, 22, 47};
    int max;

    max = getmax(a, 10);
    printf("%d\n", max);

    return 0;
}
