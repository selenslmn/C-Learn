// This preprocessor operator is used to create complex conditions for macro or symbolic constants.
// The preprocessor operator named defined returns 1 if a certain macro or symbolic constant is defined, and 0 if not.
 
// For example, if SIZE and COUNT are defined, let's say we want to export a piece of code to the compilation module:

#ifdef SIZE
		#ifdef COUNT
			...
		#endif
	#endif

// However, thanks to the defined operator, this can also be done like this:

	#if defined(SIZE) && defined(COUNT)
		....
	#endif

/*----------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

#define SIZE        10
#define COUNT       20

int main(void)
{

#if defined(SIZE) && defined(COUNT)
    printf("yes\n");
#else
    printf("no\n");
#endif

    return 0;

}

/*-------------------------------------------------------------------------------------------------------------------------------------------*/

// If a macro parameter is used in the #define command by prefixing it with # in the STR2 part, this parameter is enclosed in double quotes.

	#define NAME(name)		#name

// Here, when we use an expression like NAME(x) in the code, the preprocessor will insert "x" instead.

#include <stdio.h>

#define MSG(msg)		puts(#msg)

int main(void)
{
	MSG(this is a test);

	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------*/

// If ## is used in the STR2 part of the #define command, this operation is called "token pasting".

// Here, when we give a double-quoted text to the WSTR macro, the macro will prefix it with the letter L:

	#include <stdio.h>
	#include <wchar.h>

	#define WSTR(msg)		L##msg

	int main(void)
	{
		wprintf(L"%s\n", WSTR("test"));

		return 0;
	}

/*-----------------------------------------------------------------------------------------------------------------------------------------*/

	#include <stdio.h>

	#define UNICODE

	#ifdef UNICODE
		#define STR(str)	L##str
	#else
		#define STR(str)		str
	#endif

	#ifdef UNICODE
		#define _tprintf		wprintf
	#else
		#define _tprintf	printf
	#endif

	int main(void)
	{
		_tprintf(STR("%s\n"), STR("this is a test\n"));

		return 0;
	}

// If the programmer uses all the strings with the STR macro, it can keep her code largely compatible between UNICODE and ASCII.

/*------------------------------------------------------------------------------------------------------------------------------------------*/
