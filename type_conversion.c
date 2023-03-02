// In C program we can assign any type of data address to void pointer. But we cannot assign function address.

	int add(int a, int b)
	{
		return a + b;
	}
	void (*pf)(void);

	pf = add;					            /* invalid! */

	pf = (void (*)(void))add;		  /* valid */

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/

// A pointer of any type at a void address cannot be assigned, even if the type conversion operator is applied.
// However, a function address can be converted to another function address by type conversion.

	void foo()
	{
		...
	}
	
	void *pv;

	pv = foo;		  /* invalid /*

	pv = &foo;		/* valid, because &foo is void (**)(void) type. This type is a data pointer. */

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/

// In a function pointer, leaving the parameter brackets blank and writing void there have different meanings.
// Writing void inside the parameter parenthesis means that the parameter of the function address to be assigned to it must be void.

  void foo(void)
	{
		...
	}

	void bar(int a)
	{
		...
	}

	int tar(int a)
	{
		...
	}

	void (*pf)(void);

	pf = foo;		          /* valid */
	pf = bar;		          /* invalid! */
	pf = tar;		          /* invalid! */

	/* But for example: */

	void (*pf)();

	pf = foo;	          	/* valid */
	pf = bar;		          /* valid */
	pf = tar;		          /* invalid! */

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/
