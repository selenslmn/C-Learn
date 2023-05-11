// When a file is opened, the file pointer is at the 0th offset. Then, the file pointer is automatically advanced as reading and writing are done.
// However, we may want to read something from a certain part of the file or we may want to write something to a certain part of the file. 
// For this we need to position the file pointer. This is done with a function called fseek.
	
// The prototype of the fseek function is:

	int fseek(FILE *f, long int offset, int whence);

// The 1st parameter of the function file pointer takes the information pointer of the file to be located. 
// The 2nd parameter specifies the positioning offset. 
// The 3rd parameter specifies where the positioning will be made, in other words, the positioning origin. 
// This third parameter can only take the value 0, 1 or 2.
// A value of 0 means that the positioning will be done from the beginning of the file. In this case, the second parameter must be >= 0.
// A value of 1 means that the positioning will be done from where the file pointer is currently pointing. 
// The 2nd parameter can be +, - or 0. Positive value means positioning "n forward from home", negative value means positioning "n back from home".	
 
// Here the file pointer is positioned one back: 	  fseek(f, -1, 1);

// Here the file pointer is positioned at the 10th offset:	  fseek(f, 10, 0);

// The 3rd parameter being 2 means that the positioning will be done from the EOF position. In this case, the 2nd parameter should be <= 0:
    fseek(f, 0, 2);

// Here the positioning is done to the last byte of the file:    fseek(f, -1, 2);

// Third parameter to improve readability:

	#define SEEK_SET		0
	#define SEEK_CUR		1
	#define SEEK_END		2

	fseek(f, 10, SEEK_SET);
	fseek(f, 0, SEEK_END);

// If we pass a non-existent offset as a parameter to the fseek function, or enter the third parameter improperly, fseek may fail.
// fseek returns 0 on success, and any non-zero value on failure.

/*--------------------------------------------------------------------------------------------------------------------------------------------*/

// The file pointer is pulled to the EOF state and something is written to the end of the file with the fprintf function:

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *f;

    if ((f = fopen("test.txt", "r+")) == NULL) {
        fprintf(stderr, "cannot open file!..\n");
        exit(EXIT_FAILURE);
    }

    fseek(f, 0, SEEK_END);

    fprintf(f, "this is a test...\n");


    fclose(f);

    return 0;
}

/*--------------------------------------------------------------------------------------------------------------------------------------------*/

/* According to C standards, if the file is opened in read and write mode, 
the file pointer must be positioned with the fseek function when going from reading to writing and from writing to reading. 
Otherwise it will lead to undefined behavior: */

ch = fegtc(f);
fseek(f, 0, 1);
fputc('x', f);

/*--------------------------------------------------------------------------------------------------------------------------------------------*/

// There is also a function called rewind to position the file pointer.
// This function always moves the file pointer to the beginning of the file (ie to the 0th offset).

// rewind(f) and fseek(f, 0, 0) are completely equivalent.

/*--------------------------------------------------------------------------------------------------------------------------------------------*/

// Sometimes we may want to get the current location of the file pointer. 
// Then we can position that offset with fseek and read something from there or write something there. 
// The ftell function is used for this.

// Note that the return value of the function that specifies the offset is long. 
// This long value always specifies a value from the beginning of the file.

/*--------------------------------------------------------------------------------------------------------------------------------------------*/

// In the example below, the file pointer is first pulled to the EOF position, and then the value of the file pointer is obtained.
// Therefore, the byte length of the file is obtained. 

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *f;
    long size;
    
    if ((f = fopen("test.txt", "r")) == NULL) {
        fprintf(stderr, "cannot open file!..\n");
        exit(EXIT_FAILURE);
    }

    fseek(f, 0, SEEK_END);
    size = ftell(f);
    printf("%ld\n", size);

    fclose(f);

    return 0;
}

/*--------------------------------------------------------------------------------------------------------------------------------------------*/
