#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *str;

    if ((str = (char *)malloc(100)) == NULL) {
        fprintf(stderr, "cannot allocate memory!..\n");
        exit(EXIT_FAILURE);
    }
    printf("Bir yazi giriniz:");
    gets(str);

    puts(str);

    free(str);

    return 0;
}

--------------------------------------------------------------------
  
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
        printf("Bir isim giriniz:");
        gets(names[i]);
    }

    for (int i = 0; i < 5; ++i)
        puts(names[i]);

    for (int i = 0; i < 5; ++i)
        free(names[i]);

    return 0;
}
