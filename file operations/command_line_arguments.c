// The arguments entered when running a program from the command line are called the "command line arguments" of the program. 

	./sample christopher david matt peter

// Here "christopher david matt peter" are the command line arguments of the sample program we are running.
// Without command line arguments, we wouldn't be able to run many programs to do what we want.

/*----------------------------------------------------------------------------------------------------------------------------------------*/

// Standartlara göre main fonksiyonu iki parametreli yapıya sahip olabilmektedir: “int main(void)” or “int main(int argc, char *argv[])”

// However, the standards state that the main function can have other parameters, specific to that compiler and operating system.
// However, these two parametric structures are used for portability.

	int main(int argc, char *argv[])
	{
		...
	}

// The names of the parameter variables do not have to be argc and argv. But traditionally programmers use these names. 

// The second parameter of the main function is the pointer to the pointer. So the above is exactly equivalent to the following:

	int main(int argc, char **argv)
	{
		...
	} 

/* The name "argc" comes from "argument counter",
the name "argv" comes from "argument vector" (here "vector" is used to mean array) or "argument variable list". */

/*----------------------------------------------------------------------------------------------------------------------------------------*/

// What do argc and argv mean?

	./sample christopher david matt peter

// Here, the number of texts separated by spaces, including the program name, is passed to the argc parameter.
// So in our example, argc will take the value 5.
// argv is a pointer to a pointer. That is, it represents an array of pointers. 
// Here this pointer array shows command line arguments including program name.
// There is also a null character at the end of each command line argument.

The content of the argv array will be:

	argv ---> [0] ---> ./sample\0
	          [1] ---> christopher\0
		        [2] ---> david\0
		        [3] ---> matt\0
		        [4] ---> peter\0
            [5] NULL

// For example:

	#include <stdio.h>

	int main(int argc, char *argv[])
	{
		printf("%d\n", argc);

		for (int i = 0; i < argc; ++i)
			puts(argv[i]);
    
		return 0;
	}

// Let's run the program on UNIX/Linux systems:

	./sample christopher david matt peter

	5
	./sample
	christopher 
  david 
  matt 
  peter
		
/*----------------------------------------------------------------------------------------------------------------------------------------*/

  ./sample 10 20

	3
	./sample
	10
	20
	
/*----------------------------------------------------------------------------------------------------------------------------------------*/

  ./sample

	1
	./sample

/*----------------------------------------------------------------------------------------------------------------------------------------*/

  ./sample ankara izmir

	3
	./sample
	ankara
	izmir
	
// Since the name of the program is also included in the command line arguments. So argc can never be 0. It has to be at least 1.

/*---------------------------------------------------------------------------------------------------------------------------------------------*/
	
// It is the programmer's job to take command line arguments from argc and argv parameters and use them.
// The operating system simply passes these arguments to the main function.
// If the programmer voids the parameter of the main function, it will not cause a problem, but he cannot use these arguments.

	#include <stdio.h>

	int main(int a, char **b)
	{
		printf("%d\n", a);

		for (int i = 0; i < a; ++i)
			puts(b[i]);

		return 0;
	}

/*---------------------------------------------------------------------------------------------------------------------------------------------*/

// In the example below, the sum of the values received from the command line is printed on the screen. 

// Suppose the program name is "sample":

	./sample 10 20 30
	60.000000

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    double total;

    if (argc < 2) {
        fprintf(stderr, "wrong number of arguments!..\n");
        exit(EXIT_FAILURE);
    }

    total = 0;
    for (int i = 1; i < argc; ++i)
        total += atof(argv[i]);

    printf("%f\n", total);
  
    return 0;
}

/*----------------------------------------------------------------------------------------------------------------------------------------------*/

// Example that prints the contents of the file specified with the path expression taken in the form of a command line argument: 

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *f;
    int ch;

    if (argc != 2) {
        fprintf(stderr, "wronh number of arguments!..\n");
        exit(EXIT_FAILURE);
    }

    if ((f = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "cannot open file: %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((ch = fgetc(f)) != EOF)
        putchar(ch);

    if (ferror(f)) {
        fprintf(stderr, "cannot read file!..\n");
        exit(EXIT_FAILURE);
    }

    fclose(f);
  
    return 0;
}

/*--------------------------------------------------------------------------------------------------------------------------------------------*/

/* Even if a program does not use command-line arguments (for example, even if the parameter of the main function is void), 
giving a command-line argument during program execution is generally not a problem. */

/*------------------------------------------------------------------------------------------------------------------------------------------*/
