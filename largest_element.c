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
