// The fprintf function is the file format of the printf function. 
// So the printf function is actually the form of the fprintf function that writes to the stdout file (screen).

// If we are going to print something to the file with the fprintf function, it is appropriate to open the file in text mode.

// Note that the things printed to the file with the fprintf function are printed as text.

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *f;

    if ((f = fopen("test.txt", "w")) == NULL) {
        fprintf(stderr, "cannot open file!..\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < 100; ++i)
        fprintf(f, "Number: %d\n", i);

    fclose(f);

    return 0;
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/

// The screen behaves like a file. So actually printf is a hidden file function. The general version of the printf function is the fprintf function.

#include <stdio.h>

int main(void)
{
    printf("this is a test\n");
    fprintf(stdout, "this is a test\n");

    return 0;
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/
