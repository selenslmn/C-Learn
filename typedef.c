// In C, giving a type an alternative name that can completely replace it is called a "typedef declaration". 
// The typedef keyword is in the "storage class specifier" group in C. 
// Each declaration can be preceded by a typedef.


#include <stdio.h>

	typedef char *STR;

	int main(void)
	{
		STR s = "ankara";		/* char *s = "ankara"; */

		printf("%s\n", s);		/* ankara */

		return 0;
	}

/*-------------------------------------------------------------------------------------*/

// A typedef does not create a definition, it is a declaration operation. 
// That is, the compiler gets information when it sees the typedef declaration. 
// It doesn't take a place.

#include <stdio.h>

	typedef int I, *PI;

	int main(void)
	{
		I a = 10;			/* int a = 10; */
		PI pi;				/* int *pi; */

		pi = &a;

		printf("%d\n", *pi);
	
		return 0;
	}

/*-----------------------------------------------------------------------*/

#include <stdio.h>

	typedef int A[5];

	int main(void)
	{
		A a = {1, 2, 3, 4, 5};			
		
    for (int i = 0; i < 5; ++i)
        printf("%d ", a[i]);
    pritnf("\n");                         /* 1 2 3 4 5 */
    
    return 0;
  }
