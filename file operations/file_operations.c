/*

/a/b/c.text			On UNIX/Linux and macOS systems (but Windows systems also support)
\a\b\c.text			On Windows systems, but UNIX/Linux and macOS systems do not support

*/

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/

// Path expressions are divided into two as "absolute" and "relative". 
// If the first character of the path expression is "/" on UNIX/Linux systems and "\" on Windows systems, path expressions are "absolute":

/*

	/a.txt
	/a/b/c.txt
	\windows\notepad.exe

*/

// Absolute path expressions always refer to the root directory.

/*

	/usr/include/stdio.h

*/

//	If the first characters of path expressions aren't "/" on UNIX/Linux and macOS systems, and "\" on Windows systems, path expressions are relative path expressions.

/*

	a/b/c.txt
	temp\test.txt
	test.txt

*/

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/

// In operating systems, the working directories of each currently running process can be different from each other.
// The program that a program runs is called a "child process", and the program that runs it is called a "parent process". 
// In general, in most operating systems, the working directory of the parent process is transferred to the child process.

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/

// The characters that can be used in file and directory naming may differ in Windows, UNIX/Linux and macOS systems. 
// One of the key differences between Windows and others is that in the Windows, file and directory names are not case sensitive.

/*

test.text
Test.txt

*/

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/

// File operations in C start with the letter "f" in <stdio.h>: fopen, fclose, fread, fwrite, fgetc, ... 

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/

// "r"		Opens the current file, reads only.
// "r+"		Opens the current file, both reads and writes. 
// "w"		If the file doesn't exist, it creates and opens it, if the file exists, it truncates and opens it, only writes can be made.
// "w+"		If the file doesn't exist, it creates and opens it, if the file exists, it truncates and opens it, both reads and writes can be made.
// "a"		If the file exists, it opens, if not, it creates and opens, only writing. Each post is appended to the end. (Can't be overwritten except at the end of the file)
// "a+" 	If the file exists, it opens, if not, it creates and opens, both reading and writing. Each post is appended to the end. However, it can be read from anywhere.

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/

// In operating systems, each process has a maximum number of files that it can open. 
// In other words, we may not be able to open every file we want in every mode we want. 
// The programmer must check the success of the fopen function.

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/

// A file was wanted to be opened in "r" mode:

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *f;

    if ((f = fopen("test.txt", "r")) == NULL) {
        fprintf(stderr, "cannot open file!..\n");
        exit(EXIT_FAILURE);
    }

    printf("Ok\n");

    return 0;
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/

// When the programmer is finished with a file, he/she should close the file. Not necessary but good technique.
// The "fclose" function is used to close the file. "fclose" returns 0 if the file was successfully closed.
// If the file was not closed successfully, fclose returns the EOF value defined in <stdio.h>.
// C standards do not specify the symbolic constant EOF, but specify that it should be defined as a negative int constant expression.


#define EOF		(-1)

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *f;

    if ((f = fopen("test.txt", "r")) == NULL) {
        fprintf(stderr, "cannot open file!..\n");
        exit(EXIT_FAILURE);
    }

    printf("Ok\n");

    fclose(f);

    return 0;
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/
