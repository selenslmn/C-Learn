#include <stdio.h>

#define SIZE        10

int main(void)
{
    int a[SIZE] = {23, 12, 76, 45, 23, 65, 11, 98, 42, 81};
    int temp;

    for (int i = 0; i < SIZE - 1; ++i)
        for (int k = 0; k < SIZE - 1 - i; ++k)
            if (a[k + 1] < a[k]) {
                temp = a[k];
                a[k] = a[k + 1];
                a[k + 1] = temp;
            }

    for (int i = 0; i < SIZE; ++i)
        printf("%d ", a[i]);
    printf("\n");

    return 0;
}

------------------------------------------------------------------------------------------------
  
#include <stdio.h>

#define SIZE        10

#define TRUE        1
#define FALSE       0

int main(void)
{  
    int a[SIZE] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int temp;
    int replace_flag;
  
    for (int i = 0; i < SIZE - 1; ++i) {
        replace_flag = FALSE;
        for (int k = 0; k < SIZE - 1 - i; ++k)
            if (a[k + 1] < a[k]) {
                temp = a[k];
                a[k] = a[k + 1];
                a[k + 1] = temp;
                replace_flag = TRUE;
            }
        if (!replace_flag)
            break;
    }

    for (int i = 0; i < SIZE; ++i)
        printf("%d ", a[i]);
    printf("\n");

    return 0;
}

------------------------------------------------------------------------------------------------------
  
#include <stdio.h>

#define SIZE        10

#define TRUE        1
#define FALSE       0

int main(void)
{
    int a[SIZE] = {10, 9, 8, 3, 6, 5, 4, 11, 2, 1};
    int temp;
    int replace_flag;

    for (int i = 0; i < SIZE - 1; ++i) {
        replace_flag = FALSE;
        for (int k = 0; k < SIZE - 1 - i; ++k)
            if (a[k + 1] < a[k]) {
                temp = a[k];
                a[k] = a[k + 1];
                a[k + 1] = temp;
                replace_flag = TRUE;
            }
        if (!replace_flag)
            break;
    }

    for (int i = 0; i < SIZE; ++i)
        printf("%d ", a[i]);
    printf("\n");

    return 0;
}

-----------------------------------------------------------------------------------------
  
#include <stdio.h>

#define SIZE        10

#define TRUE        1
#define FALSE       0

int main(void)
{  
    int a[SIZE] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int temp;
    int replace_flag;
    int n = SIZE - 1;
  
    do {
        replace_flag = FALSE;
        for (int k = 0; k < n; ++k)
            if (a[k + 1] < a[k]) {
                temp = a[k];
                a[k] = a[k + 1];
                a[k + 1] = temp;
                replace_flag = TRUE;
            }
        --n;
    } while (replace_flag);

    for (int i = 0; i < SIZE; ++i)
        printf("%d ", a[i]);
    printf("\n");

    return 0;
}

----------------------------------------------------------------------------------------------------------
    
#include <stdio.h>

void bsort(int *pi, size_t size);

int main(void)
{
    int a[10] = {2, 56, 11, 1, 58, 23, 32, 43, 67, 15};

    bsort(a, 10);

    for (size_t i = 0; i < 10; ++i)
        printf("%d ", a[i]);
    printf("\n");

    return 0;
}

void bsort(int *pi, size_t size)
{
    int temp;
    int flag;
    size_t i;
 
    i = 0;
    do {
        flag = 0;
        for (size_t k = 0; k < size - 1 - i; ++k) {
            if (pi[k] > pi[k + 1]) {
                flag = 1;
                temp = pi[k];
                pi[k] = pi[k + 1];
                pi[k + 1] = temp;
            }
        }
        ++i;
    }  while (flag == 1);
}
