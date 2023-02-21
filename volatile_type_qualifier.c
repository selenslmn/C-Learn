  volatile int *pi;					        /* volatile where it points, not itself */
	int * volatile pi;					      /* itself volatile, not where it points */
	volatile int * volatile pi;			  /* both itself and where it points are volatile */

/*-----------------------------------------------------------------------------------------------------------------------------------*/

  int a = 10, b;
	volatile int *pi = &a;          /* The compiler will access the location pi points to again and again. */
	...

	a = *pi + 10;
	b = *pi + 20;

/*-----------------------------------------------------------------------------------------------------------------------------------*/

  int a;
	volatile int b;
	int *pi1;
	volatile int *pi2;

	pi1 = &b;		  /* invalid, There is no automatic conversion. */
	pi2 = &b;		  /* valid */
	pi2 = &a;		  /* valid, It has automatic conversion. */

/*-----------------------------------------------------------------------------------------------------------------------------------*/

// The const and volatile type qualifiers can also be used together. It does not matter which one is written first in the notification.

  const volatile int *pi;
	const volatile int x = 10;

	const int * const volatile pi = &a;

/*-----------------------------------------------------------------------------------------------------------------------------------*/
