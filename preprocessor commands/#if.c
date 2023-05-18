// The #if command works like this: The preprocessor calculates the numeric value of the expression next to the #if command. 
// If this value is a non-zero value, the part between #if and #else is given to the compilation module, 
// and if it is 0, the part between #else and #endif is given to the build module.

#include <stdio.h>

int main(void)
{
	#if 1
		printf("Yes\n")   
	#else
		printf("No\n");
	#endif

	return 0;
}

// Don't confuse the #if command with a regular if statement. 
// In the normal if statement, both the right part and the wrong part of the if statement are in the code.

/*------------------------------------------------------------------------------------------------------------------------------------------*/

/* Sometimes it is desirable to discard some pieces of code and give some pieces of code to the build module. 
For example, let's say something has changed after 3 versions of a library. 
In this case, we may want to arrange our code to work both in versions after version 3 and in previous versions: */

#define VERSION		3.4
	...

	#if VERSION > 3
		...
	#else
		...
	#endif

	...

/*------------------------------------------------------------------------------------------------------------------------------------------*/

// Sometimes programmers prefer the #if command to remove some code from the build module instead of using a comment line:

	#if 1 				/* 0 for comment line */

	int main(vodid)
	{
		...
	}

	#endif

/*-----------------------------------------------------------------------------------------------------------------------------------------*/

// A #elif (meaning else if) part is also added for nested #ifs in the if command. Such nested #ifs are very difficult to create. 
// Instead, the same operations can be performed more easily using #elif.

// Note that each #elif part is not closed with #endif, only one #endif is used in total. 
// #elseif can also be used #else at the end of the ladder:

	#if VERSION == 1
		....
	#elif VERSION == 2
		...
	#elif VERSION == 3
		...
	#else
		....
	#endif

/*-----------------------------------------------------------------------------------------------------------------------------------------*/
