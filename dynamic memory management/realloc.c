// The first parameter of the function specifies the starting address of the previously allocated dynamic area. 
// The second parameter is the wanted total new length of the block.
// malloc(n) = realloc(NULL, n)

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int val;
    int *pi, *pnew;
    int n;

    pi = NULL;
    for (n = 0;; ++n) {
        printf("Bir deger giriniz:");
        scanf("%d", &val);
        if (val == 0)
            break;
        if ((pnew = (int *)realloc(pi, (n + 1) * sizeof(int))) == NULL) {
            fprintf(stderr, "cannot realloc memory!..\n");
            break;
        }
        pi = pnew;
        pi[n] = val;
    }

    for (int i = 0; i < n; ++i)
        printf("%d ", pi[i]);
    printf("\n");

    free(pi);

    return 0;
}

-------------------------------------------------------------------------------------------------------
  
#include <stdio.h>
#include <stdlib.h>

#define CHUNK_SIZE      10

int main(void)
{
    int val;
    int *pi, *pnew;
    int n;

    pi = NULL;
    for (n = 0;; ++n) {
        printf("Bir deger giriniz:");
        scanf("%d", &val);
        if (val == 0)
            break;
        if (n % CHUNK_SIZE == 0) {
            if ((pnew = (int *)realloc(pi, (n + CHUNK_SIZE) * sizeof(int))) == NULL) {
                fprintf(stderr, "cannot realloc memory!..\n");
                break;
            }
            pi = pnew;
        }
        pi[n] = val;
    }

    for (int i = 0; i < n; ++i)
        printf("%d ", pi[i]);
    printf("\n");

    free(pi);

    return 0;
}

------------------------------------------------------------------------------------------------------
  
#include <stdio.h>
#include <stdlib.h>

#define DEF_CAPACITY        4

int main(void)
{
    int val;
    int *pi, *pnew;
    size_t size, capacity;

    size = 0;
    capacity = DEF_CAPACITY;

    if ((pi = (int *)malloc(DEF_CAPACITY * sizeof(int))) == NULL) {
        fprintf(stderr, "cannot allocate memory!..\n");
        exit(EXIT_FAILURE);
    }
    
    for (;;) {
        printf("Bir deger giriniz:");
        scanf("%d", &val);
        if (val == 0)
            break;
        if (size == capacity) {
            if ((pnew = (int *)realloc(pi, (capacity * 2) * sizeof(int))) == NULL) {
                fprintf(stderr, "cannot reallocate memory!..\n");
                break;
            }
            pi = pnew;
            capacity *= 2;
        }
        pi[size] = val;
        ++size;  
    }

    for (int i = 0; i < size; ++i)
        printf("%d ", pi[i]);
    printf("\n");

    free(pi);

    return 0;
}
