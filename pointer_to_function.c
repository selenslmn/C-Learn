// Pointers that point to the starting addresses of functions are called "function pointers".
// There are machine commands called CALL in machine language to call functions.
// These CALL instructions take the starting address of the function and cause the processor to execute instructions from that address.

CALL <adres>

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/

// Function pointers cannot represent all functions. It can represent functions with a certain form of return value and parameter types.

  int (*pf)(int, int);

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/

// Each function's address cannot be placed in a function pointer. 
// Addresses of functions whose return value and parametric structure are compatible can be placed.

	void foo(void)
	{
		/* ... */
	}

	void bar(int a)
	{
		printf("bar\n");
	}

	int tar(int a, int b)
	{
		/* .... */
	}

	int (*pf)(int, int);

	pf = foo;		/* invalid! */
	pf = bar;		/* invalid */
	pf = tar;		/* valid */

// Do not accidentally use parentheses when assigning a function pointer.

	pf = tar();		/* invalid! */ 

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/

	#include <stdio.h>
	#include <shellapi.h>

	void foo(void)
	{
		printf("foo\n");
	}


	int main(void)
	{
		void (*pf)(void);

		pf = foo;

		pf();       /* valid */
		
		return 0;
	}


/*----------------------------------------------------------------------------------------------------------------------------------------------------*/

	void foo(void)
	{
		printf("foo\n");
	}
	...
	void (*pf)(void);

	pf = foo;

	pf();   	  /* same notation, more use */
	(*pf)(); 	  /* same notation */

	// A function pointer can be give first value.

	void (*pf)(void) = foo;

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/

// calling some functions via the function pointer.

#include <stdio.h>

int add(int a, int b)
{
    return a + b;
}

int sub(int a, int b)
{
    return a - b;
}

int mul(int a, int b)
{
    return a * b;
}

int div(int a, int b)
{
    return a / b;
}

int main(void)
{
    int (*pfs[4])(int, int) = {add, sub, mul, div};
    int result;

    for (int i = 0; i < 4; ++i) {
        result = pfs[i](20, 10);
        printf("%d\n", result);
    }
      
    return 0;
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/

// Function types can also be typedef.

  typedef void (*PF)(void);

	PF pf;

	/* this statement is equivalent to the following: */

	void (*pf)(void);

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/
