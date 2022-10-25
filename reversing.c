// Reversing the elements of an array

#include <stdio.h>

#define SIZE        10

int main(void)
{  
    int a[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int temp;
   
    for (int i = 0; i < SIZE / 2; ++i) {
        temp = a[i];
        a[i] = a[SIZE - 1 - i];
        a[SIZE - 1 - i] = temp;
    }

    for (int i = 0; i < SIZE; ++i)
        printf("%d ", a[i]);
    printf("\n");

    return 0;
}

---------------------------------------------------------------------------------------
    
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

void reverse(int *pi, size_t size)
{
    for (size_t i = 0; i < size / 2; ++i) {
        int temp = pi[i];
        pi[i] = pi[size - 1 - i];
        pi[size - 1 - i] = temp;
    }
}
