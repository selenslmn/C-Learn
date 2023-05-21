/* Writing functions in macro form is problematic. Because:

- Macro writing is difficult and complicates readability.

- Care must be taken to avoid undefined behavior when calling macros.

- It is difficult to create blocky transactions within macros.

That's why "inline functions" were considered as a better alternative to macros. */

/*------------------------------------------------------------------------------------------------------------------------------------------*/

/* 

Making a function inline can take 3 forms in C:

	inline
	static inline (or inline static)
	extern inline (or inline extern)

*/

/*-----------------------------------------------------------------------------------------------------------------------------------------*/

/*

When we make a function inline, the compiler may not open that function inline, so it is not mandatory. Why?

- Inline expansions of recursive functions are not possible.
- Functions with complex statements (such as nested if statements) may not be opened inline.
- It is not appropriate to open inline codes that take a long time to run.
- If the address of the function is taken and used in the code, the compiler may not want to open the function inline.
- If the function consists of too many lines, the inline expansion will greatly enlarge the code.

"funtions with simple, a few lines, not containing statements such as long loops and complex if statements" are candidates for opening inline.

*/

/*-------------------------------------------------------------------------------------------------------------------------------------------*/

//	The differences between the three inline functions are:

//	1) inline: It's fine if the compiler decompresses inline, but if it doesn't, it places the CALL machine command.
               If there is no this function in another module, an error occurs at the link stage. 

//   For example:

	/* sample.c  */

	#include <stdio.h>

	inline int square(int a)
	{
		return a * a;
	}

	int main(void)
	{
		int result;

		result = square(3);

		printf("%d\n", result);

		return 0;
	}

// For example, let's compile the function in the gcc compiler without turning on the optimization options as follows:

	gcc -o sample sample.c

// In this case, we get an error at the link stage.

// However, if we use the program with the optimization option, an error will not occur:

	gcc -O2 -o sample sample.c

// Because at least the /O2 optimization option for Microsoft compilers to decompress inline,
The gcc and clang compilers also require at least the -O2 option.

// The compiler does not write the function code to the objective code, whether it does inline or not.

//	2) static inline: The problem does not occur whether the compiler does inline or not. However, if it cannot open the function inline, 
                      it writes the object to the file with a static linkage and calls the function with the CALL machine command.

// For example:

	static inline int square(int a)
	{
		return a a a;
	} 

// static inline functions are the most used inline functions in C. 
// The most important disadvantage is that if the same static inline function is used in more than one module and inline opening cannot be made,
the codes of these functions must be present in these modules separately. 

//	3) extern inline: If the compiler opens inline, it's fine. If it cannot, it uses the CALL machine command.
                      However, the compiler always writes the function to the target file with an extern linkage.
                      Therefore, if this function is used in more than one module, an error will occur. 
  
  // A normal function is already in extern format. That is, it makes no difference whether extern is brought before its definition.

	extern void foo(void)
	{
		...
	}

	// The extern specifier is used redundantly here. Functions already have default external linkage.
    
	extern inline int square(int a)
	{
		return a * a;
	}

	// Here the function is defined as external inline. 

/*-------------------------------------------------------------------------------------------------------------------------------------------*/

// How should the programmer proceed here? 

// If the inline function cannot be opened inline by the compiler and if dont want any trouble, it should prefer the static inline definition.

/*-------------------------------------------------------------------------------------------------------------------------------------------*/

// inline functions must be seen by the compiler at every compilation process. Therefore, these functions cannot be placed in libraries.
// When working with multiple modules we can put inline functions in a common header file. For example:

	/* project.h */

	#ifndef PROJECT_H_
	#define PROJECT_H_

	static inline foo()
	{
		...
	}

	#endif

	/* sample.c */

	#include <stdio.h>
	#include "project.h"
	...

	/* mample.c */

	#include <stdio.h>
	#include "project.h"
	...

/*------------------------------------------------------------------------------------------------------------------------------------------*/
