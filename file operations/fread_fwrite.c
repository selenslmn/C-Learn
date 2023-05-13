// These functions are generally used to transfer between memory and file in "binary" files.

/* The 1st parameters of these functions specify the memory transfer address. 
The 2nd parameter is the byte length of an element of the array, and the 3rd parameter is the length of the array. 
When the two values are multiplied, the total number of bytes of the array is obtained and the functions transfer that many bytes. 
The last parameter of the function specifies the file information pointer for the file.
The functions return with the number of read or write parts specified in the 3rd parameter. 
In case of EOF, fread function returns 0 because it cannot read. It also returns 0 when functions fail. 
In this case, if the fread function returns 0, the ferror or feof functions must be used to determine whether the failure is due to EOF. */

/*------------------------------------------------------------------------------------------------------------------------------------------ */

/* A 10-element int array is written to a binary file in one go with the fwrite function, 
and then again read with the fread function in one stroke: */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *f;
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int b[10];

    if ((f = fopen("test.dat", "w+b")) == NULL) {
        fprintf(stderr, "cannot open file!..\n");
        exit(EXIT_FAILURE);
    }

    if (fwrite(a, sizeof(int), 10, f) != 10) {
        fprintf(stderr, "cannot write file!..\n");
        exit(EXIT_FAILURE);
    }

    rewind(f);

    if (fread(b, sizeof(int), 10, f) != 10) {
        fprintf(stderr, "cannot read file!..\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < 10; ++i)
        printf("%d ", b[i]);
    printf("\n");

    fclose(f);

    return 0;
}

/*---------------------------------------------------------------------------------------------------------------------------------------------*/

// The fread function reads as many bytes as it can from the point the file pointer points to and returns the number of parts it can read. 
// So we can read fewer bytes than we requested with fread. This is not considered an error.

// If the fread function encounters EOF without doing any reading or an IO error occurs, it returns 0. This may need to be checked.

	result = fread(a, 1, sizeof(int) * 10, f);
	if (result == 0) {
		if (ferror(f)) {
			fprintf(stderr, "IO error!..\n);
			exit(EXIT_FAILURE);
		}
		/* end of file encountered */
	}

/*----------------------------------------------------------------------------------------------------------------------------------------------*/

// We can copy files using fread and fwrite functions. Classic file copy algorithm:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATH        1024
#define BUFFER_SIZE     1024      /* Here BUFFER_SIZE specifies the dish size to be used during copying. */

int main(void)
{
    FILE *fs, *fd;
    char spath[1024], dpath[1024], *str;
    size_t result;
    char buf[BUFFER_SIZE];

    /* Read and open part */

    printf("Source file path: ");
    fgets(spath, 1024, stdin);
    if ((str = strchr(spath, '\n')) != NULL)
        *str = '\0';
    else {
        fprintf(stderr, "path too long...\n");
        exit(EXIT_FAILURE);
    }

    printf("Target file path: ");
    fgets(dpath, 1024, stdin);
    if ((str = strchr(dpath, '\n')) != NULL)
        *str = '\0';
    else {
        fprintf(stderr, "path too long...\n");
        exit(EXIT_FAILURE);
    }

    if ((fs = fopen(spath, "rb")) == NULL) {
        fprintf(stderr, "cannot open file!..\n");
        exit(EXIT_FAILURE);
    }

    if ((fd = fopen(dpath, "wb")) == NULL) {
        fprintf(stderr, "cannot open file!..\n");
        exit(EXIT_FAILURE);
    }
	
    /* Copy part */

    while ((result = fread(buf, 1, BUFFER_SIZE, fs)) > 0)
        if (fwrite(buf, 1, result, fd) != result) {
            fprintf(stderr, "cannot write file!...\n");
            exit(EXIT_FAILURE);
        }

    /* Control part */    

    if (ferror(fs)) {
        fprintf(stderr, "cannot read file!..\n");
        exit(EXIT_FAILURE);
    }

    printf("file successfully copied...\n");

    fclose(fs);
    fclose(fd);
    
    return 0;
}
              
// This cycle can be exited for two reasons. 
// The first is to encounter EOF without reading any bytes, and the second is to have an IO error. 
// For this reason, it has been questioned why the fread function returns 0 at the output of the loop.

/*---------------------------------------------------------------------------------------------------------------------------------------------*/
