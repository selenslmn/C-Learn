// The fgets function is used to read a line from a text file.

    char *fgets(char *s, int n, FILE *f);

// The first parameter of the function specifies the address of the directory where the information in the row will be placed.
// The second parameter specifies the length of the array specified in the first parameter.
// The function never tries to insert more than the specified number of bytes into the array.
// The last parameter specifies the file information pointer for the file to be processed.

/*-------------------------------------------------------------------------------------------------------------------------------------------*/

// The fgets function works like this:

      ankara\n

      char buf[100];
      fgets(buf, 100, f);         /* ankara\n\0.... */

// gets function would put this in the array: ankara\0
// To use the fgets function like gets, it is necessary to find the '\n' character at the end of the text and replace it with a null character.
// If there are too many characters in the line, then fgets will not insert the '\n' character.

/*-------------------------------------------------------------------------------------------------------------------------------------------*/

// The stdin file may be redirected to another file, and this file may not always have the '\n' character at the end.
// Therefore, the fgets function also needs to check whether the return value is a NULL address.

#include <stdio.h>
#include <string.h>

int main(void)
{
    char buf[10];
    char *str;

    if (fgets(buf, 10, stdin) != NULL) {
        if ((str = strchr(buf, '\n')) != NULL)
            *str = '\0';
        puts(buf);
    }
    
    return 0;
}

/*----------------------------------------------------------------------------------------------------------------------------------------*/

char buf[5];
fgets(buf, 5, f);                /*   anka\0 */

/* If EOF is encountered before the '\n' character is seen when fgets is called, then fgets reads as many characters as it can, 
again inserts a null character at the end of the array and terminates the process. */

ankaraEOF

char buf[100];
fgets(buf, 100, f);               ankara\0

/*------------------------------------------------------------------------------------------------------------------------------------------*/

// To print a file line by line to the screen (stdout file): 

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *f;
    char buf[4096];   /* If we keep the array length small, we cannot read the file line by line, 
                                but we can read and print everything until the end of the file. */
    
    if ((f = fopen("test.txt", "r")) == NULL) {
        fprintf(stderr, "cannot open file!..\n");
        exit(EXIT_FAILURE);
    }

    while (fgets(buf, 4096, f) != NULL)
        printf("%s", buf);

    fclose(f);

    return 0;
}

/*----------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <string.h>

int main(void)
{
    char buf[10];
    char *str;

    if (fgets(buf, 10, stdin) != NULL) {
        if ((str = strchr(buf, '\n')) != NULL)
            *str = '\0';
        puts(buf);
    }
    
    return 0;
}

/*-------------------------------------------------------------------------------------------------------------------------------------------*/
