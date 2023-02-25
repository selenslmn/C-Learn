// The qualifiers const and volatile can be in three positions in pointers pointing to the pointer.

	const char **ppc;
	char * const *p;
	char ** const p = adres;

// The same goes for volatile.

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/
  
  // The ppi is of type "const int **". ppi denotes a const pointer.
  // The **ppi expression is of type "const int *". The *ppi expression is of type "const int". We can assign another address to the ppi. Because ppi is not const.
  // We can also assign an address to *ppi. Because the place where **ppi points, not itself, is in const state. 
  // However, we cannot assign a value to **ppi because it is const.

	int a = 10;
	int *pi;
	const int **ppi;

	ppi = &pi;		/* valid ppi is not */
	*ppi = &a;		/* valid *ppi is not const, address assigned to pi */
	**ppi = 20;		/* invalid **ppi is const */

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/

  // Here, ppi is not const, **ppi also is not const. *ppi is const.

	int a = 10;
	int *pi;
	int * const *ppi;

	ppi = &pi;		/* valid ppi is not const */
	*ppi = &a;		/* invalid */
	pi = &a;		/* valid */
	**ppi = 20;		/* valid **ppi is not const, a is changing */

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/
   
  int *pi;
  int ** const ppi = &pi;

  // Here, ppi is const. Therefore, initializing is meaningful. But *ppi and **ppi are not const. 

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/
