// In operating systems, the screen and keyboard are managed by a "device driver". Device drivers are treated like files.
// Device drivers that control the screen and keyboard are called "terminal device drivers". 
// In C, the variables "stdout" and "stdin" specify a file information pointer of type FILE *. Both variables are declared in <stdio.h>.

// A computer system doesn't have to have a screen and keyboard. 
// In classical computer systems, stdout represents the screen, and stdin represents the keyboard by default.

// Stdout can be a display device driver on the system, or it can be a device driver for another device. 
// As a file, stdout can also represent a regular disk file. The situation is also valid for the stdin file.

// The stdin, stdout and stderr files are considered to be opened automatically when the program starts running. 
// They aren't opened and closed by the programmer, they can be used directly.

// It is assumed that stdin file is opened in "read only text mode", and stdout and stderr files are opened in "write only text mode". 
// So we can't write to stdin file and we can't read from the stdout and stderr files.

/*----------------------------------------------------------------------------------------------------------------------------------------------*/

// The stdin, stdout, and stderr files can be redirected to other devices and other files on disk. This topic is called "IO".

// In Windows, UNIX/Linux and macOS systems, IO routing is done with ">" and "<" symbols. 
// The ">" symbol is used to redirect the stdout file, and the "<" symbol is used to redirect the stdin file.

	#include <stdio.h>

	int main(void)
	{
		for (int i = 0; i < 10; ++i)
			printf("%d\n", i);

		return 0;
	}

// This program prints numbers 1 to 10 to stdout file. When this program is run, what is written will appear on the screen.

// With the > symbol on the command line, we can redirect the stdout file to a disk file.

  ./sample > test.txt

// Now the things to be written to the screen will be written into the "test.txt" file.

  ./sample < x.txt

// Here, what will be read from the stdin file will be read from the x.txt file.

/*----------------------------------------------------------------------------------------------------------------------------------------------*/

// How is the EOF effect achieved on the keyboard?
// In UNIX/Linux systems, pressing the Ctrl+d keys on the keyboard creates the effect of encountering EOF in the stdin file.
// On Windows systems, this effect is made with the Ctrl+z key.
// When we press these special keys, we do not close the file related to the keyboard. That one-time EOF effect is created.

#include <stdio.h>

	int main(void)
	{
		double val;

		for (;;) {
			if (scanf("%lf", &val) == EOF)
				break;
            
			printf("%f\n", val * val);
		}

			return 0;
		}
	}

// Here, when scanf encounters EOF, it returns EOF value. We are out of the loop. 
// While running this program, Ctrl+d or Ctrl+z keys are used to create the EOF effect. 
// If we run this program as follows, the program will read from the "x.txt" file instead of reading from the keyboard:

    ./sample < x.txt

// The stdin file and the stdout file can be redirected together:

    ./sample < x.txt > y.txt

/*----------------------------------------------------------------------------------------------------------------------------------------------*/

// What is stderr file?

// stderr file is intended for printing error messages.
// By default in operating systems, what is written to the stderr file will be displayed.

	#include <stdio.h>

	int main(void)
	{
		printf("stdout\n");
		fprintf(stderr, "stderr\n");

		return 0;
	}

//	Both texts will appear on the screen. 

/*----------------------------------------------------------------------------------------------------------------------------------------------*/

// What is the need for stderr file?

// By default, stdout and stderr cause text to appear on the screen, but the targets of these two files can be changed with IO redirection.
 
// For example, let's rewrite the above program. Now let's run the program like this:

    ./sample > x.txt

// Here we will only see "stderr" on the screen. Because the > symbol only redirects the stdout file.
// If the stderr file is to be redirected, then the 2> symbol must be used.

    ./sample 2> x.txt

// Here, too, we will only see "stdout" on the screen. Because in this example we only redirected the stderr file.

/* So if the programmer writes the error messages to the stderr file, 
the user can distinguish between the normal messages of the program and the error messages. */

/*---------------------------------------------------------------------------------------------------------------------------------------------*/

// We should print the error messages not to stdout with printf, but to stderr with the fprintf function:

	char *str;
	if ((s = (char *)malloc(1024)) == NULL) {
            fprintf(stderr, "cannot allocate memory!..\n");
            exit(EXIT_FAILURE);
        }

/*---------------------------------------------------------------------------------------------------------------------------------------------*/
