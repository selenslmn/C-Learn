// The scanf function reads from the stdin file (keyboard). fscanf reads from any file.

// These functions return the number of parts that can be read on success. 
// If the functions encounter EOF without any reading, they return to the EOF value.

/*	In the example below, the contents of the "test.txt" file are:

	10 20

Reading from this file with fscanf: */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *f;
    int a, b;

    if ((f = fopen("test.txt", "r")) == NULL) {
        fprintf(stderr, "cannot open file!..\n");
        exit(EXIT_FAILURE);
    }

    fscanf(f, "%d%d", &a, &b);

    printf("a = %d, b = %d\n", a, b);

    fclose(f);

    return 0;
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/

// These functions proceed by reading characters one by one. 
// If it encounters a character that does not match the format character, it terminates the operation and returns to the number of successfully placed objects. 

	#include <stdio.h>

	int main(void)
	{
		int a = -1, b = -1;
		int result;

		result = scanf("%d%d", &a, &b);

		printf("a = %d, b = %d\n", a, b);
		printf("result = %d\n", result);

		return 0;
	}

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/

	/* Let's make the following entry from the keyboard:

	      10     20

	  scanf ignores whitespace characters between entries. Therefore, since it has successfully made two placements here, scanf will return with the value of 2.
	
  */

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/

/*

Let's make the following entry from the keyboard:

  10 matt

scanf does the reading for a but fails to read for b and terminates its process. It returns a value of 1.

*/

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/

/*

Let's make the following entry from the keyboard:

  matt david

	scanf fails to read for a and terminates its process. It returns a value of 0.
 
*/

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/

/*

Let's make the following entry from the keyboard:

  10arizona stonehenge

Here scanf places the value 10 in a and returns a value of 1. */

*/

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/
