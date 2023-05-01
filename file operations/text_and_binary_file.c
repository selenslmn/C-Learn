/*
According to the operating system, the file consists of bytes.

In C, files are divided into two as "text" and "binary" to make things a little easier. 
A file containing only text is a text file. However, there is no text in the ".obj", ".exe" files that we obtained as a result of the compilation and linking process. 
These files are binary files. For example, "jpeg" files, "bmp" files are binary files. 
But "html" files are text files. If we can see meaningful things when we pull a file into the editor, it is a text file.
For example, if we want to view an exe file with a text editor, this text editor will show us the bytes of machine codes as characters, 
and as a result, strange characters will be displayed. At the operating system level, there is no such distinction as a text file binary file.
*/

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/

/*
To display a character at the beginning of the down line in a text UNIX/Linux and macOS systems use the '\n' character (LF (Line Feed - 0A)), 
'\r' (Carriage Return (CR) - 0D) and '\n' on Windows systems.

In order to facilitate operations with text files in C, file opening modes are divided into two as "text mode" and "binary mode". 
The default boot mode is text mode. For opening in binary mode, the letter "b" is added to the end of the opening mode. 
For example "r" stands for text mod. But "rb" stands for binary mode.

	Text mode				Binary Mode

	"r"					      "rb"
	"w"					      "wb"
	"r+"					    "r+b"
	"w+"					    "w+b"
	"a"					      "ab"
	"a+"					    "a+b"

*/

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/

/*
What is the difference between opening the file in text mode and binary mode?

1) If we open a file in "text" mode on Windows systems, when we write the '\n' character in that file, the characters \r\n will actually be written to the file. 
However, if we open the file in binary mode, the '\n' character will be printed for the '\n' character. 
There will be no difference between "text mode" and "binary mode" on UNIX/Linux and macOS systems. 
However, for portability, the programmer must open non-text files in binary mode.

2) If the file is opened in text mode; On Windows it reads CR/LF but returns the LF (\n) character as a result of the reading. 
In UNIX/Linux and macOS systems, when a byte is read from the file, the CR (\r) character will be given. 
Then, when a byte will be read again, this time LF (\n) character will be given.
If opened in binary mode; In Windows, the CR character is read. In UNIX/Linux and macOS systems, nothing changes in the reading process in binary mode or text mode.

Note: If you are going to open a file for text purposes, you should open it in text mode. 
However, if you are going to operate on a non-text file, you should open the file in binary mode.
*/

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/

// Opening the file in text mode:

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *f;

    if ((f = fopen("test.txt", "w")) == NULL) {
        fprintf(stderr, "cannot open file!..\n");
        exit(EXIT_FAILURE);
    }

    fputc('a', f); 		  /* 61 */
    fputc('\n', f); 		/* 0D 0A */
    fputc('b', f); 		  /* 62 */

    fclose(f);

    return 0;
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/

// Opening the file in binary mode:

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *f;

    if ((f = fopen("test.txt", "wb")) == NULL) {
        fprintf(stderr, "cannot open file!..\n");
        exit(EXIT_FAILURE);
    }

    fputc('a', f); 		  /* 61 */
    fputc('\n', f); 		/* 0A */
    fputc('b', f); 		  /* 62 */

    fclose(f);

    return 0;
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/

/*
It is assumed that the stdout file representing the screen and the stdin file representing the keyboard are opened in "text mode".
In this case, we only need to send the LF character to the screen in order to move the cursor to the beginning of the down line in Windows.
The display will move the cursor to the beginning of the down line using the CR/LF characters. We should not use CR/LF.
*/

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/

/*
There is no problem in reading and printing a text file created in Windows on UNIX/Linux and macOS systems.
Because when reading the CR/LF pair, it will be read as two separate characters in UNIX/Linux and macOS systems.
In these systems, there will be no problem as the CR character "puts the cursor to the beginning of the current line" and 
the LF immediately after it "puts it to the beginning of the lower line".
However, the text file will take up more space.
*/

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/
