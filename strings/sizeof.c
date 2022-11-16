#include <stdio.h>

int main(void)
{
    int a[10];
    int *pi;
    char *pc;
    size_t result;

    result = sizeof 100 + 2;
    printf("%zd\n", result);        /* 6 */

    result = sizeof (100 + 2);       
    printf("%zd\n", result);        /* 4 */

    result = sizeof(pi);            
    printf("%zd\n", result);        /* 8 */

    result = sizeof(pc);
    printf("%zd\n", result);        /* 8 */

    result = sizeof(a);
    printf("%zd\n", result);        /* 40 */

    return 0;
}

------------------------------------------------------
  
#include <stdio.h>
#include <string.h>

int main(void)
{
    int a[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int b[10];

    memcpy(b, a, sizeof(int) * 10);

    for (int i = 0; i < 10; ++i)
        printf("%d ", b[i]);
    printf("\n");

    return 0;
}

-------------------------------------------------------------------------------------------
 
// sizeof(a) / sizeof(*a) returns the element length of the array, with the array name a.
  
#include <stdio.h>
#include <string.h>

int main(void)
{
    int a[] = {10, 20, 30, 40, 50, 60, 70};
    
    for (int i = 0; i < sizeof(a) / sizeof(*a); ++i)
        printf("%d ", a[i]);
    printf("\n");

    return 0;
}

