#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *pi;
    int size;

    printf("Array length:");
    scanf("%d", &size);

    pi = (int *)malloc(size * sizeof(int));
    if (pi == NULL) {
        fprintf(stderr, "cannot allocate memory!..\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < size; ++i) {
        printf("Enter the %d. element:", i + 1);
        scanf("%d", &pi[i]);
    }

    for (int i = 0; i < size; ++i)
        printf("%d ", pi[i]);
    printf("\n");

    return 0;
}

----------------------------------------------------------------------------------------------------------
  
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *str;

    if ((str = (char *)malloc(100)) == NULL) {
        fprintf(stderr, "cannot allocate memory!..\n");
        exit(EXIT_FAILURE);
    }
    printf("Enter a text:");
    gets(str);

    puts(str);

    return 0;
}

-----------------------------------------------------------------------------------------------------------------
  

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *names[5];

    for (int i = 0; i < 5; ++i) {
        if ((names[i] = (char *)malloc(64)) == NULL) {
            fprintf(stderr, "cannot allocate memory!..\n");
            exit(EXIT_FAILURE);
        }
        printf("Enter a name:");
        gets(names[i]);
    }

    for (int i = 0; i < 5; ++i)
        puts(names[i]);

    return 0;
}
