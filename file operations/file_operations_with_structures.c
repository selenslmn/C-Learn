/* Since the elements of the structures are sequentially in memory, a structure object can be written to the file with the fwrite function and 
read from the file with the fread function in one go. */

// In the example below, the information of the people is taken in a loop and written to the file with the fwrite function:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct PERSON {
    char name[64];
    int no;
};

int main(void)
{
    FILE *f;
    struct PERSON per;
    char *str;
    
    if ((f = fopen("test.dat", "wb")) == NULL) {
        fprintf(stderr, "cannot open file!..\n");
        exit(EXIT_FAILURE);
    }

    for (;;) {
        printf("Name Surname:");
        fgets(per.name, 64, stdin);
        if ((str = strchr(per.name, '\n')) != NULL)
            *str = '\0';
        if (!strcmp(per.name, "quit"))
            break;
        printf("No:");
        scanf("%d", &per.no);
        while (getchar() != '\n')
            ;
        if (fwrite(&per, sizeof(struct PERSON), 1, f) != 1) {
            fprintf(stderr, "cannot write file!..\n");
            exit(EXIT_FAILURE);
        }
    }

    fclose(f);

    return 0;
}

/*--------------------------------------------------------------------------------------------------------------------------------------------*/

// In the example above, we read the information we wrote to the file with the fread function in the loop:

#include <stdio.h>
#include <stdlib.h>

struct PERSON {
    char name[64];
    int no;
};

int main(void)
{
    FILE *f;
    struct PERSON per;
 
    if ((f = fopen("test.dat", "rb")) == NULL) {
        fprintf(stderr, "cannot open file!..\n");
        exit(EXIT_FAILURE);
    }

    while (fread(&per, sizeof(struct PERSON), 1, f) == 1) 
        printf("%s, %d\n", per.name, per.no);
  
    if (ferror(f)) {
        fprintf(stderr, "cannot read file!..\n");
        exit(EXIT_FAILURE);
    }

    fclose(f);

    return 0;
}

/*---------------------------------------------------------------------------------------------------------------------------------------------*/

// In the example below, a certain record is searched in the file by name in a "sequential" format.
// Sorting search isn't a good method if the number of records is too large. For this, special algorithmic search methods are used.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct PERSON {
    char name[64];
    int no;
};

int main(void)
{
    FILE *f;
    struct PERSON per;
    char *str;
    char name[64];

    printf("Enter the name and surname of the person to be called:");
    fgets(name, 64, stdin);
    if ((str = strchr(name, '\n')) != NULL)
        *str = '\0';

    if ((f = fopen("test.dat", "rb")) == NULL) {
        fprintf(stderr, "cannot open file!..\n");
        exit(EXIT_FAILURE);
    }

    while (fread(&per, sizeof(struct PERSON), 1, f) == 1) 
        if (!strcmp(per.name, name)) {
            printf("record found : %s, %d\n", per.name, per.no);
            break;
        }
       
    if (feof(f))
        printf("record not found!..\n");

    if (ferror(f)) {
        fprintf(stderr, "cannot read file!..\n");
        exit(EXIT_FAILURE);
    }

    fclose(f);

    return 0;
}

/*-----------------------------------------------------------------------------------------------------------------------------------------------*/
