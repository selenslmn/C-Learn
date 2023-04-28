// The fputc function is used to write a byte to the pointer of the file.

// The first parameter of the function specifies the byte to be written. 
// Although this parameter is of int type, the least significant byte value of the number here is written to the file. 
// The second parameter of the function specifies the file information pointer for the file to be written.

// The function returns the written byte value on success and the EOF value on failure. The reason for the failure may be the IO error.

// The ferrror flag is set when the function fails. Therefore, the ferror function also returns a non-zero value.

/* 

  Here are some of the possible causes of IO error while writing:

  - The disk is corrupt
  - Instant removal of a removable disk (e.g. flash drives)
  - The disk is completely full
  - In operating systems, the maximum number of bytes that can be written to the file may be limited. This limit may have been exceeded.

*/

// In the example below, all bytes in a char type directory are written to the file until a null character is seen.

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *f;
    char s[] = "ankara";

    if ((f = fopen("test.txt", "w")) == NULL) {
        fprintf(stderr, "cannot open file!..\n");
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; s[i] != '\0'; ++i)
        if (fputc(s[i], f) == EOF) {
            fprintf(stderr, "Unexpected IO error!..\n");
            exit(EXIT_FAILURE);
        }

    fclose(f);

    return 0;
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/
