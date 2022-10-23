#include <stdio.h>

int main(void)
{  
    int a[10];

    for (int i = 0; i < 10; ++i)
        a[i] = i * i;

    for (int i = 0; i < 10; ++i)
        printf("%d\n", a[i]);

    return 0;
}

------------------------------------------------------------------
  
#include <stdio.h>

int main(void)
{  
    int a[5] = {10, 20, 30, 40, 50};

    for (int i = 0; i < 5; ++i)
        printf("%d ", a[i]);
    printf("\n");

    return 0;
}

------------------------------------------------------------------
  
#include <stdio.h>

int main(void)
{  
    int a[5] = {10, 20};

    for (int i = 0; i < 5; ++i)
        printf("%d ", a[i]);    /* 10 20 0 0 0 */
    printf("\n");

    return 0;
}
