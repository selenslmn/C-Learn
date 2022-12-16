// The first parameter specifies the number of elements of the array to be allocated, the second parameter specifies the byte length of an element of the array.

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *pi;

    if ((pi = (int *)calloc(10, sizeof(int))) == NULL) {        /* Dynamically allocating an int array with 10 elements */
        fprintf(stderr, "cannot allocate memory!..\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < 10; ++i)
        printf("%d ", pi[i]);
    printf("\n");

    free(pi);

    return 0;
}

// The main difference of the calloc function from the malloc function is that the calloc function resets the space allocated. 
// However, there are garbage values in the space allocated with the malloc function.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *mycalloc(size_t nelems, size_t size)          /* Without calloc() */
{
    void *ptr;

    if ((ptr = malloc(nelems * size)) == NULL)
        return NULL;

    return memset(ptr, 0, nelems * size);
}

int main(void)
{
    int *pi;

    if ((pi = (int *)mycalloc(10, sizeof(int))) == NULL) {
        fprintf(stderr, "cannot allocate memory!..\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < 10; ++i)
        printf("%d ", pi[i]);
    printf("\n");

    free(pi);

    return 0;
}
