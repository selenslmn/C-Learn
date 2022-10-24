#include <stdio.h>

#define SIZE        10

int main(void)
{  
    int a[SIZE] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int min, min_index;
    
    for (int i = 0; i < SIZE - 1; ++i) {
        min = a[i];
        min_index = i;
        for (int k = i + 1; k < SIZE; ++k) 
            if (a[k] < min) {
                min = a[k];
                min_index = k;
            }
        a[min_index] = a[i];
        a[i] = min;
    }

    for (int i = 0; i < SIZE; ++i)
        printf("%d ", a[i]);
    printf("\n");

    return 0;
}
