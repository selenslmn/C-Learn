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
