#include <stdio.h>

#define SIZE        10

int main(void)
{
    int a[SIZE] = {1, 3, 5, 5, 24, 63, 2, 17, 4, 89};
    int val;
    int i;

    printf("Enter a value: ");
    scanf("%d", &val);

    for (i = 0; i < SIZE; ++i)
        if (a[i] == val)
            break;

    if (i == SIZE)
        printf("\nnot found!\n");
    else
        printf("\nfound in index %d\n", i);

    return 0;
}
