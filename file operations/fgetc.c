// The fgetc() function reads 1 byte from the pointer of the file pointer and gives us the byte it read.

/* 

fgetc can fail for basically two reasons:

1) The file pointer is in the EOF state and therefore could not be read.
2) A serious problem has occurred with the disc. Such serious errors are called "IO errors".

IO errors are very rare. It is a normal failure condition if the read operation fails due to the EOF condition.

*/

// Here's a program that reads a file byte by byte and prints it out:

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *f;
    int ch;

    if ((f = fopen("test.txt", "r")) == NULL) {
        fprintf(stderr, "cannot open file!..\n");
        exit(EXIT_FAILURE);
    }

    while ((ch = fgetc(f)) != EOF)
        putchar(ch);

    fclose(f);

    return 0;
}

// Finally, the file pointer will become EOF. This will exit the loop. Even if an IO error occurs, fgetc returns with the EOF value. This is the end of the loop. 

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/
