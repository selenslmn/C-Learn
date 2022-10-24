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
