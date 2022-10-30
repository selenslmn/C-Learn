// swapping two int values

#include <stdio.h>

void reverse(int *pi, size_t size);

int main(void)
{
    int a[10] = {2, 56, 11, 1, 58, 23, 32, 43, 67, 15};

    for (size_t i = 0; i < 10; ++i)
        printf("%d ", a[i]);
    printf("\n");

    reverse(a, 10);

    for (size_t i = 0; i < 10; ++i)
        printf("%d ", a[i]);
    printf("\n");

    return 0;
}

void swap(int *pi1, int *pi2)
{
    int temp = *pi1;
    *pi1 = *pi2;
    *pi2 = temp;
}

void reverse(int *pi, size_t size)
{
    for (size_t i = 0; i < size / 2; ++i)
        swap(&pi[i], &pi[size - 1 - i]);
}
