// Double-star void pointers are different from one-star void pointers. One-star void pointers can be directly assigned the address of any object. 
// However, we cannot do this with a two-star void pointer. Only the address of a void pointer can be assigned.

	char *names[] = {"ali", "veli", "selami"};
	void *pv;
	void **ppv;

	pv = names;		/* valid */
	ppv = names;	/* invalid! */	
	ppv = &pv;		/* valid */

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/

	void foo(int pi[])
	{
		/* ... */
	}

	// This definition is completely equivalent to the following.

	void foo(int *pi)
	{
		/* ... */
	}

	// Again, a definition such as the following is completely equivalent to the above.

	void foo(int pi[100])
	{
		/* ... */
	}

	// A value of 100 doesn't matter. The parameter of the function is actually a pointer of type int. 

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/

	void foo(char *argv[])
	{
		/* ... */
	}

	// This definition is completely equivalent to the following.

	void foo(char **argv)
	{
		/* ... */
	}

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/
