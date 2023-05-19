// There is a set of "predefined" macros in the C standards. These predefined macros are not defined anywhere. 
// No header files need to be included to use them. The important ones are:

/*------------------------------------------------------------------------------------------------------------------------------------------*/

__FILE__: When the preprocessor sees this macro, it places the name of the file in double quotes at the location of the macro.

#include <stdio.h>

int main(void)
{
	char fname[] = __FILE__;
	printf("%s\n", fname);
	return 0;
}

// Whether the filename is just a name or a path expression may vary from compiler to compiler.

/*-----------------------------------------------------------------------------------------------------------------------------------------*/

__LINE__: When the preprocessor sees this macro, 
it places the number of the line where the macro is located as an int constant at the location of the macro.


	#include <stdio.h>

	int main(void)
	{
		printf("%d\n", __LINE__);
		printf("%d\n", __LINE__);

		return 0;
	}

// Thus, we can obtain the line number of a certain line of the file from within the program.

/*------------------------------------------------------------------------------------------------------------------------------------------*/

__DATE__ ve __TIME__: When the preprocessor sees these macros, it places the current date and time information in double quotes.

	#include <stdio.h>

	int main(void)
	{
		printf("%s\n", __DATE__);
		printf("%s\n", __TIME__);

		return 0;
	} 

/*------------------------------------------------------------------------------------------------------------------------------------------*/

__cplusplus: If this macro is compiled in C, it is not defined, if it is done in C++, it is defined as defined. 
  So programmers can use this macro to fix incompatibilities of the two languages if C code is compiled by C++ compilers.

// For example, "restrict pointers" were added to C with C99. However, C++ does not support this feature. 
// In this case, we can make a prototype C++ compatible like this:
    
	#ifdef __cplusplus
	void foo(void * p);
	#else
	void foo(void * restrict p);
	#endif 

/*------------------------------------------------------------------------------------------------------------------------------------------*/

__STDC_VERSION__: When the preprocessor sees this macro, it inserts a long constant in the form of 201ymmL. 
  In this way, we can understand which version of C we are running during compilation.  

/*------------------------------------------------------------------------------------------------------------------------------------------*/

__GNUC__ : gcc compilers assume this macro is defined. So we can include some gcc compiler-specific operations in the code during compilation.

#include <stdio.h>

	int main(void)
	{
	#ifdef __GNUC__
		printf("gcc\n");
	#else
		printf("not gcc\n");
	#endif

		return 0;
	}

/*----------------------------------------------------------------------------------------------------------------------------------------*/

__unix__ : Since C compilers on UNIX/Linux systems are not standard, 
we can include and exclude UNIX/Linux-specific operations in our code during compilation with this command.

// The _WIN32 macro for 32-bit Windows systems and the _WIN64 macro for 64-bit Windows systems are defined as defined in Microsoft C compilers.

	#include <stdio.h>
	#include <stdlib.h>

	#if defined(__unix__)
	#include <sys/stat.h>
	#elif defined(_WIN32) || defined(_WIN64)
	#include <windows.h>
	#endif

	#define DIR_NAME       "xxx"

	int main(void)
	{
	#if defined(__unix__)
		if (mkdir(DIR_NAME, 0777) == -1) {
			fprintf(stderr, "cannot create directory!..\n");
			exit(EXIT_FAILURE);
		}
	#elif defined(_WIN32) || defined(_WIN64)
		if (!CreateDirectory(DIR_NAME, NULL)) {
			fprintf(stderr, "cannot create directory!..\n");
			exit(EXIT_FAILURE);
		}
	#else
		#error operating system not supported
	#endif

		return 0;
	}

// Directory creation is done with different functions in UNIX/Linux systems and Windows systems. 
// Therefore, an attempt was made to create a directory by calling the function on the system in which the code is currently working.

/*------------------------------------------------------------------------------------------------------------------------------------------*/

// The #error preprocessor command currently interrupts the compilation process with a fatal error message.
// Usage of the command for UNIX/Linux systems:

	#ifndef __unix__
		#error operatating system is not UNIX/linux
	#endif


// Note that the text of the message is not in double quotes.

/*-----------------------------------------------------------------------------------------------------------------------------------------*/
