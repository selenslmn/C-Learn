// It is one of the most used preprocessor commands.

// The #ifdef keyword is accompanied by a symbolic constant name, not an expression.
// If the symbolic constant is defined, the command executes the part up to #else, otherwise it returns the part between #else and #endif.

// It doesn't have to be the #else part. It doesn't matter what the symbolic constant here is defined as. 
// What matters is whether this symbolic constant is defined or not.

/*-------------------------------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>

#define MAX 

int main(void)
{
	#ifdef MAX
		printf("Yes\n");
	#else
		printf("No\n");
	#endif

	return 0;
}

// “Yes” will be displayed because there is a definition here. If it wasn't, it would print "No".

/*-------------------------------------------------------------------------------------------------------------------------------------------*/
